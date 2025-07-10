/*
 * Copyright (c) Salmon 2025 under the Hippocratic 3.0 license.
 * If your copy of this program doesn't include the license, it is
 * available to read at:
 * 
 *     <https://firstdonoharm.dev/version/3/0/core.txt>
 */

#pragma once

#include <io.h>
#include <mem.h>
#include <string.h>
#include <kernel/config.h>

void ksh_manpage1();
void ksh_manpage2();
void ksh_manpage3();

int ksh_help() {
    char* str = (char*) kmalloc(255);

    printf("What page of the manual would you like to open? [1-3]\n");
    printf("%s ", KSH_PROMPT2);

    scan(str);

    if (strcmp(str, "1")) {
        ksh_manpage1();
    }
    else if (strcmp(str, "2")) {
        ksh_manpage2();
    }
    else if (strcmp(str, "3")) {
        ksh_manpage3();
    }
    else {
        printf("Invalid page number!\n");
    }

    return 0;
}

void ksh_manpage1() {
    println("=== KSH Manual page 1: A brief description ===");
    println("KSH (Kernel SHell), is the main (and so far only) shell in pearlOS.");
    println("It's very simple and quite frankly pretty bad, with for example");
    println("parameters needing to be on another line as the command. Nonetheless");
    println("it's a useful tool for navigating pearlOS.");
}

void ksh_manpage2() {
    println("=== KSH Manual page 2: Commands ===");
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
    println("theme-hacker   changes the theme to hacker >:3");
    println("memstat        get allocated memory usage");
    println("memalloc       allocate memory");
    println("coin           flip a fucking coin");
    println("panic          invoke kernel panic");  
    println("exit           exit OS");

}

void ksh_manpage3() {
    println("=== KSH Manual page 3: More commands ===");
    println("ls             list all files");
    println("mk             create new file");
    println("rm             delete file");
    println("cat            read file content");
    println("to             write to file");
}