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

	/* Init messages */
	kinfo(KERNEL_INFO_ENTERED);
	kinfo(KERNEL_INFO_INIT_START);

    /* ISR and SMBIOS */
    isr_install();
    smbios_init();

    /* Display configured default theme */
    display_theme(DEFAULT_THEME);

    /* Initalize memory, input and display */
	memory_init();
	keyboard_init();
	display_init();
	
    /* Make filesystem and finish the initialization
     * by initializing the "rand" function. */
    mkfs();
	rand_init();

    /* End of init messages */
	kinfo(KERNEL_INFO_INIT_DONE);
	kinfo(KERNEL_INFO_WELCOME);

	/* Debug */
    #include "debug.h" /* this file is created by "./configure" */
    #ifdef DBG_MAIN
        DBG_MAIN;
    #endif

    /* Start the OS */
    KERNEL_STARTUP;
	
    return 0;
}

#ifdef __cplusplus
}
#endif