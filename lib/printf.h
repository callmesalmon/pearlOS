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

/* * * * * * * * * * * * * * * * * * *
 *     The first commandment.        *
 * * * * * * * * * * * * * * * * * * *
 * When you just need                *
 * printf, not the whole IO          *
 * library, do:                      *
 *                                   *
 *     #define PRINTF_IMPL           *
 *     #include <printf.h>           *
 *                                   *
 * If not, you have sinned,          *
 * and will be sent to programmer    *
 * hell forever (it's a              *
 * javascript repl).                 *
 * * * * * * * * * * * * * * * * * * */
#ifdef PRINTF_IMPL
#define printf  printf_
#define sprintf sprintf_
#endif

/* Functions */

/* Main ``printf`` function (true macro
 * defined in ``io.h`` though -_-). */
int printf_(const char *format, ...);

/* SPrintf (Stream Printf). Has *not*
 * been tested, thus should *not* be used. */
int sprintf_(char *out, const char *format, ...);