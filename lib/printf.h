/*
 * Copyright (c) Salmon 2025 under the Hippocratic 3.0 license.
 * If your copy of this program doesn't include the license, it is
 * available to read at:
 * 
 *     <https://firstdonoharm.dev/version/3/0/core.txt>
 */

#pragma once

/* Includes */
#include <io.h>

/* Defines */
#ifndef putchar
#   define putchar(c) printc(c)
#endif

#ifdef PRINTF_ONLY
#define printf  printf_
#endif

/* Functions */

/* Main ``printf`` function (true macro
 * defined in ``io.h`` though -_-). */
int printf_(const char *format, ...);