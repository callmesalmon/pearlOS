/*
Copyright 2025 Elis Staaf

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

/* * * * * * * * * * * * * * * * * * *
 *     The second commandment.       *
 * * * * * * * * * * * * * * * * * * *
 * When defining a new message       *
 * macro, follow the following       *
 * rules:                            *
 *                                   *
 * - Thou shall follow the syntax    *
 *   of this template:               *
 *   "LABEL_TYPE_MESSAGE"            *
 * - Thou shall try to only use      *
 *   the following labels:           *
 *   KERNEL,                         *
 *   BOOT,                           *
 *   DRIVER_DISPLAY,                 *
 *   DRIVER_PORT,                    *
 *   FIRMWARE,                       *
 * - Thou shall *only* use the       *
 *   following types:                *
 *   INFO    -> regular information  *
 *   WARNING -> possible problem     *
 *   ERROR   -> non-fatal problem    *
 *   PANIC   -> fatal problem        * 
 * * * * * * * * * * * * * * * * * * */

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
#define FIRMWARE_ERROR_ISR_EXCEPTION        "ISR Exception: "
#define FIRMWARE_ERROR_SMBIOS_ENTRY_MISSING "Couldn't find an SMBIOS entry...\n"