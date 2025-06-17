/*
 * Copyright (c) Salmon 2025 under the ANTIFA-MIT license.
 * If your copy of this program doesn't include the license, it is
 * available to read at: 
 *
 *     https://github.com/jamiebuilds/anti-fascist-mit-license
 */

#include <stddef.h>

#include <drivers/display.h>
#include <drivers/display_cursor.h>

/* * * * * * * * * * * * * * * * * * *
 *     The fourth commandment.       *
 * * * * * * * * * * * * * * * * * * *
 * When in need of a video based     *
 * function, thou shall not send     *
 * a prayer to above (gotten         *
 * that *way* too many times),       *
 * thou shall instead initialize     *
 * the memory with a macro the       *
 * gods graciously provided to you.  *
 * It's very easy, like this:        *
 *                                   *
 *     int video_based_function() {  *
 *         INIT_VIDEO;               *
 *         ...                       *
 *     }                             *
 *                                   *
 * Finally those nerds will stop     *
 * asking me to give them video.     *
 * Also, I have already done that!   *
 * "First, there was nothing."       *
 * "Then, there was video."          *
 * * * * * * * * * * * * * * * * * * */

static byte display_theme_current;

uint get_offset(uint column, uint row) { 
    return 2 * (row * DISPLAY_WIDTH + column);
}
uint get_offset_row(uint offset) {
    return offset / (2 * DISPLAY_WIDTH);
}
uint get_offset_column(uint offset) {
    return  (offset - (get_offset_row(offset) * 2 * DISPLAY_WIDTH)) / 2;
}

void set_cursor_position(uint column, uint row) { 
    set_cursor_offset(get_offset(column, row));
}

/* Draws character at specific offset */
void display_char(char character, uint offset, byte color) {
	INIT_VIDEO;
	video_memory[offset * 2] = character;
    if (color != TRANSPARENT) video_memory[offset * 2 + 1] = color;
}

/* Called when display should scroll */
void do_scroll() {
  display_scroll();
}

/* Prints a newline, equivalent to printc('\n') */
void printnl() {
  uint cursor_offset     = get_cursor_offset();
  uint cursor_offset_row = get_offset_row(cursor_offset);

  set_cursor_position(0, cursor_offset_row + 1);

  if (cursor_offset_row > DISPLAY_HEIGHT + DISPLAY_SCROLL_DETECTION_DEBUG) {
    do_scroll();
  }
}

/* Print char to cursor with colour, the
 * lowest level of printing, basically. */
void cprintc(char character, char color) {
    INIT_VIDEO;
	uint cursor = get_cursor_offset();
	if (character == '\n') {
		printnl();
	} else {
      if (cursor <= (DISPLAY_WIDTH * DISPLAY_HEIGHT - 2) * 2) {
        video_memory[cursor] = character;
        /* If the color is transparent nothing will be drawn */
        if (color != TRANSPARENT) video_memory[cursor + 1] = color;
        set_cursor_offset(cursor + 2);
      } else {
        printnl();
      }
    }
}

/* Print char to cursor with default color */
void printc(char character) {
	cprintc(character, TRANSPARENT);
}

void cprint(char* text, uint32_t depth, byte color) {
  for (uint32_t i = 0; i < depth; ++i) {
    cprintc(text[i], color);
  }
}

void print(char* text, uint32_t depth) {
  cprint(text, depth, TRANSPARENT);
}

/* Draw a specific color on whole display */
void display_theme(char color) {
  INIT_VIDEO;
  display_theme_current = color;
  for (uint i = 1; i < DISPLAY_WIDTH * DISPLAY_WIDTH; i += 2) {
    video_memory[i] = color;
  }
}

/* Copy a display row over another */
void rowcpy(uint dest, uint src) {
  INIT_VIDEO;
  
  /* Get row offset */
  char* dest_offset = get_offset(0, dest) + video_memory;
  char* src_offset  = get_offset(0, src)  + video_memory;
  
  /* Use the offset in memcpy */
  for (uint32_t i = 0; i < DISPLAY_WIDTH + DISPLAY_SCROLL_DEBUG; ++i) {
    dest_offset[i] = src_offset[i]; /* Scroll text */
  }
}

/* Scroll display by 1 row up */
void display_scroll() {
  for (uint row = 1; row <= DISPLAY_HEIGHT; ++row) {
    /* Copy the current row to the last */
    rowcpy(row - 1, row); 
  }
  uint cursor_offset = get_cursor_offset();
  uint cursor_offset_row = get_offset_row(cursor_offset);
  set_cursor_position( 0, cursor_offset_row - 1);
}

/* Clear display */
void display_clear() {
	for (uint i = 0; i < DISPLAY_WIDTH * DISPLAY_HEIGHT; ++i) {
		display_char(0, i, 0x00);
	}
	set_cursor_offset(0);
  display_theme(display_theme_current);
}

void display_deletec() {
  set_cursor_offset(get_cursor_offset()-1);
  printc(0);
  set_cursor_offset(get_cursor_offset()-1);
}

void display_init() {
  display_theme_current = DEFAULT_THEME;
}