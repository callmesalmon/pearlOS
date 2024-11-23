#include "../io.h"
#include "../mem.h"
#include "../../lib/string.h"
#include "../../lib/conv.h"
#include "../../lib/math.h"

#define strint(str) (str_to_int(str, (int)(sizeof str / sizeof *str)))

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

    kprints("res> ");

    /* Convert */
    int n1 = strint(s1);
    int n2 = strint(s2);

    /* Handle */
    if (strcmp(op, "+"))      kprintu(n1 + n2);
    else if (strcmp(op, "-")) kprintu(n1 - n2);
    else if (strcmp(op, "*")) kprintu(n1 * n2);
    else if (strcmp(op, "/")) kprintu(n1 / n2);
    else if (strcmp(op, "^")) kprintu(pow(n1, n2));
    else if (strcmp(op, "%")) kprintu(n1 % n2);
    else kprints("Invalid operator.");

    kprintc('\n');

    return 0;
}
