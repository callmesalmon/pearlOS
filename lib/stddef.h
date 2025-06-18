/*
 * Copyright (c) Salmon 2025 under the Hippocratic 3.0 license.
 * If your copy of this program doesn't include the license, it is
 * available to read at:
 * 
 *     <https://firstdonoharm.dev/version/3/0/core.txt>
 */

#pragma once

/* Generic types */
typedef unsigned long uint32_t;
typedef unsigned char byte;
typedef unsigned char* bytes;
typedef unsigned int uint;
typedef unsigned short word;
typedef unsigned char uchar;
typedef unsigned short ushort;

/* size_t */
#ifdef __SIZE_TYPE__
     typedef __SIZE_TYPE__ size_t;
#else
#    error "[ERROR] \"__SIZE_TYPE__\" is not defined. Can't compile."
#endif

/* Boolean definitions */
#ifndef __cplusplus
typedef unsigned char bool;
#endif

#if !defined(true) && !defined(false)
#    define true (bool) 1
#    define false (bool) 0
#endif

/* NULL definition */
#ifndef NULL
#    define NULL (void*) 0
#endif

/* High/Low 16 definitions */
#if !defined(low_16) && !defined(high_16)
#    define low_16(address) (word)((address) & 0xFFFF)
#    define high_16(address) (word)(((address) >> 16) & 0xFFFF)
#endif