/*
 * Copyright (c) Salmon 2025 under the Hippocratic 3.0 license.
 * If your copy of this program doesn't include the license, it is
 * available to read at:
 * 
 *     <https://firstdonoharm.dev/version/3/0/core.txt>
 */

#pragma once

#include <io.h>
#include <conv.h>
#include <magic.h>
#include <stddef.h>
#include <mem.h>
#include <kernel/config.h>

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
        
        printf("command%s ", KSH_PROMPT2);
        scan(cmd);
        
        commands[i] = cmd;
    }
    
    return commands;
}

/* Init */
int ksh_loop() {
    char* stimes = (char*) kmalloc(255);
    printf("times%s ", KSH_PROMPT2);
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