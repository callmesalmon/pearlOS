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
#include <mem.h>

#include <kernel/ksh.h>
#include <drivers/display.h>
#include <cpu/smbios.h>

void ksh_pearlfetch() {
  putc('\n');
  puts(
  "           _.-''|''-._\n"
  "        .-'     |     `-.\n"
  "      .'\\       |       /`.\n"
  "    .'   \\      |      /   `.\n"
  "    \\     \\     |     /     /\n"
  "     `\\    \\    |    /    /'\n"
  "       `\\   \\   |   /   /'\n"
  "         `\\  \\  |  /  /'\n"
  "        _.-`\\ \\ | / /'-._\n"
  "       {_____`\\\\|//'_____}\n"
  "               `-'\n"
  );

  puts("OS: pearlOS ");
  puts(OS_VERSION);
  putc('\n');

  puts("BIOS name: ");
  puts(smbios_get_bios_name());
  putc('\n');

  puts("BIOS version:");
  puts(smbios_get_bios_version());
  putc('\n');

  puts("Memory: ");
  putu32(memory_usage());
  puts("/");
  putu32(memory_total());
  putc('\n');

  puts("Theme: ");
  puts(theme);
  putc('\n');
}

/*14 x 28
██████████████████  ████████   eliss@pc
██████████████████  ████████   ------------
██████████████████  ████████   OS: Manjaro Linux x86_64
██████████████████  ████████   Host: MS-7788 1.0
████████            ████████   Kernel: 5.10.34-1-MANJARO
████████  ████████  ████████   Uptime: 2 hours, 43 mins
████████  ████████  ████████   Packages: 1388 (pacman), 7 (snap)
████████  ████████  ████████   Shell: bash 5.1.4
████████  ████████  ████████   Resolution: 1920x1080, 1280x1024
████████  ████████  ████████   DE: Plasma 5.21.4
████████  ████████  ████████   WM: KWin
████████  ████████  ████████   WM Theme: Sweet-Mars-transparent
████████  ████████  ████████   Theme: Aritim-Dark_DEV [Plasma], Breeze [GTK2/3]
████████  ████████  ████████ */