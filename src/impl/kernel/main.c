#include "../../intf/print.h"

#define VERSION "v1.0.0"

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
    VERSION "\n\n"
    "Hello World! You are currently running the\n"
    "\"OSk\" kernel, an open-source kernel made\n"
    "and currently maintained by Elis Staaf.\n"
    "Thank you for using the OSk!!!"
    );
}
