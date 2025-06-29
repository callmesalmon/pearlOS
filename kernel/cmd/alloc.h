/*
 * Copyright (c) Salmon 2025 under the Hippocratic 3.0 license.
 * If your copy of this program doesn't include the license, it is
 * available to read at:
 * 
 *     <https://firstdonoharm.dev/version/3/0/core.txt>
 */

#pragma once

#include <io.h>
#include <conv.h>
#include <magic.h>
#include <mem.h> 
#include <drivers/display.h>
#include <kernel/config.h>

int ksh_alloc() {
    /* Define */
    char* str = (char*) kmalloc(255);

    /* Collect */
    printf("%s ", KSH_PROMPT2);
    scan(str);

    /* Convert */
    if (str_to_int(str, alen(str)) == INVALID_INT) {
        println("Invalid number.");
        return 1;
    }
    int num = str_to_int(str, alen(str));

    /* Handle */
    kmalloc(num);

    return 0;
}