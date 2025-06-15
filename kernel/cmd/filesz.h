/*
 * Copyright (c) Salmon 2025 under the ANTIFA-MIT license.
 * If your copy of this program doesn't include the license, it is
 * available to read at: 
 *
 *     https://github.com/jamiebuilds/anti-fascist-mit-license
 */

#include <err.h>
#include <io.h>
#include <mem.h>
#include <conv.h>
#include <fs/core.h>
#include <drivers/display.h>
#include <string.h>

/* DISCLAIMER
 * Fuck this, dude. It keeps kmallocing a value called "S",
 * which presumably happened during the cpu update. Fix later
 * maybe. */

excode ksh_filesz() {
    /* Collect */
    printk("> ");
    char *file = (char *) kmalloc(255);
    scan(file); /* This is where file = "S" */

    /* Handle */
    char *file_sz;
    int_to_str(file_sz, file_size(file));
    printf("%s\n", file_sz);

    return exitval;
}