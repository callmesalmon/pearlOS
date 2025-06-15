/*
* Copyright (c) Salmon 2025 under the ANTIFA-MIT license.
* If your copy of this program doesn't include the license, it is
* available to read at: 
*
*     https://github.com/jamiebuilds/anti-fascist-mit-license
*/

#include <kernel/cmd/editor.h>
#include <fs/core.h>

struct editor_state {
    char lines[EDITOR_MAX_LINES][EDITOR_BUFFER_SIZE];
    int line_count;
    int display_start;
    int display_end;
};

// Improved safe_scan: scans directly into buffer up to max_len
int safe_scan(char* buffer, int max_len) {
    if (!buffer || max_len <= 0) {
        return -1;
    }

    strcls(buffer);

    // Assume scan reads a line of input; truncate manually after scan
    scan(buffer);

    int len = alen(buffer);
    if (len > max_len) {
        len = max_len;
        printk("Warning: input truncated to %d characters\n", max_len);
        buffer[len] = '\0';
    }

    return len;
}

static void editor_edit_line(struct editor_state* state, int line_num) {
    if (line_num < 1 || line_num > state->line_count) {
        printk("Invalid line number!\n");
        return;
    }

    char input[EDITOR_BUFFER_SIZE];
    strcls(input);
    printf("New content for line %d> ", line_num);
    safe_scan(input, EDITOR_BUFFER_SIZE - 1);

    // Ensure newline at end
    size_t len = strlen(input);
    if (len == 0 || input[len - 1] != '\n') {
        stradd(input, "\n");
    }

    strcopy(state->lines[line_num - 1], input);
}

static void editor_print_help() {
    printk("Zeptex editor commands:\n");
    printk("q - quit editor\n");
    printk("w - write to file\n");
    printk("a - add new line\n");
    printk("p - print content\n");
    printk("d - delete line\n");
    printk("i - insert line\n");
    printk("e - edit line\n");
    printk("c - clear editor\n");
    printk("h - show help\n");
}

static void editor_print_content(struct editor_state* state) {
    for (int i = 0; i < state->line_count; i++) {
        printf("%d: %s", i + 1, state->lines[i]);
    }
}

static void editor_redraw(struct editor_state* state) {
    // Clear screen except command line (last line)
    for (int row = 0; row < DISPLAY_HEIGHT - 1; row++) {
        for (int col = 0; col < DISPLAY_WIDTH; col++) {
            uint offset = get_offset(col, row);
            VIDEO_MEMORY_OFFSET[offset] = ' ';
            VIDEO_MEMORY_OFFSET[offset + 1] = display_theme_current;
        }
    }

    // Print lines in visible window
    for (int i = state->display_start; i < state->display_end && i < state->line_count; i++) {
        uint row = i - state->display_start;
        set_cursor_position(0, row);
        printf("%2d: %s", i + 1, state->lines[i]);
    }

    // Clear lines after displayed lines up to display_end (to avoid leftover text)
    for (int i = state->line_count; i < state->display_end; i++) {
        uint row = i - state->display_start;
        if (row >= DISPLAY_HEIGHT - 1) break;
        set_cursor_position(0, row);
        for (int col = 0; col < DISPLAY_WIDTH; col++) {
            uint offset = get_offset(col, row);
            VIDEO_MEMORY_OFFSET[offset] = ' ';
            VIDEO_MEMORY_OFFSET[offset + 1] = display_theme_current;
        }
    }

    // Position cursor at command line prompt
    set_cursor_position(0, DISPLAY_HEIGHT - 1);
    printf("Editor> ");
}

static void editor_delete_line(struct editor_state* state, int line_num) {
    if (line_num < 1 || line_num > state->line_count) {
        printk("Invalid line number!\n");
        return;
    }
    for (int i = line_num - 1; i < state->line_count - 1; i++) {
        strcopy(state->lines[i], state->lines[i + 1]);
    }
    strcls(state->lines[state->line_count - 1]);
    state->line_count--;
}

static void editor_insert_line(struct editor_state* state, int line_num) {
    if (line_num < 1 || line_num > state->line_count + 1) {
        printk("Invalid line number!\n");
        return;
    }
    if (state->line_count >= EDITOR_MAX_LINES) {
        printk("Too many lines! Cannot insert.\n");
        return;
    }
    // Shift lines down to make space
    for (int i = state->line_count; i >= line_num; i--) {
        strcopy(state->lines[i], state->lines[i - 1]);
    }

    char input[EDITOR_BUFFER_SIZE];
    strcls(input);
    printf("Line %d> ", line_num);
    safe_scan(input, EDITOR_BUFFER_SIZE - 1);

    // Ensure newline at end
    size_t len = strlen(input);
    if (len == 0 || input[len - 1] != '\n') {
        stradd(input, "\n");
    }

    strcopy(state->lines[line_num - 1], input);
    state->line_count++;
}

static void editor_add_line(struct editor_state* state) {
    if (state->line_count >= EDITOR_MAX_LINES) {
        printk("Too many lines! Cannot add.\n");
        return;
    }

    char input[EDITOR_BUFFER_SIZE];
    strcls(input);
    printf("Line> ");
    safe_scan(input, EDITOR_BUFFER_SIZE - 1);

    // Ensure newline at end
    size_t len = strlen(input);
    if (len == 0 || input[len - 1] != '\n') {
        stradd(input, "\n");
    }

    strcopy(state->lines[state->line_count], input);
    state->line_count++;
}

static void editor_write_to_file(const char* filename, struct editor_state* state) {
    char* content = (char*) kmalloc(EDITOR_BUFFER_SIZE * EDITOR_MAX_LINES);
    if (!content) {
        printk("Failed to allocate memory for content\n");
        return;
    }
    strcls(content);

    // Concatenate all lines ensuring newline
    for (int i = 0; i < state->line_count; i++) {
        stradd(content, state->lines[i]);
        size_t len = strlen(state->lines[i]);
        if (len == 0 || state->lines[i][len - 1] != '\n') {
            stradd(content, "\n");
        }
    }

    file_clean(filename);
    int response = file_writes(filename, content);

    if (response == 0) {
        printk("File saved successfully!\n");
    } else {
        printk("Failed to save file\n");
    }

    kfree(content);
}

int ksh_editor() {
    struct editor_state state = {0};
    state.display_start = 0;
    state.display_end = DISPLAY_HEIGHT - 1;  // Display lines up to last but one (command line)

    char filename[EDITOR_BUFFER_SIZE];
    strcls(filename);
    printf("Filename> ");
    if (safe_scan(filename, SAFE_INPUT_MAX) < 0) {
        printk("Failed to read filename\n");
        return EDITOR_ERR_MEMORY;
    }

    if (file_get_id(filename) == FILE_NOT_FOUND) {
        if (file_make(filename) != OK) {
            printk("Failed to create file!\n");
            return EDITOR_ERR_FILE_CREATE;
        }
        printk("Created new file.\n");
    } else {
        file_open(filename);

        char* buffer = (char*) kmalloc(EDITOR_BUFFER_SIZE * EDITOR_MAX_LINES);
        if (!buffer) {
            printk("Failed to allocate memory for file buffer\n");
            return EDITOR_ERR_MEMORY;
        }
        strcls(buffer);
        int size = file_reads(filename, buffer);

        if (size > 0) {
            int pos = 0;
            while (pos < size && state.line_count < EDITOR_MAX_LINES) {
                int end = pos;
                while (end < size && buffer[end] != '\n') end++;

                // Extract line substring
                int line_len = end - pos;
                if (line_len >= EDITOR_BUFFER_SIZE) {
                    line_len = EDITOR_BUFFER_SIZE - 1;
                }

                // Copy line content into lines array
                memcpy(state.lines[state.line_count], &buffer[pos], line_len);
                state.lines[state.line_count][line_len] = '\0';

                // Append newline if original line had it
                if (end < size && buffer[end] == '\n') {
                    stradd(state.lines[state.line_count], "\n");
                }

                state.line_count++;
                pos = end + 1;
            }
        }
        kfree(buffer);
    }

    // Initial screen draw
    editor_redraw(&state);

    while (1) {
        // Clear only the command line
        uint bottom_offset = get_offset(0, DISPLAY_HEIGHT - 1);
        for (int i = 0; i < DISPLAY_WIDTH; i++) {
            uint char_offset = bottom_offset + (i * 2);
            VIDEO_MEMORY_OFFSET[char_offset] = ' ';
            VIDEO_MEMORY_OFFSET[char_offset + 1] = display_theme_current;
        }

        printf("Editor> ");
        char cmd[2];
        scan(cmd);

        switch (cmd[0]) {
            case 'q':
                // Clean up and return to normal
                for (int i = 0; i < DISPLAY_HEIGHT; i++) {
                    for (int j = 0; j < DISPLAY_WIDTH; j++) {
                        uint offset = get_offset(j, i);
                        VIDEO_MEMORY_OFFSET[offset] = ' ';
                        VIDEO_MEMORY_OFFSET[offset + 1] = display_theme_current;
                    }
                }
                return EDITOR_ERR_NONE;

            case 'w':
                editor_write_to_file(filename, &state);
                break;

            case 'a':
                editor_add_line(&state);
                editor_redraw(&state);
                break;

            case 'p':
                editor_print_content(&state);
                break;

            case 'd': {
                printf("Delete line number: ");
                char cmd_input[8];
                safe_scan(cmd_input, 7);
                int line_num = str_to_int(cmd_input, strlen(cmd_input));
                editor_delete_line(&state, line_num);
                editor_redraw(&state);
                break;
            }

            case 'i': {
                printf("Insert line number: ");
                char cmd_input[8];
                safe_scan(cmd_input, 7);
                int line_num = str_to_int(cmd_input, strlen(cmd_input));
                editor_insert_line(&state, line_num);
                editor_redraw(&state);
                break;
            }

            case 'e': {
                printf("Edit line number: ");
                char cmd_input[8];
                safe_scan(cmd_input, 7);
                int line_num = str_to_int(cmd_input, strlen(cmd_input));
                editor_edit_line(&state, line_num);
                editor_redraw(&state);
                break;
            }

            case 'c':
                state.line_count = 0;
                for (int i = 0; i < EDITOR_MAX_LINES; i++) {
                    strcls(state.lines[i]);
                }
                printk("Editor cleared.\n");
                editor_redraw(&state);
                break;

            case 'h':
                editor_print_help();
                break;

            default:
                printk("Unknown command!\n");
                editor_print_help();
                break;
        }
    }

    return EDITOR_ERR_NONE;
}
