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

#include <stddef.h>
#include <rand.h>
#include <mem.h>

#include <kernel/config.h>
#include <kernel/kmsg.h>
#include <kernel/ksh.h>

#include <cpu/smbios.h>
#include <cpu/isr.h>
#include <fs/core.h>
#include <drivers/keyboard.h>

static bool kernel_running;

int kmain() {
	/* Init */
	kinfo(KERNEL_INFO_ENTERED);
	kinfo(KERNEL_INFO_INIT_START);
	
    display_theme(DEFAULT_THEME);
	memory_init();
    isr_install();
	keyboard_init();
	smbios_init();
	display_init();
	fsinit();
	rand_init();

	kinfo(KERNEL_INFO_INIT_DONE);
	kinfo(KERNEL_INFO_WELCOME);

	/* Main */
    #include "debug.h" /* this file is created by "./config.sh" */
    #ifdef DBG_MAIN
        DBG_MAIN;
    #endif
	
    KERNEL_STARTUP;
	
    while (true) {
        KERNEL_UPDATE;
	}
    return 0;
}