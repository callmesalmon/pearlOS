#pragma once

#include <io.h>
#include <mem.h>

#include <kernel/kmsg.h>

int usrpanic() {
    char *msg = (char *) kmalloc(255);

    puts("> ");
    scan(msg);
    kpanic(msg);

    return 0;
}
