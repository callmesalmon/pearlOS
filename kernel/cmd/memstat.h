#pragma once

#include <io.h>
#include <mem.h>
#include <drivers/display.h>

int ksh_memstat() {
    println("Memory usage:");
    printf("total: %d\n", memory_usage());
    printf("effective: %d\n", memory_usage_effective());
    
    return 0;
}