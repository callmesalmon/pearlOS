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