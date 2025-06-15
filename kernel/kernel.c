/*
 * Copyright (c) Salmon 2025 under the ANTIFA-MIT license.
 * If your copy of this program doesn't include the license, it is
 * available to read at: 
 *
 *     https://github.com/jamiebuilds/anti-fascist-mit-license
 */

#ifdef __cplusplus
extern "C" {
#endif

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
	mkfs();
	rand_init();

	kinfo(KERNEL_INFO_INIT_DONE);
	kinfo(KERNEL_INFO_WELCOME);

	/* Main */
    #include "debug.h" /* this file is created by "./configure" */
    #ifdef DBG_MAIN
        DBG_MAIN;
    #endif

    KERNEL_STARTUP;
	
    return 0;
}

#ifdef __cplusplus
}
#endif