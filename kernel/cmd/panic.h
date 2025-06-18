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

#include <kernel/kmsg.h>

int usrpanic() {
    char *msg = (char *) kmalloc(255);

    printk("> ");
    scan(msg);
    kpanic(msg);

    return 0;
}