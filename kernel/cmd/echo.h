/*
 * Copyright (c) Salmon 2025 under the ANTIFA-MIT license.
 * If your copy of this program doesn't include the license, it is
 * available to read at: 
 *
 *     https://github.com/jamiebuilds/anti-fascist-mit-license
 */

#pragma once

#include <io.h>
#include <mem.h>
#include <drivers/display.h>

void ksh_echo() {
    char* str = (char*) kmalloc(255);
    printk("> ");
    scan(str);
    printf("%s\n", str);
}