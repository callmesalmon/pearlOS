/*
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