#include <io.h>
#include <math.h>
#include <string.h>
#include <conv.h>

#include "../mem.h"

int str2int(char *str)
{
    return str_to_int(
        str,
        sizeof(str) / sizeof(*str)
    );
}

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
    if (str2int(s1) == -1 || str2int(s2) == -1)
    {
        puts("Invalid number.");
        putc('\n');
        return -1;
    }
    int n1 = str2int(s1);
    int n2 = str2int(s2);

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
