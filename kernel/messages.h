/*
 * Copyright (c) Salmon 2025 under the ANTIFA-MIT license.
 * If your copy of this program doesn't include the license, it is
 * available to read at: 
 *
 *     https://github.com/jamiebuilds/anti-fascist-mit-license
 */

#pragma once

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
#define KERNEL_INFO_SHELL_UNKNOWN_COMMAND   "Unknown command\n"
#define KERNEL_PANIC_MEMORY_INDEX_FULL      "Kernel index is full!\nCAUSE: Too many kmalloc() calls...\n"
#define KERNEL_PANIC_MEMORY_FULL            "Kernel memory is full!\nCAUSE: The system ran out of RAM..."
#define FIRMWARE_ERROR_ISR_EXCEPTION        "(ERROR) Recieved ISR exception: "
#define FIRMWARE_ERROR_SMBIOS_ENTRY_MISSING "(ERROR) Recieved exception: Couldn't find an SMBIOS entry...\n"