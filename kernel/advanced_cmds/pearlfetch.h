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