#include "../../intf/print.h"

void kernel_main() {
    print_clear();
    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    print_str(
    "  /$$$$$$   /$$$$$$  /$$      \n"
    " /$$__  $$ /$$__  $$| $$      \n"
    "| $$  \\ $$| $$  \\__/| $$   /$$\n"
    "| $$  | $$|  $$$$$$ | $$  /$$/\n"
    "| $$  | $$ \\____  $$| $$$$$$/ \n"
    "| $$  | $$ /$$  \\ $$| $$_  $$ \n"
    "|  $$$$$$/|  $$$$$$/| $$ \\  $$\n"
    "\\______/  \\______/ |__/  \\__/ \n"
    "\n"
    "Hello World! Welcome to the small OSk\n"
    "kernel! It... Works? Yeah! So enjoy!\n"
    );
}
