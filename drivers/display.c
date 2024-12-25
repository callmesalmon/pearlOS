/*
Licensed to the Apache Software Foundation (ASF) under one
or more contributor license agreements.  See the LICENSE file
distributed with this work for additional information
regarding copyright ownership.  The ASF licenses this file
to you under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance
with the License.  You may obtain a copy of the License at

  http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing,
software distributed under the License is distributed on an
"AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
KIND, either express or implied.  See the License for the
specific language governing permissions and limitations
under the License.
*/

#include <stddef.h>

#include <drivers/display.h>
#include <drivers/display_cursor.h>

static byte display_theme_current;

uint get_offset(uint column, uint row) { return 2 * (row * DISPLAY_WIDTH + column); }
uint get_offset_row(uint offset) { return offset / (2 * DISPLAY_WIDTH); }
uint get_offset_column(uint offset) { return (offset - (get_offset_row(offset)*2*DISPLAY_WIDTH))/2; }

void set_cursor_position(uint column, uint row) { set_cursor_offset(get_offset(column, row)); }

// draws character at specific offset
void display_char(char character, uint offset, byte color) {
	INIT_VIDEO
	video_memory[offset*2] = character;
  if (color != TRANSPARENT) { video_memory[offset*2 + 1] = color; }
}

// called when display should scroll
void do_scroll() {
  // kdisplay_clear();
  display_scroll();
}

// prints a newline, equivalent to putc('\n')
void printnl() {
  uint cursor_offset = get_cursor_offset();
  uint cursor_offset_row = get_offset_row(cursor_offset);
  set_cursor_position( 0, cursor_offset_row + 1);
  if (cursor_offset_row > DISPLAY_HEIGHT + DISPLAY_SCROLL_DETECTION_DEBUG) do_scroll();
}

// print char to cursor with color
void cputc(char character, char color) {
  INIT_VIDEO
	uint cursor = get_cursor_offset();
	if (character == '\n') {
		printnl();
	}
    else {
      if (cursor <= (DISPLAY_WIDTH * DISPLAY_HEIGHT - 2) * 2) {
        video_memory[cursor] = character;
        if (color != TRANSPARENT) video_memory[cursor + 1] = color;   // if the color is transparent no will be drawn
        set_cursor_offset(cursor + 2);
      }
      else {
        printnl();
      }
    }
}

// print char to cursor with default color
void putc(char character) {
	cputc(character, TRANSPARENT);
}

void cput(char* text, uint32_t depth, byte color) {
  for (uint32_t i = 0; i < depth; ++i) {
    cputc(text[i], color);
  }
}

void put(char* text, uint32_t depth) {
  cput(text, depth, TRANSPARENT);
}

void display_theme(char color) { // draw a specific color on whole display
  INIT_VIDEO
  display_theme_current = color;
  for (uint i = 1; i < DISPLAY_WIDTH * DISPLAY_WIDTH; i += 2) {
    video_memory[i] = color;
  }
}

// copy a display row over another
void rowcpy(uint dest, uint src) {
  INIT_VIDEO;
  // get row offset
  char* dest_offset = get_offset(0, dest) + video_memory;
  char* src_offset = get_offset(0, src) + video_memory;
  // use the offset in memcpy
  for (uint32_t i = 0; i < DISPLAY_WIDTH + DISPLAY_SCROLL_DEBUG; ++i) {
    dest_offset[i] = src_offset[i];         // scroll text
  }
}

// scroll display by 1 row up
void display_scroll() {
  for (uint row = 1; row <= DISPLAY_HEIGHT; ++row) {
    rowcpy(row - 1, row); // copy the current row to the last (row - 1)
  }
  uint cursor_offset = get_cursor_offset();
  uint cursor_offset_row = get_offset_row(cursor_offset);
  set_cursor_position( 0, cursor_offset_row - 1);
}

// clear display
void display_clear() {
	for (uint i = 0; i < DISPLAY_WIDTH * DISPLAY_HEIGHT; ++i) {
		display_char(0, i, 0x00);
	}
	set_cursor_offset(0);
  display_theme(display_theme_current);
}

void display_deletec() {
  set_cursor_offset(get_cursor_offset()-1);
  putc(0);
  set_cursor_offset(get_cursor_offset()-1);
}

void display_init() {
  display_theme_current = DEFAULT_THEME;
}