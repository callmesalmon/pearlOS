/*
 * Copyright (c) Salmon 2025 under the Hippocratic 3.0 license.
 * If your copy of this program doesn't include the license, it is
 * available to read at:
 * 
 *     <https://firstdonoharm.dev/version/3/0/core.txt>
 */

#pragma once

#include <io.h>

int ksh_help() {
    println("help           prints this message");
    println("echo           prints \"X\" to the display");
    println("wipe           clears screen");
    println("exit           exit kernel shell");
    println("fortune        digital fortune cookie");
    println("kowsay         a minimal version of cowsay");
    println("version        get OS version");
    println("pearlfetch     show info about your system");
    println("calc           simple calculator");
    println("theme-light    changes the theme to a light theme");
    println("theme-dark     changes the theme to a dark theme");
    println("theme-pascal   changes the theme to pascal");
    println("theme-hacker   changes the theme to hacker >:D");
    println("memstat        get allocated memory usage");
    println("memalloc       allocate memory");
    println("random         get random number between 0-100");
    println("panic          invoke kernel panic");  
    println("exit           exit OS");
    println("ls             list all files");
    println("mk             create new file");
    println("rm             delete file");
    println("cat            read file content");
    println("to             write to file");

    return 0;
}