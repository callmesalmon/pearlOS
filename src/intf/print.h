/* **RULES FOR PRINTING**
 * This file contains the definitions/prototypes
 * of printing to the screen in OSk, remade completely
 * from scratch, infact, there are no printf(...)
 * statements in this entire kernel! Check ./print.c
 * for the full definitions.
 */

#ifndef _PRINT
#define _PRINT

#pragma once

#include <stdint.h>
#include <stddef.h>

enum {
    PRINT_COLOR_BLACK       = 0,
	PRINT_COLOR_BLUE        = 1,
	PRINT_COLOR_GREEN       = 2,
	PRINT_COLOR_CYAN        = 3,
	PRINT_COLOR_RED         = 4,
	PRINT_COLOR_MAGENTA     = 5,
	PRINT_COLOR_BROWN       = 6,
	PRINT_COLOR_LIGHT_GRAY  = 7,
	PRINT_COLOR_DARK_GRAY   = 8,
	PRINT_COLOR_LIGHT_BLUE  = 9,
	PRINT_COLOR_LIGHT_GREEN = 10,
	PRINT_COLOR_LIGHT_CYAN  = 11,
	PRINT_COLOR_LIGHT_RED   = 12,
	PRINT_COLOR_PINK        = 13,
	PRINT_COLOR_YELLOW      = 14,
	PRINT_COLOR_WHITE       = 15,
};

void printClear();
void printChar(char character);
void printStr(char* string);
void printSetColor(uint8_t foreground, uint8_t background);

#endif /* _PRINT */
