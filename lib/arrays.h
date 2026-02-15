#pragma once

/* ALen (Array [Due to referencing the array
 * directly] Length) calculates length of array
 * by using ``sizeof(x) / sizeof(x[0])``. Clang
 * likes this implementation, and is thus preferred. */
#define alen(arr) (sizeof(arr) / sizeof(arr[0]))