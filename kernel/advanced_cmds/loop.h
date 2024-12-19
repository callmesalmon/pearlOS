#pragma once

#include <io.h>
#include <conv.h>
#include <magic.h>
#include <stddef.h>

#include "../mem.h"

char* commands[] = {};

/* Necessary prototype function,
 * since circle importing isn't allowed */
byte ksh_interpret(char* command);

/* Reader */
char** ksh_loop_read(char* stimes)
{
    int itimes = str_to_int(stimes, len(stimes));

    for (int i = 0; i < 10; i++)
    {
        char* cmd = (char*) kmalloc(255);
        
        puts("c> ");
        scan(cmd);
        
        commands[i] = cmd;
    }
    
    return commands;
}

int ksh_loop()
{
    char* stimes = (char*) kmalloc(255);
    puts("t> ");
    scan(stimes);
    int itimes = str_to_int(stimes, len(stimes));

    char** commands = ksh_loop_read(stimes);
    int i = 0;

    do
    {
        int j = 0;
        puts((char*)commands[i]);
        do
        {
            ksh_interpret((char*)commands[i]);
        } while (j++ < itimes);
    } while (i++ < len(commands));
}
