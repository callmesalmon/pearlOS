/*
 * Copyright (c) Salmon 2025 under the ANTIFA-MIT license.
 * If your copy of this program doesn't include the license, it is
 * available to read at: 
 *
 *     https://github.com/jamiebuilds/anti-fascist-mit-license
 */

#pragma once

#include <io.h>
#include <err.h>
#include <mem.h>
#include <drivers/display.h>

excode ksh_memstat() {
    println("Memory usage:");
    printf("total: %d\n", memory_usage());
    printf("effective: %d\n", memory_usage_effective());
    
    return exitval;
}