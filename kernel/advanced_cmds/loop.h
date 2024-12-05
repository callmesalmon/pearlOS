#include <io.h>
#include <conv.h>
#include <magic.h>

#include "../mem.h"

char* commands[] = {};

char** ksh_loop()
{
    char* stimes = (char*) kmalloc(255);
    
    puts("t> ");
    scan(stimes);
    int itimes = str_to_int(stimes, len(stimes));

    for (int i = 0; i < itimes; i++)
    {
        char* cmd = (char*) kmalloc(255);
        
        puts("c> ");
        scan(cmd);
        
        commands[i] = cmd;
    }
    
    return commands;
}
