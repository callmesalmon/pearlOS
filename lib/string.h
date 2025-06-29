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

/* Defines */
uint strlen(char* string);
void strcpy(char* dest, char* src);
bool strcmp(char* a, char* b);
void stradd(char* base, char* extension);
void strcls(char* string);
char char_to_upper(char character);
void strupp(char* string);