/*
 * Copyright (c) Salmon 2025 under the Hippocratic 3.0 license.
 * If your copy of this program doesn't include the license, it is
 * available to read at:
 * 
 *     <https://firstdonoharm.dev/version/3/0/core.txt>
 */

#include <kernel/ksh.h>

char *theme;

#include <kernel/cmd/pearlfetch.h>
#include <kernel/cmd/list_files.h>
#include <kernel/cmd/read_file.h>
#include <kernel/cmd/write_to_file.h>
#include <kernel/cmd/make_file.h>
#include <kernel/cmd/fortune.h>
#include <kernel/cmd/remove_file.h>
#include <kernel/cmd/echo.h>
#include <kernel/cmd/help.h>
#include <kernel/cmd/calc.h>
#include <kernel/cmd/panic.h>
#include <kernel/cmd/alloc.h>
#include <kernel/cmd/memstat.h>
#include <kernel/cmd/cowsay.h>
#include <kernel/cmd/exit.h>

byte ksh_interpret(char* command) {
    if (!*command) {
        return KSH_OK;
    }
    else if (command[0] == KSH_COMMENT) {
        return KSH_OK;
    }
    else if (strcmp(command, "help")) {
        ksh_help();
    }
    else if (strcmp(command, "echo")) {
        ksh_echo();
    }
    else if (strcmp(command, "wipe")) {
        display_clear();
    }
    else if (strcmp(command, "version")) {
        printf("OS version: %s\n", OS_VERSION);
        printf("OS version (generic): %s\n", OS_GENERIC);
        printf("KSH version: %s\n", KSH_VERSION);
    }
    else if (strcmp(command, "memstat")) {
        ksh_memstat();
    }
    else if (strcmp(command, "theme-light")) {
        display_theme(BLACK_ON_WHITE);
        theme = "Generic light";
    }
    else if (strcmp(command, "theme-dark")) {
        display_theme(WHITE_ON_BLACK);
        theme = "Generic dark";
    }
    else if (strcmp(command, "theme-pascal")) {
        display_theme(WHITE_ON_BLUE);
        theme = "Generic pascal";
    }
    else if (strcmp(command, "theme-hacker")) {
        display_theme(GREEN_ON_BLACK);
        theme = "Hacker >:3";
        cprintln("You are a hacker now! >:3", RED_ON_BLACK);
    }
    else if (strcmp(command, "fortune")) {
        ksh_fortune();
    }
    else if (strcmp(command, "kowsay")) {
        kowsay();
    }
    else if (strcmp(command, "calc")) {
        ksh_calc();
    }
    else if (strcmp(command, "memalloc")) {
        ksh_alloc();
    }
    else if (strcmp(command, "pearlfetch")) {
        ksh_pearlfetch();
    }
    else if (strcmp(command, "ls")) {
        ksh_list_files();
    }
    else if (strcmp(command, "mk")) {
        ksh_make_file();
    }
    else if (strcmp(command, "rm")) {
        ksh_remove_file();
    }
    else if (strcmp(command, "cat")) {
        ksh_read_file();
    }
    else if (strcmp(command, "to")) {
        ksh_write_to_file();
    }
    else  if (strcmp(command, "exit")) {
        return ksh_exit();
    }
    else if (strcmp(command, "coin")) {
        printf("%s\n", ((rand() % 2) == 1) ? "heads" : "tails");
    }
    else if (strcmp(command, "panic")) {
        usrpanic();
    }
    else {
        printk(KERNEL_INFO_SHELL_UNKNOWN_COMMAND);
    }
    return KSH_OK;
}

void ksh_start() {
    theme = "Generic pascal";

    char c[KSH_INPUT_BUFFER];
    for (uint i = 0; i < KSH_INPUT_BUFFER; ++i) {
        c[i] = (char) 0;
    }

    byte response;

    printk(KERNEL_INFO_SHELL_WELCOME);
    printk(KERNEL_INFO_MANUAL_HELP);

    while (true) {
        printf("%s ", KSH_PROMPT);
        scan(c);
        response = ksh_interpret(c);

        if (response == KSH_EXIT) {
            break;
        }

        strcls(c);
    }
}