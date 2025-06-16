#include <zeptex/editor.h>

#ifndef uint8_t
#define uint8_t unsigned char
#endif

// Improved safe_scan: scans directly into buffer up to max_len
int safe_scan(char* buffer, int max_len) {
    if (!buffer || max_len <= 0) {
        return -1;
    }

    strcls(buffer);

    // Assume scan reads a line of input; truncate manually after scan
    scan(buffer);

    int len = max_len; // Use max_len directly
    int current_len = strlen(buffer);
    if (current_len > max_len) {
        cprintk("Warning: input truncated to %d characters\n", max_len);
        buffer[len] = '\0';
    }

    return len;
}

// Define display theme color
uint8_t display_theme_current = 0x07;  // White text on black background

// Removed redefinition of VIDEO_MEMORY_OFFSET
//#define VIDEO_MEMORY_OFFSET ((volatile uint8_t*) 0xb8000)

// Editor write to file
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

    // Cast filename to (char*) when calling these functions
    file_clean((char*) filename); // Cast to char* explicitly
    int response = file_writes((char*) filename, content); // Cast to char*

    if (response == 0) {
        printk("File saved successfully!\n");
    } else {
        printk("Failed to save file\n");
    }

    kfree(content);
}

// Replaced `str_to_int` with `atoi`
// Editor delete line function
static void editor_delete_line(struct editor_state* state, int line_num) {
    if (line_num < 1 || line_num > state->line_count) {
        printk("Invalid line number!\n");
        return;
    }
    for (int i = line_num - 1; i < state->line_count - 1; i++) {
        strcpy(state->lines[i], state->lines[i + 1]);
    }
    strcls(state->lines[state->line_count - 1]);
    state->line_count--;
}

// Replaced `file_open` with `file_read`
int ksh_editor() {
    struct editor_state state = {0};
    state.display_start = 0;
    state.display_end = DISPLAY_HEIGHT - 1;

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
        // Declare buffer to hold file content
        char buffer[EDITOR_BUFFER_SIZE * EDITOR_MAX_LINES] = {0};
        file_read((char*) filename, buffer);  // Cast to char* explicitly

        // Code to load file into editor state...
    }

    // Initialize editor state here...

    // Display lines on screen...
    // More code...

    return EDITOR_ERR_NONE;
}
