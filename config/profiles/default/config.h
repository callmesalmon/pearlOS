/*
 * Copyright (c) Salmon 2025 under the Hippocratic 3.0 license.
 * If your copy of this program doesn't include the license, it is
 * available to read at:
 * 
 *     <https://firstdonoharm.dev/version/3/0/core.txt>
 */

#pragma once

/* kernel.c */
#define DEFAULT_THEME  WHITE_ON_BLUE
#define KERNEL_STARTUP ksh_start()
#define KERNEL_UPDATE

/* ksh.h */
#define KSH_PROMPT  "%"
#define KSH_PROMPT2 ">"
#define KSH_COMMENT ';'

/* mem.h */
#define KERNEL_MEMORY_OFFSET_START 0xffffff
#define KERNEL_MEMORY_OFFSET_END   0xffffffff
#define MEMORY_INDEX_BASE_SIZE     10000