#pragma once

/* Includes */
#include <types.h>
#include <printf.h>
#include <drivers/display.h>
#include <drivers/keyboard.h>
#include <drivers/display_color.h>

/* Defines */
#ifndef PRINTF_ONLY
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