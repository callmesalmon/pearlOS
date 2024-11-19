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
             .',;::::;,'.                eliss@pc
         .';:cccccccccccc:;,.            ------------
      .;cccccccccccccccccccccc;.         OS: Fedora Linux 40 x86_64
    .:cccccccccccccccccccccccccc:.       Kernel: 5.15.167.4.x86_64
  .;ccccccccccccc;.:dddl:.;ccccccc;.     Uptime: 22 mins
 .:ccccccccccccc;OWMKOOXMWd;ccccccc:.    Shell: bash 5.2.26
.:ccccccccccccc;KMMc;cc;xMMc;ccccccc:.   Theme: Adwaita [GTK3]
,cccccccccccccc;MMM.;cc;;WW:;cccccccc,   Icons: Adwaita [GTK3]
:cccccccccccccc;MMM.;cccccccccccccccc:   Terminal: gnome-terminal
:ccccccc;oxOOOo;MMM0OOk.;cccccccccccc:   CPU: Intel Celeron N4500 (2) @ 1.113GHz
cccccc;0MMKxdd:;MMMkddc.;cccccccccccc;   Memory: 432MiB / 1891MiB
ccccc;XM0';cccc;MMM.;cccccccccccccccc'
ccccc;MMo;ccccc;MMW.;ccccccccccccccc;
ccccc;0MNc.ccc.xMMd;ccccccccccccccc;
cccccc;dNMWXXXWM0:;cccccccccccccc:,
cccccccc;.:odl:.;cccccccccccccc:,.
:cccccccccccccccccccccccccccc:'.
.:cccccccccccccccccccccc:;,..
  '::cccccccccccccc::;,.
*/
