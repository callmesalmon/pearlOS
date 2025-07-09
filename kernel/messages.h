/*
 * Copyright (c) Salmon 2025 under the Hippocratic 3.0 license.
 * If your copy of this program doesn't include the license, it is
 * available to read at:
 * 
 *     <https://firstdonoharm.dev/version/3/0/core.txt>
 */

#pragma once

/* == Message naming conventions ==
 * 1. Structure
 *  LABEL_TYPE_MESSAGE
 *  See (2) for info on labels,
 *      (3) for info on types.
 *  The messages should be clear
 *  and concise.
 * 2. Labels
 *  KERNEL, FIRMWARE,...
 * 3. Types
 *  INFO     regular information
 *  WARNING  possible problem
 *  ERROR    non-fatal problem
 *  PANIC    fatal problem
 */

// These first four functions do not require any "\n" appending,
// as they are called with <kernel/kmsg.h> functions, all of which
// append a "\n" automatically to the text.
#define KERNEL_INFO_ENTERED       "Booting..."
#define KERNEL_INFO_INIT_START    "Initializing..."
#define KERNEL_INFO_INIT_DONE     "Done!"
#define KERNEL_INFO_WELCOME       "Welcome to pearlOS!"
#define KERNEL_INFO_SHELL_WELCOME \
"                                         /$$  /$$$$$$   /$$$$$$ \n" \
"                                        | $$ /$$__  $$ /$$__  $$\n" \
"  /$$$$$$   /$$$$$$   /$$$$$$   /$$$$$$ | $$| $$  \\ $$| $$  \\__/\n" \
" /$$__  $$ /$$__  $$ |____  $$ /$$__  $$| $$| $$  | $$|  $$$$$$ \n" \
"| $$  \\ $$| $$$$$$$$  /$$$$$$$| $$  \\__/| $$| $$  | $$ \\____  $$\n" \
"| $$  | $$| $$_____/ /$$__  $$| $$      | $$| $$  | $$ /$$  \\ $$\n" \
"| $$$$$$$/|  $$$$$$$|  $$$$$$$| $$      | $$|  $$$$$$/|  $$$$$$/\n" \
"| $$____/  \\_______/ \\_______/|__/      |__/ \\______/  \\______/ \n" \
"| $$                                                            \n" \
"| $$                                                            \n" \
"|__/                                                            \n"
#define KERNEL_INFO_MANUAL_HELP "Type \"help\" to open ksh manual.\n"
#define KERNEL_INFO_SHELL_UNKNOWN_COMMAND   "Invalid command!\n"
#define KERNEL_PANIC_MEMORY_INDEX_FULL      "Kernel index is full!\n" \
                                            "CAUSE: Too many kmalloc() calls...\n"
#define KERNEL_PANIC_MEMORY_FULL            "Kernel memory is full!\n" \
                                            "CAUSE: The system ran out of RAM..."
#define FIRMWARE_ERROR_ISR_EXCEPTION        "Recieved ISR exception: "
#define FIRMWARE_ERROR_SMBIOS_ENTRY_MISSING "Recieved exception: Couldn't find an SMBIOS entry...\n"