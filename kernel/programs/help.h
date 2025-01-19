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

int ksh_help() {
    println("help           prints this message");
    println("echo           prints \"X\" to the display");
    println("wipe           clears screen");
    println("loop           loop command \"X\" times");
    println("exit           exit kernel shell");
    println("fortune        digital fortune cookie");
    println("version        get kernel version");
    println("pearlfetch     show info about your system");
    println("calc           simple calculator");
    println("theme-light    changes the theme to a light theme");
    println("theme-dark     changes the theme to a dark theme");
    println("theme-pascal   changes the theme to pascal");
    println("hacker         changes the theme back to hacker >:D");
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

    return 0;
}