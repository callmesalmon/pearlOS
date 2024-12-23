#pragma once

#include <io.h>
#include <mem.h>

void ksh_echo() {
    char* str = (char*) kmalloc(255);
    puts("> ");
    scan(str);
    puts(str);
    putc('\n');
}