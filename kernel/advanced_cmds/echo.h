#include "../io.h"
#include "../mem.h"

void ksh_echo()
{
    char* str = (char*) kmalloc(255);
    kprints("> ");
    kinputs(str);
    kprints(str);
    kprintc('\n');
}
