/* 
 * Copyright (c) Salmon 2025 under the ANTIFA-MIT license.
 * If your copy of this program doesn't include the license, it is
 * available to read at: 
 *
 *     https://github.com/jamiebuilds/anti-fascist-mit-license
 */

#pragma once

/* kernel.c */
#define DEFAULT_THEME  GREEN_ON_BLACK
#define KERNEL_STARTUP ksh_start()
#define KERNEL_UPDATE

/* ksh.h */
#define KSH_PROMPT  "*"
#define KSH_COMMENT ';'

/* mem.h */
#define KERNEL_MEMORY_OFFSET_START 0xffffff
#define KERNEL_MEMORY_OFFSET_END   0xffffffff
#define MEMORY_INDEX_BASE_SIZE     10000