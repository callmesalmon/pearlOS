#pragma once

/* Includes */
#include <stddef.h>
#include <kernel/kmsg.h>

/* Functions */
char* smbios_get_bios_version();
char* smbios_get_bios_name();
void smbios_init();