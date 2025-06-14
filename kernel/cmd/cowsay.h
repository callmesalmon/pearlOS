/*
Copyright 2025 Elis Staaf

Licensed to the Apache Software Foundation (ASF) under one
or more contributor license agreements.  See the LICENSE file
distributed with this work for additional information
regarding copyright ownership.  The ASF licenses this file
to you under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance
with the License.  You may obtain a copy of the License at

  http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing,
software distributed under the License is distributed on an
"AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
KIND, either express or implied.  See the License for the
specific language governing permissions and limitations
under the License.
*/

#pragma once


#include <io.h>
#include <magic.h>

void printcow(void);

char upperbubble='\\';
char lowerbubble='\\';

unsigned int counter;
unsigned int argscharcount=0;
unsigned int nextarg;
unsigned short skiparg;
unsigned short thought=0;

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