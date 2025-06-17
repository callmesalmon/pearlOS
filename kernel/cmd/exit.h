/*
 * Copyright (c) Salmon 2025 under the ANTIFA-MIT license.
 * If your copy of this program doesn't include the license, it is
 * available to read at: 
 *
 *     https://github.com/jamiebuilds/anti-fascist-mit-license
 */

#pragma once

#include <io.h>
#include <string.h>
#include <mem.h>
#include <kernel/kmsg.h>

#define EXIT_DENY 0x0
#define EXIT_INIT 0x1

byte ksh_exit() {
    char* str = (char*) kmalloc(255);

    kwarning("This will permanently exit you out of the OS. Are you sure?");
    printk("[y/n, default n]% ");
    scan(str);

    if (strcmp(str, "y")) {
        return EXIT_INIT;
    } 

    return EXIT_DENY;
}