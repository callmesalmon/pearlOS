#pragma once
#include "../../drivers/display.h"
#include "../io.h"
#include "../mem.h"
#include "../ksh.h"
#include "../../cpu/smbios.h"

void ksh_pearlfetch()
{
  kprintc('\n');
  kprints(
"                                         /$$  /$$$$$$   /$$$$$$ \n"
"                                        | $$ /$$__  $$ /$$__  $$\n"
"  /$$$$$$   /$$$$$$   /$$$$$$   /$$$$$$ | $$| $$  \\ $$| $$  \\__/\n"
" /$$__  $$ /$$__  $$ |____  $$ /$$__  $$| $$| $$  | $$|  $$$$$$ \n"
"| $$  \\ $$| $$$$$$$$  /$$$$$$$| $$  \\__/| $$| $$  | $$ \\____  $$\n"
"| $$  | $$| $$_____/ /$$__  $$| $$      | $$| $$  | $$ /$$  \\ $$\n"
"| $$$$$$$/|  $$$$$$$|  $$$$$$$| $$      | $$|  $$$$$$/|  $$$$$$/\n"
"| $$____/  \\_______/ \\_______/|__/      |__/ \\______/   \\______/ \n"
"| $$                                                            \n"
"| $$                                                            \n"
"|__/                                                            \n"
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
