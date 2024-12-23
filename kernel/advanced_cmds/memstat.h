#pragma once

#include <io.h>

int ksh_memstat() {
    puts("Memory usage:");
    puts("\ntotal: ");
    putu32(memory_usage());
    puts("\neffective: ");
    putu32(memory_usage_effective());
    putc('\n');
    
    return 0;
}