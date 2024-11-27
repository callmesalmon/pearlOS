#include <io.h>
#include <math.h>
#include <string.h>
#include <conv.h>
#include <magic.h>

#include "../mem.h"

int ksh_calc()
{
    /* Define */
    char* s1 = (char*) kmalloc(255);
    char* s2 = (char*) kmalloc(255);
    char* op = (char*) kmalloc(255);

    /* Collect */
    puts("num> ");
    scan(s1);
    puts("num> ");
    scan(s2);
    puts("op> ");
    scan(op);

    /* Convert */
    if (str_to_int(s1, len(s1)) == INVALID_INT || str_to_int(s2, len(s2)) == INVALID_INT)
    {
        puts("Invalid number.");
        putc('\n');
        return -1;
    }
    int n1 = str_to_int(s1, len(s1));
    int n2 = str_to_int(s2, len(s2));

    /* Handle */
    if (strcmp(op, "+"))      putu(n1 + n2);
    else if (strcmp(op, "-")) putu(n1 - n2);
    else if (strcmp(op, "*")) putu(n1 * n2);
    else if (strcmp(op, "/")) putu(n1 / n2);
    else if (strcmp(op, "^")) putu(pow(n1, n2));
    else puts("Invalid operator.");

    putc('\n');

    return 0;
}
