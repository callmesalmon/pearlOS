#include <io.h>
#include <conv.h>

#include "../mem.h" 

int ksh_alloc()
{
    /* Define */
    char* str = (char*) kmalloc(255);

    /* Collect */
    kprints("> ");
    kinputs(str);

    /* Convert */
    if (str_to_int(str, sizeof(str) / sizeof(*str)) == -1)
    {
        kprints("Invalid number.");
        kprintc('\n');
        return -1;
    }
    int num = str_to_int(str, sizeof(str) / sizeof(*str));

    /* Handle */
    kmalloc(num);

    return 0;
}
