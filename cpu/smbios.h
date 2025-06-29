/*
 * Copyright (c) Salmon 2025 under the Hippocratic 3.0 license.
 * If your copy of this program doesn't include the license, it is
 * available to read at:
 * 
 *     <https://firstdonoharm.dev/version/3/0/core.txt>
 */

#pragma once

/* Includes */
#include <stddef.h>
#include <kernel/kmsg.h>

/* Functions */
char* smbios_get_bios_version();
char* smbios_get_bios_name();
void smbios_init();