#include "../io.h"
#include "../../lib/string.h"
#include "../../lib/conv.h"
#include "../mem.h"

#define strint(str) (str_to_int(str, (int)(sizeof str / sizeof *str)))

int calc_init()
{
    /* Msg */
    kprints("PearlCalc -- Simple calculator\n\n");

    /* Define */
    char* n1 = (char*) kmalloc(255);
    char* n2 = (char*) kmalloc(255);
    char* op = (char*) kmalloc(255);

    /* Collect */
    kprints("num> ");
    kinputs(n1);
    kprintc('\n');
    kprints("num> ");
    kinputs(n2);
    kprintc('\n');
    kprints("op> ");
    kinputs(op);

    /* Handle */
    if (strcmp(op, "+")) kprintu(strint(n1) + strint(n2));
    else if (strcmp(op, "-")) kprintu(strint(n1) - strint(n2));
    else if (strcmp(op, "*")) kprintu(strint(n1) * strint(n2));
    else if (strcmp(op, "/")) kprintu(strint(n1) / strint(n2));
    kprintc('\n');
    
    return 0;
}
