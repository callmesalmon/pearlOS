#pragma once

#include <io.h>
#include <math.h>
#include <string.h>
#include <conv.h>
#include <arrays.h>
#include <mem.h>
#include <drivers/display.h>
#include <kernel/config.h>

int ksh_calc() {
    /* Define values */
    char* s1 = (char*) kmalloc(255);
    char* s2 = (char*) kmalloc(255);
    char* op = (char*) kmalloc(255);

    /* Collect */
    printf("num%s ", KSH_PROMPT2);
    scan(s1);
    printf("num%s ", KSH_PROMPT2);
    scan(s2);
    printf("op%s ", KSH_PROMPT2);
    scan(op);

    /* Convert */
    int n1 = str_to_int(s1, sizeof(int));
    int n2 = str_to_int(s2, sizeof(int));

    if (n1 == INVALID_INT || n2 == INVALID_INT) {
        printf("Invalid number!\n");
        return 0;
    }

    /* Handle */
    if (strcmp(op, "+"))      printf("%d\n", n1 + n2);
    else if (strcmp(op, "-")) printf("%d\n", n1 - n2);
    else if (strcmp(op, "*")) printf("%d\n", n1 * n2);
    else if (strcmp(op, "/")) printf("%d\n", n1 / n2);
    else if (strcmp(op, "^")) printf("%d\n", pow(n1, n2));
    else {
        println("Invalid operator.");
        return 2;
    }

    return 0;
}