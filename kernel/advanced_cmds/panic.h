#include "../io.h"
#include "../kmsg.h"
#include "../mem.h"

int usrpanic() {
    char *msg = (char *) kmalloc(255);
    kprints("> ");
    kinputs(msg);
    kpanic(msg);
    return 0;
}
