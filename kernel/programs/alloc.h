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
#include <conv.h>
#include <magic.h>
#include <mem.h> 
#include <drivers/display.h>

int ksh_alloc() {
    /* Define */
    char* str = (char*) kmalloc(255);

    /* Collect */
    printk("> ");
    scan(str);

    /* Convert */
    if (str_to_int(str, len(str)) == INVALID_INT) {
        println("Invalid number.");
        return 1;
    }
    int num = str_to_int(str, len(str));

    /* Handle */
    kmalloc(num);

    return 0;
}