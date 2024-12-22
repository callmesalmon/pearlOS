#include <io.h>
#include <kernel/kmsg.h>
#include <drivers/display_color.h>


void kinfo(char* msg)
{
  puts("[INFO] ");
  puts(msg);
}

void kwarning(char* msg)
{
  puts("[WARNING] ");
  puts(msg);
}

void kerror(char* msg)
{
  puts("[ERROR] ");
  puts(msg);
}

void kpanic(char* msg)
{
  cputs("[PANIC] ", RED_ON_BLACK);
  cputs(msg, RED_ON_BLACK);
  while (1) {} /* Infinite loop */
}
