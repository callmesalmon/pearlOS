#include "../io.h"
#include "../mem.h"

void ksh_println()
{
    char* str = (char*) kmalloc(255);
    kprints("Enter string: ");
    kinputs(str);
    kprints(str);
    kprintc('\n');
}
