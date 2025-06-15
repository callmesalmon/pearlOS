/*
 * Copyright (c) Salmon 2025 under the ANTIFA-MIT license.
 * If your copy of this program doesn't include the license, it is
 * available to read at: 
 *
 *     https://github.com/jamiebuilds/anti-fascist-mit-license
 */

#pragma once

#include <io.h>
#include <conv.h>
#include <magic.h>
#include <stddef.h>
#include <mem.h>

/* Another hella buggy one. You can actually almost make
 * loops with this one tho tehee :3 (No but actually fuck
 * this, I should probably fix this)
 */

char* commands[] = {};

/* Necessary prototype function,
 * since circle importing isn't allowed */
byte ksh_interpret(char* command);

/* Reader */
char** ksh_loop_read(char* stimes) {
    int itimes = str_to_int(stimes, alen(stimes));

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
    int itimes = str_to_int(stimes, alen(stimes));

    char** commands = ksh_loop_read(stimes);
    int i = 0;

    do {
        int j = 0;
        do {
            ksh_interpret((char*)commands[i]);
        } while (j++ < itimes);
    } while (i++ < alen(commands));
}