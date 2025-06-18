/*
 * Copyright (c) Salmon 2025 under the Hippocratic 3.0 license.
 * If your copy of this program doesn't include the license, it is
 * available to read at:
 * 
 *     <https://firstdonoharm.dev/version/3/0/core.txt>
 */

#pragma once

#include <io.h>
#include <math.h>
#include <err.h>
#include <string.h>
#include <conv.h>
#include <magic.h>
#include <mem.h>
#include <drivers/display.h>
#include <kernel/config.h>

excode ksh_calc() {
    /* Define */
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
    if (str_to_int(s1, alen(s1)) == INVALID_INT || str_to_int(s2, alen(s2)) == INVALID_INT) {
        println("Invalid number.");
        return errval;
    }
    int n1 = str_to_int(s1, alen(s1));
    int n2 = str_to_int(s2, alen(s2));

    /* Handle */
    if (strcmp(op, "+"))      printf("%d\n", n1 + n2);
    else if (strcmp(op, "-")) printf("%d\n", n1 - n2);
    else if (strcmp(op, "*")) printf("%d\n", n1 * n2);
    else if (strcmp(op, "/")) printf("%d\n", n1 / n2);
    else if (strcmp(op, "^")) printf("%d\n", pow(n1, n2));
    else {
        println("Invalid operator.");
        return errval256;
    }

    return exitval;
}