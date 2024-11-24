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

int calc_init()
{
    /* Define */
    char* s1 = (char*) kmalloc(255);
    char* s2 = (char*) kmalloc(255);
    char* op = (char*) kmalloc(255);

    /* Collect */
    kprints("num> ");
    kinputs(s1);
    kprints("num> ");
    kinputs(s2);
    kprints("op> ");
    kinputs(op);

    /* Convert */
    if (str2int(s1) == -1 || str2int(s2) == -1)
    {
        kprints("Invalid number.");
        kprintc('\n');
        return -1;
    }
    int n1 = str2int(s1);
    int n2 = str2int(s2);

    /* Handle */
    if (strcmp(op, "+"))      kprintu(n1 + n2);
    else if (strcmp(op, "-")) kprintu(n1 - n2);
    else if (strcmp(op, "*")) kprintu(n1 * n2);
    else if (strcmp(op, "/")) kprintu(n1 / n2);
    else if (strcmp(op, "^")) kprintu(pow(n1, n2));
    else kprints("Invalid operator.");

    kprintc('\n');

    return 0;
}
