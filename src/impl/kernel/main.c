/* **OSk: Operating System kernel**
 * Main file for OSk. Or, well, this
 * files "__main()" function is called
 * at startup by ../x86_64/boot/main.asm,
 * So this runs on startup! Good to know.
 */

#include "../../intf/print.h"

#define VERSION "1.0.0"

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
    "Version " VERSION "\n\n"
    "Hello World! You are currently running the\n"
    "\"OSk\" kernel, an open-source kernel made\n"
    "and currently maintained by Elis Staaf.\n"
    "Thank you for using the OSk!!!"
    );
}
