/*
 * Copyright (c) Salmon 2025 under the Hippocratic 3.0 license.
 * If your copy of this program doesn't include the license, it is
 * available to read at:
 * 
 *     <https://firstdonoharm.dev/version/3/0/core.txt>
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