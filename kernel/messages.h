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
#define KERNEL_INFO_SHELL_UNKNOWN_COMMAND "Unknown command\n"               // ksh input unkown
#define KERNEL_PANIC_MEMORY_INDEX_FULL    "Kernel index is full!\nCAUSE: Too many kmalloc() calls...\n" // when memory_index is full
#define KERNEL_PANIC_MEMORY_FULL            "Kernel memory is full!\nCAUSE: The system ran out of RAM..."
#define FIRMWARE_ERROR_ISR_EXCEPTION        "isr expection: "
#define FIRMWARE_ERROR_SMBIOS_ENRTY_MISSING "Could not find SMBIOS entry\n"
