/*
 * Copyright (c) Salmon 2025 under the Hippocratic 3.0 license.
 * If your copy of this program doesn't include the license, it is
 * available to read at:
 * 
 *     <https://firstdonoharm.dev/version/3/0/core.txt>
 */

#pragma once

#include <io.h>
#include <mem.h>
#include <drivers/display.h>
#include <kernel/config.h>

void ksh_echo() {
    char* str = (char*) kmalloc(255);
    printf("%s ", KSH_PROMPT2);
    scan(str);
    printf("%s\n", str);
}