#pragma once

#include <io.h>

#include "../../drivers/display.h"
#include "../mem.h"
#include "../ksh.h"
#include "../../cpu/smbios.h"

void ksh_pearlfetch()
{
  kprintc('\n');
  kprints(
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

  kprints("OS: pearlOS ");
  kprints(OS_VERSION);
  kprintc('\n');

  kprints("BIOS name: ");
  kprints(smbios_get_bios_name());
  kprintc('\n');

  kprints("BIOS version:");
  kprints(smbios_get_bios_version());
  kprintc('\n');

  kprints("Memory: ");
  kprintu32(memory_usage());
  kprints("/");
  kprintu32(memory_total());
  kprintc('\n');

  kprints("Theme: ");
  kprints(theme);
  kprintc('\n');
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
