#pragma once

#include <io.h>
#include <mem.h>
#include <drivers/display.h>
#include <kernel/config.h>

void ksh_echo() {
    char* str = (char*) kmalloc(255);
    printf("%s ", KSH_PROMPT2);
    scan(str);
    printf("%s\n", str);
}