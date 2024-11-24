#pragma once

#include <stddef.h>

#include "../kernel/kmsg.h"

char* smbios_get_bios_version();
char* smbios_get_bios_name();
void smbios_init();
