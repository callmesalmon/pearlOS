#pragma once

#include <stddef.h>
#include <drivers/display.h>
#include <drivers/keyboard.h>
#include <drivers/display_color.h>

void puti(int number);
void putu(uint number);
void putu32(uint32_t number);
void puts(char* text);
void puthex(uint32_t number);
void cputs(char* text, char color);
void scan(char* output);