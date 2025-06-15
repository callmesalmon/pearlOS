/*
 * Copyright (c) Salmon 2025 under the ANTIFA-MIT license.
 * If your copy of this program doesn't include the license, it is
 * available to read at: 
 *
 *     https://github.com/jamiebuilds/anti-fascist-mit-license
 */

#pragma once

#include <stdint.h>

/* PLen (Pointer Length) calculates length
 * of array by using ``sizeof(x) / sizeof(*x)``.*/
#define plen(arr)  (sizeof(arr) / sizeof(*arr))

/* ALen (Array [Due to referencing the array
 * directly] Length) calculates length of array
 * by using ``sizeof(x) / sizeof(x[0])``. Clang
 * likes this implementation, and is thus preferred. */
#define alen(arr) (sizeof(arr) / sizeof(arr[0]))