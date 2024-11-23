#include "../io.h"
#include "../../lib/string.h"
#include "../../lib/conv.h"
#include "../mem.h"

#define strint(str) (str_to_int(str, (int)(sizeof str / sizeof *str)))

int calc_init()
{
    /* Define */
    char* n1 = (char*) kmalloc(255);
    char* n2 = (char*) kmalloc(255);
    char* op = (char*) kmalloc(255);

    /* Collect */
    kprints("num> ");
    kinputs(n1);
    kprints("num> ");
    kinputs(n2);
    kprints("op> ");
    kinputs(op);

    kprints("res> ");

    /* Handle */
    if (strcmp(op, "+")) kprintu(strint(n1) + strint(n2));
    else if (strcmp(op, "-")) kprintu(strint(n1) - strint(n2));
    else if (strcmp(op, "*")) kprintu(strint(n1) * strint(n2));
    else if (strcmp(op, "/")) kprintu(strint(n1) / strint(n2));
    else kprints("Invalid operator.");

    kprintc('\n');

    return 0;
}
