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

/* Typedefs */
typedef uint32_t u32;
typedef uint u8;

/* Functions */

/* CHINT (CHar is INT?): Calculates
 * if a char (e.g 'a' or '5') is also
 * a valid int (e.g chint('a') == false,
 * chint('5') == true). */
bool chint(char ch);