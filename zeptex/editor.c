#include "editor.h"

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <errno.h>

#define MAX_LINES 1000
#define MAX_LINE_LEN 1024

char *lines[MAX_LINES];
size_t line_count = 0;
size_t scroll_offset = 0;

struct termios orig_termios;

volatile sig_atomic_t resize_flag = 0;  // flag set by SIGWINCH handler

// ========== RAW MODE ==========

void disable_raw_mode() {
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enable_raw_mode() {
    tcgetattr(STDIN_FILENO, &orig_termios);
    atexit(disable_raw_mode);

    struct termios raw = orig_termios;
    raw.c_lflag &= ~(ECHO | ICANON);
    raw.c_cc[VMIN] = 1;
    raw.c_cc[VTIME] = 0;

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

// ========== SIGNAL HANDLER ==========

void handle_resize(int sig) {
    (void)sig; // unused parameter
    resize_flag = 1;
}

void setup_sigwinch_handler() {
    struct sigaction sa;
    sa.sa_handler = handle_resize;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0; // no SA_RESTART so read() is interrupted

    if (sigaction(SIGWINCH, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }
}

// ========== FILE OPS ==========

void load_file(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) return;

    char buf[MAX_LINE_LEN];
    while (fgets(buf, sizeof(buf), f)) {
        if (line_count >= MAX_LINES) break;
        buf[strcspn(buf, "\n")] = 0;
        lines[line_count++] = strdup(buf);
    }
    fclose(f);
}

void save_file(const char *filename) {
    FILE *f = fopen(filename, "w");
    if (!f) return;

    for (size_t i = 0; i < line_count; ++i)
        fprintf(f, "%s\n", lines[i]);
    fclose(f);
}

// ========== BUFFER OPS ==========

void insert_line(size_t index, const char *text) {
    if (line_count >= MAX_LINES || index == 0 || index > line_count + 1) return;
    for (size_t i = line_count; i >= index; --i)
        lines[i] = lines[i - 1];
    lines[index - 1] = strdup(text);
    line_count++;
}

void delete_line(size_t index) {
    if (index == 0 || index > line_count) return;
    free(lines[index - 1]);
    for (size_t i = index - 1; i < line_count - 1; ++i)
        lines[i] = lines[i + 1];
    line_count--;
    if (scroll_offset > 0 && scroll_offset >= line_count)
        scroll_offset = line_count ? line_count - 1 : 0;
}

// ========== DISPLAY ==========

void draw_command_bar() {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    int width = w.ws_col;

    const char *title = "ZEPTEX EDITOR version 1.0";

    const char *cmds[] = { title , "i N TEXT -- insert line|", "d N -- delete line|", "↑/↓ scroll|", "w <filename> -- save|", "q -- Quit|" };
    int cmd_count = sizeof(cmds) / sizeof(cmds[0]);

    int total_cmd_len = 0;
    for (int i = 0; i < cmd_count; i++)
        total_cmd_len += strlen(cmds[i]);

    int total_spaces = width - total_cmd_len;
    int gap = total_spaces > 0 ? total_spaces / (cmd_count - 1) : 1;

    printf("\n");
    for (int i = 0; i < cmd_count; i++) {
        printf("\033[1;97m%s\033[0m", cmds[i]);
        if (i < cmd_count - 1)
            printf("%*s", gap, "");
    }
    printf("\n");
}

void draw_buffer() {
    // Clear screen and move cursor to top-left corner
    printf("\033[H\033[J");

    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    const char *title = "ZEPTEX EDITOR version 1.0 ";
    int padding = (w.ws_col - (int)strlen(title)) / 2;
    if (padding < 0) padding = 0;

    // // Print header line (fixed top)
    // printf("%*s\033[1;97m%s\033[0m\n\n", padding > 0 ? padding : 0, "", title);

    // Calculate how many lines fit below header and above command bar
    // Header = 2 lines (title + blank), Command bar = 1 line, so:
    size_t usable_rows = (w.ws_row > 3) ? (w.ws_row - 3) : 1;

    // Clamp scroll_offset to valid range (cannot scroll beyond start or end)
    size_t max_scroll = (line_count > usable_rows) ? (line_count - usable_rows) : 0;
    if (scroll_offset > max_scroll) scroll_offset = max_scroll;

    // Draw visible text lines
    for (size_t i = 0; i < usable_rows; ++i) {
        size_t line_index = i + scroll_offset;
        if (line_index < line_count) {
            printf("%3zu | %s\n", line_index + 1, lines[line_index]);
        } else {
            // Empty line if no content (prevents leftover text artifacts)
            printf("~\n");
        }
    }

    // printf("%*s\033[1;97m%s\033[0m\n\n", padding > 0 ? padding : 0, "", title);
    // printf("\033[1;97m%s\033[0m\n\n", title);


    // Draw command bar at bottom line (fixed)
    draw_command_bar();

    // Flush output immediately
    fflush(stdout);
}




// ========== MAIN LOOP ==========
void run_editor(const char *filename) {
    char cmd[MAX_LINE_LEN] = {0};
    size_t cmd_len = 0;

    // Draw initial screen and prompt
    draw_buffer();
    printf(": ");
    fflush(stdout);
    
    while (1) {
        if (resize_flag) {
            draw_buffer();
            printf(": %s", cmd);
            fflush(stdout);
            resize_flag = 0;
        }

        char c;
        ssize_t n = read(STDIN_FILENO, &c, 1);
        if (n == -1) {
            if (errno == EINTR) {
                if (resize_flag) {
                    draw_buffer();
                    printf(": %s", cmd);
                    fflush(stdout);
                    resize_flag = 0;
                }
                continue;
            }
            continue;
        }
        if (n == 0) continue;

        if (c == '\r' || c == '\n') {
            cmd[cmd_len] = '\0';

            if (strcmp(cmd, "q") == 0) break;
            else if (cmd[0] == 'i') {
                int line_no;
                char text[MAX_LINE_LEN];
                if (sscanf(cmd, "i %d %[^\n]", &line_no, text) == 2) {
                    insert_line((size_t)line_no, text);

                    struct winsize w;
                    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
                    size_t screen_lines = (w.ws_row > 3) ? (w.ws_row - 3) : 1;

                    // Auto-scroll if inserted line is below visible area
                    if ((size_t)line_no > scroll_offset + screen_lines)
                        scroll_offset = (size_t)line_no - screen_lines;

                    // Clamp scroll_offset
                    size_t max_scroll = (line_count > screen_lines) ? (line_count - screen_lines) : 0;
                    if (scroll_offset > max_scroll) scroll_offset = max_scroll;
                }
            } else if (cmd[0] == 'd') {
                int line_no;
                if (sscanf(cmd, "d %d", &line_no) == 1)
                    delete_line((size_t)line_no);
            } else if (cmd[0] == 'w') {
                char fname[256];
                if (sscanf(cmd, "w %255s", fname) == 1)
                    save_file(fname);
                else if (filename)
                    save_file(filename);
            }

            cmd_len = 0;
            cmd[0] = '\0';
            draw_buffer();
            printf(": ");
            fflush(stdout);
            continue;
        } else if (c == 127 || c == '\b') {  // Backspace
            if (cmd_len > 0) cmd[--cmd_len] = '\0';
        } else if (c == '\033') {
            char seq[2];
            if (read(STDIN_FILENO, &seq[0], 1) != 1) continue;
            if (read(STDIN_FILENO, &seq[1], 1) != 1) continue;

            if (seq[0] == '[') {
                struct winsize w;
                ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
                size_t screen_lines = (w.ws_row > 3) ? (w.ws_row - 3) : 1;
                size_t max_scroll = (line_count > screen_lines) ? (line_count - screen_lines) : 0;

                if (seq[1] == 'A') {  // Up arrow
                    if (scroll_offset > 0) scroll_offset--;
                } else if (seq[1] == 'B') {  // Down arrow
                    if (scroll_offset < max_scroll) scroll_offset++;
                }
            }
        } else if (cmd_len < MAX_LINE_LEN - 1 && c >= 32 && c < 127) {
            cmd[cmd_len++] = c;
            cmd[cmd_len] = '\0';
        }

        draw_buffer();
        printf(": %s", cmd);
        fflush(stdout);
    }
}

// ========== MAIN ==========

int main(int argc, char **argv) {
    const char *filename = NULL;
    if (argc > 1) filename = argv[1];

    // Alt screen & cursor off
    printf("\033[?1049h\033[?25l");

    enable_raw_mode();

    setup_sigwinch_handler();

    if (filename) load_file(filename);

    run_editor(filename);

    disable_raw_mode();

    // Restore screen
    printf("\033[?1049l\033[?25h");

    for (size_t i = 0; i < line_count; ++i) free(lines[i]);

    return 0;
}
