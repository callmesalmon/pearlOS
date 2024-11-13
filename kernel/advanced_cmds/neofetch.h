#pragma once
#include "../../drivers/display.h"
#include "../io.h"
#include "../mem.h"
#include "../ksh.h"
#include "../../cpu/smbios.h"

void ksh_neofetch()
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
  set_cursor_position(23, 8);
  kprints("OS: pearlOS ");
  kprints(OS_VERSION);
  set_cursor_position(23, 9);
  kprints("BIOS name: ");
  kprints(smbios_get_bios_name());
  set_cursor_position(23, 10);
  kprints("BIOS version:");
  kprints(smbios_get_bios_version());
  set_cursor_position(23, 11);
  kprints("Memory: ");
  kprintu32(memory_usage());
  kprints("/");
  kprintu32(memory_total());
  set_cursor_position(23, 12);
  kprints("Theme: ");
  kprints(theme);
  set_cursor_position(0, 24);
  kprintc('\n');
}
