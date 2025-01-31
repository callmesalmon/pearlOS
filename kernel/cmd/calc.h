/*
Copyright 2025 Elis Staaf

Licensed to the Apache Software Foundation (ASF) under one
or more contributor license agreements.  See the LICENSE file
distributed with this work for additional information
regarding copyright ownership.  The ASF licenses this file
to you under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance
with the License.  You may obtain a copy of the License at

  http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing,
software distributed under the License is distributed on an
"AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
KIND, either express or implied.  See the License for the
specific language governing permissions and limitations
under the License.
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

excode ksh_calc() {
    /* Define */
    char* s1 = (char*) kmalloc(255);
    char* s2 = (char*) kmalloc(255);
    char* op = (char*) kmalloc(255);

    /* Collect */
    printk("num> ");
    scan(s1);
    printk("num> ");
    scan(s2);
    printk("op> ");
    scan(op);

    /* Convert */
    if (str_to_int(s1, alen(s1)) == INVALID_INT || str_to_int(s2, alen(s2)) == INVALID_INT) {
        println("Invalid number.");
        return errval;
    }
    int n1 = str_to_int(s1, alen(s1));
    int n2 = str_to_int(s2, alen(s2));

    /* Handle */
    if (strcmp(op, "+")) printu(n1 + n2);
    else if (strcmp(op, "-")) printu(n1 - n2);
    else if (strcmp(op, "*")) printu(n1 * n2);
    else if (strcmp(op, "/")) printu(n1 / n2);
    else if (strcmp(op, "^")) printu(pow(n1, n2));
    else {
        println("Invalid operator.");
        return errval256;
    }

    return exitval;
}