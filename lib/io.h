/*
 * Copyright (c) Salmon 2025 under the ANTIFA-MIT license.
 * If your copy of this program doesn't include the license, it is
 * available to read at: 
 *
 *     https://github.com/jamiebuilds/anti-fascist-mit-license
 */

#pragma once

/* Includes */
#include <stddef.h>
#include <printf.h>
#include <drivers/display.h>
#include <drivers/keyboard.h>
#include <drivers/display_color.h>

/* Defines */
#define printf  printf_
#define sprintf sprintf_

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