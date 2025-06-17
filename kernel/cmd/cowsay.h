/*
 * Copyright (c) Salmon 2025 under the ANTIFA-MIT license.
 * If your copy of this program doesn't include the license, it is
 * available to read at: 
 *
 *     https://github.com/jamiebuilds/anti-fascist-mit-license
 */

#pragma once


#include <io.h>
#include <magic.h>

void printcow(void);

char upperbubble='\\';
char lowerbubble='\\';

unsigned int counter;
unsigned int argscharcount=0;

int kowsay() {
    char* str = (char*) kmalloc(255);
    printk("> ");
    scan(str);

    for (int i; i < alen(str); i++) {
        argscharcount++;
    }

    for(counter=1; counter <= argscharcount; counter++) {
        printf("_");
    }

    printf("\n<");
    printf("%s", str);
    printf(">\n");

    for(counter=1; counter <= argscharcount; counter++) {
        printf("-");
    }
    printf("\n");
    printcow();
    return 0;
}

void printcow(void) {
printf("        %c    ^__^\n\
         %c   (Oo)\\_______\n\
            (__)\\       )\\/\\\n\
                ||----w |\n\
                ||     ||\n", upperbubble, lowerbubble);
}