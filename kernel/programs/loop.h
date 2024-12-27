/*
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
#include <stddef.h>
#include <mem.h>

char* commands[] = {};

/* Necessary prototype function,
 * since circle importing isn't allowed */
byte ksh_interpret(char* command);

/* Reader */
char** ksh_loop_read(char* stimes) {
    int itimes = str_to_int(stimes, len(stimes));

    for (int i = 0; i < 10; i++) {
        char* cmd = (char*) kmalloc(255);
        
        printk("c> ");
        scan(cmd);
        
        commands[i] = cmd;
    }
    
    return commands;
}

/* Init */
int ksh_loop() {
    char* stimes = (char*) kmalloc(255);
    printk("t> ");
    scan(stimes);
    int itimes = str_to_int(stimes, len(stimes));

    char** commands = ksh_loop_read(stimes);
    int i = 0;

    do {
        int j = 0;
        printk((char*)commands[i]);
        do {
            ksh_interpret((char*)commands[i]);
        } while (j++ < itimes);
    } while (i++ < len(commands));
}