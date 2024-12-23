#include <stddef.h>
#include <rand.h>
#include <mem.h>

#include <kernel/config.h>
#include <kernel/kmsg.h>
#include <kernel/ksh.h>

#include <cpu/smbios.h>
#include <fs/fscore.h>
#include <drivers/keyboard.h>

static bool kernel_running;

int main() {
	/* init */
	kinfo(KERNEL_INFO_ENTERED);
	kinfo(KERNEL_INFO_INIT_START);
	kernel_running = true;
	display_theme(DEFAULT_THEME);
	memory_init();
	keyboard_init();
	smbios_init();
	display_init();
	fsinit();
	rand_init();
	kinfo(KERNEL_INFO_INIT_DONE);
	kinfo(KERNEL_INFO_WELCOME);

	/* main */
	#include "debug.h" /* this file is created by "./config.sh" */
	KERNEL_STARTUP;
	while (kernel_running) {
		KERNEL_UPDATE
	}
    return 0;
}