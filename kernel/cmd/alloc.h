/*
 * Copyright (c) Salmon 2025 under the ANTIFA-MIT license.
 * If your copy of this program doesn't include the license, it is
 * available to read at: 
 *
 *     https://github.com/jamiebuilds/anti-fascist-mit-license
 */

#pragma once

#include <io.h>
#include <conv.h>
#include <magic.h>
#include <mem.h> 
#include <drivers/display.h>

int ksh_alloc() {
    /* Define */
    char* str = (char*) kmalloc(255);

    /* Collect */
    printk("> ");
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