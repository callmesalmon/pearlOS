#include "../../intf/print.h"

void __main() {
    printClear();
    printSetColor(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    printStr(
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
