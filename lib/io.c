#include <io.h>
#include <conv.h>
#include <types.h>
#include <drivers/display.h>
#include <drivers/keyboard.h>
#include <drivers/display_color.h>

/* Print string to cursor with color */
void cprintk(char* text, char color) {
	while (*text) {
		cprintc(*text, color);
		++text;
	}
}

/* Print string to cursor with default color */
void printk(char* text) {
  cprintk(text, TRANSPARENT);
}

void printi(int number) {
  char output[12];
  int_to_str(output, number);
  printk(output);
}

void printu(uint number) {
  char output[12];
  uint_to_str(output, number);
  printk(output);
}

void printu32(uint32_t number) {
  char output[12];
  uint32_to_str(output, number);
  printk(output);
}

void printhex(uint32_t number) {
  char* output;
  uint32_to_hex(output, number);
  printk(output);
}

void println(char* text) {
    printk(text);
    printnl();
}

void cprintln(char* text, char color) {
    cprintk(text, color);
    printnl();
}

void scan(char* output) {
  uint32_t i = 0;
  char input = 0;
  while (input != '\n') {
    input = scanc();
    if (input == '\b' && i > 0) {
      --i;
      display_deletec();
    }
    else if (input == '\n') output[i] = 0;
    else if (input != '\b') {
      printc(input);
      output[i] = input;
      ++i;
    }
  }
  printnl();
}

void __stack_chk_fail() {}