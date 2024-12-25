/*
Licensed to the Apache Software Foundation (ASF) under one
or more contributor license agreements.  See the LICENSE file
distributed with this work for additional information
regarding copyright ownership.  The ASF licenses this file
to you under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance
with the License.  You may obtain a copy of the License at

  http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing,
software distributed under the License is distributed on an
"AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
KIND, either express or implied.  See the License for the
specific language governing permissions and limitations
under the License.
*/

#pragma once

// message syntax:
// LABEL_TYPE_MESSAGE
// LABELS: KERNEL, BOOT, DRIVER_DISPLAY, DRIVER_PORT...
// TYPES:
// INFO     regular information
// WARNING  possible problem
// ERROR    non-fatal problem
// PANIC    fatal problem
#define INCLUDED_MESSAGES

#define KERNEL_INFO_ENTERED       "Booting...\n"                    // start of main()
#define KERNEL_INFO_INIT_START    "Initializing...\n"               // start of init()
#define KERNEL_INFO_INIT_DONE     "Done!\n"                         // end of init()
#define KERNEL_INFO_WELCOME       "Welcome to pearlOS!\n"           // end of main() startup
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
    // man prompt
#define KERNEL_INFO_SHELL_UNKNOWN_COMMAND "Unknown command\n"               // ksh input unkown
#define KERNEL_PANIC_MEMORY_INDEX_FULL    "Kernel index is full!\nCAUSE: Too many kmalloc() calls...\n" // when memory_index is full
#define KERNEL_PANIC_MEMORY_FULL            "Kernel memory is full!\nCAUSE: The system ran out of RAM..."
#define FIRMWARE_ERROR_ISR_EXCEPTION        "[ISR exception] "
#define FIRMWARE_ERROR_SMBIOS_ENTRY_MISSING "Couldn't find an SMBIOS entry...\n"