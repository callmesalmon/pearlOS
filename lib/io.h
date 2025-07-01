/*
 * Copyright (c) Salmon 2025 under the Hippocratic 3.0 license.
 * If your copy of this program doesn't include the license, it is
 * available to read at:
 * 
 *     <https://firstdonoharm.dev/version/3/0/core.txt>
 */

#pragma once

/* Includes */
#include <stddef.h>
#include <printf.h>
#include <drivers/display.h>
#include <drivers/keyboard.h>
#include <drivers/display_color.h>

/* Defines */
#ifdef PRINTF_ONLY
#define printf  printf_
#endif

/* Functions */
void printi(int number);
void printu(uint number);
void printu32(uint32_t number);
void printk(char* text);
void printhex(uint32_t number);
void cprintk(char* text, char color);
void println(char* text);
void cprintln(char* text, char color);
void scan(char* output);