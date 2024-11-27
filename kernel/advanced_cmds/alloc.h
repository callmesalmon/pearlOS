#include <io.h>
#include <conv.h>
#include <magic.h>

#include "../mem.h" 

int ksh_alloc()
{
    /* Define */
    char* str = (char*) kmalloc(255);

    /* Collect */
    puts("> ");
    scan(str);

    /* Convert */
    if (str_to_int(str, len(str)) == INVALID_INT)
    {
        puts("Invalid number.");
        putc('\n');
        return 1;
    }
    int num = str_to_int(str, len(str));

    /* Handle */
    kmalloc(num);

    return 0;
}
