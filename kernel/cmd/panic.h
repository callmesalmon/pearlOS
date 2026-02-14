#pragma once

#include <io.h>
#include <mem.h>

#include <kernel/kmsg.h>
#include <kernel/config.h>

int usrpanic() {
    char *msg = (char *) kmalloc(255);

    printf("%s ", KSH_PROMPT2);
    scan(msg);
    kpanic(msg);

    return 0;
}