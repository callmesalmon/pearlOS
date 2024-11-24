#include <io.h>

#include "../kmsg.h"
#include "../mem.h"

int usrpanic() {
    char *msg = (char *) kmalloc(255);

    puts("> ");
    scan(msg);
    kpanic(msg);

    return 0;
}
