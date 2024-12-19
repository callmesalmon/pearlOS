#pragma once

#include <io.h>

int help_init() {
    puts("help           prints this message\n");
    puts("echo           prints \"X\" to the display\n");
    puts("wipe           clears screen\n");
    puts("loop           loop command \"X\" times\n");
    puts("exit           exit kernel shell\n");
    puts("fortune        digital fortune cookie\n");
    puts("version        get kernel version\n");
    puts("pearlfetch     show info about your system\n");
    puts("calc           simple calculator\n");
    puts("theme-light    changes the theme to a light theme\n");
    puts("theme-dark     changes the theme to a dark theme\n");
    puts("theme-pascal   changes the theme to pascal\n");
    puts("hacker         changes the theme back to hacker >:D\n");
    puts("memstat        get allocated memory usage\n");
    puts("memalloc       allocate memory for test\n");
    puts("random         get random number between 0-100\n");
    puts("panic          invoke debug kernel panic\n");  
    puts("ls             list all files\n");
    puts("mk             create new file\n");
    puts("rm             delete file\n");
    puts("cat            read file content\n");
    puts("to             write to file\n");
}
