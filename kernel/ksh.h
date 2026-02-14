#pragma once

/* Includes */
#include <stddef.h>
#include <io.h>
#include <string.h>
#include <magic.h>
#include <mem.h>

#include <kernel/kmsg.h>
#include <kernel/version.h>
#include <kernel/config.h>

#include <cpu/smbios.h>
#include <drivers/display_color.h>
#include <drivers/display.h>

/* Defines */
#define KSH_OK           0x0
#define KSH_EXIT         0x1
#define KSH_INPUT_BUFFER 31

/* Functions */
byte ksh_interpret(char* command);
void ksh_start();