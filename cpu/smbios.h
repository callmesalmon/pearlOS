#pragma once

#include "../lib/type.h"
#include "../kernel/kmsg.h"

char* smbios_get_bios_version();
char* smbios_get_bios_name();
void smbios_init();
