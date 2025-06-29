/*
 * Copyright (c) Salmon 2025 under the Hippocratic 3.0 license.
 * If your copy of this program doesn't include the license, it is
 * available to read at:
 * 
 *     <https://firstdonoharm.dev/version/3/0/core.txt>
 */

#pragma once

/* ps: I wish I could change the name of this file but uhh
 * to many files depend on this so this'll be the magic file
 * I fucking guess lol :3 */

/* ALen (Array [Due to referencing the array
 * directly] Length) calculates length of array
 * by using ``sizeof(x) / sizeof(x[0])``. Clang
 * likes this implementation, and is thus preferred. */
#define alen(arr) (sizeof(arr) / sizeof(arr[0]))