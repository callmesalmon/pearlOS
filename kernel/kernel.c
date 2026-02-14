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

#include <multiboot.h>

/* Forward declarations */
void memory_init(void);
void keyboard_init(void);
void display_init(void);
void display_theme(char color);
void mkfs(void);
void rand_init(void);
void isr_install(void);
void smbios_init(void);

/* Multiboot information pointer */
struct multiboot_info *mb_info;

int kmain(unsigned long magic, unsigned long addr) {
    /* Check if we were loaded by a Multiboot-compliant boot loader */
    if (magic != MULTIBOOT_BOOTLOADER_MAGIC) {
        /* Not loaded by a compliant bootloader */
        return -1;
    }

    /* Save the multiboot info structure */
    mb_info = (struct multiboot_info *)addr;

    /* Init messages */
    kinfo(KERNEL_INFO_ENTERED);
    kinfo(KERNEL_INFO_INIT_START);

    /* ISR and SMBIOS */
    isr_install();
    smbios_init();

    /* Display configured default theme */
    display_theme((char)DEFAULT_THEME);

    /* Initialize memory, input and display */
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

    /* Start the OS */
    KERNEL_STARTUP;
	
    return 0;
}

#ifdef __cplusplus
}
#endif