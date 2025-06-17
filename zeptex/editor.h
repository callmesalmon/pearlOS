/*
 *     Author: androvonx95 (https://github.com/androvonx95/)
 */


#pragma once

#include <io.h>
#include <string.h>
#include <mem.h>
#include <fs/core.h>
#include <magic.h>    
#include <drivers/display.h>
#include <stdint.h>

// Editor version
#define EDITOR_VERSION "1.0"

// Editor configuration
#define EDITOR_BUFFER_SIZE 256
#define EDITOR_MAX_LINES 100
#define SAFE_INPUT_MAX 255  // Maximum input length minus null terminator

// Editor state structure
struct editor_state {
    char lines[EDITOR_MAX_LINES][EDITOR_BUFFER_SIZE];
    int line_count;
    int display_start;  // Which line to start displaying
    int display_end;    // Which line to end displaying
};

// Safe input functions
int safe_scan(char* buffer, int max_len);

// Display constants from kernel
#define DISPLAY_WIDTH  80
#define DISPLAY_HEIGHT 25
#define COMMAND_LINE_HEIGHT (DISPLAY_HEIGHT - 1)

// Screen buffer management
#define VIDEO_MEMORY_OFFSET (uint*) 0xb8000

// Screen buffer functions
uint get_offset(uint column, uint row);
uint get_offset_row(uint offset);
uint get_offset_column(uint offset);
void set_cursor_position(uint column, uint row);

// File modes
#define EDITOR_FILE_MODE_CREATE 1
#define EDITOR_FILE_MODE_OPEN   2

// Error codes
#define EDITOR_ERR_NONE           0
#define EDITOR_ERR_FILE_NOT_FOUND 1
#define EDITOR_ERR_FILE_CREATE    2
#define EDITOR_ERR_FILE_SAVE      3
#define EDITOR_ERR_LINE_FULL      4
#define EDITOR_ERR_MEMORY         5

/**
* Launches the built-in line editor in kernel shell.
* Allows editing a file interactively using a simple line-based interface.
*/
int ksh_editor();