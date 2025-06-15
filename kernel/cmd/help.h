/*
 * Copyright (c) Salmon 2025 under the ANTIFA-MIT license.
 * If your copy of this program doesn't include the license, it is
 * available to read at: 
 *
 *     https://github.com/jamiebuilds/anti-fascist-mit-license
 */

#pragma once

#include <io.h>

int ksh_help() {
    println("help           prints this message");
    println("echo           prints \"X\" to the display");
    println("wipe           clears screen");
    println("loop           loop command \"X\" times");
    println("exit           exit kernel shell");
    println("fortune        digital fortune cookie");
    println("kowsay         a minimal version of cowsay");
    println("version        get kernel version");
    println("pearlfetch     show info about your system");
    println("calc           simple calculator");
    println("theme-light    changes the theme to a light theme");
    println("theme-dark     changes the theme to a dark theme");
    println("theme-pascal   changes the theme to pascal");
    println("theme-hacker   changes the theme back to hacker >:D");
    println("memstat        get allocated memory usage");
    println("memalloc       allocate memory for test");
    println("random         get random number between 0-100");
    println("panic          invoke debug kernel panic");  
    println("ls             list all files");
    println("mk             create new file");
    println("rm             delete file");
    println("cat            read file content");
    println("sz             get size of file");
    println("to             write to file");
    println("femto          lightweight text editor");

    return 0;
}