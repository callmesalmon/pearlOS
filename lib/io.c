#include "io.h"
#include "conv.h"

// print string to cursor with color
void cputs(char* text, char color)
{
	while (*text)
	{
		cputc(*text, color);
		++text;
	}
}

// print string to cursor with default color
void puts(char* text)
{
  cputs(text, TRANSPARENT);
}

void puti(int number)
{
  char output[12];
  int_to_str(output, number);
  puts(output);
}

void putu(uint number)
{
  char output[12];
  uint_to_str(output, number);
  puts(output);
}

void putu32(uint32_t number)
{
  char output[12];
  uint32_to_str(output, number);
  puts(output);
}

void puthex(uint32_t number)
{
  char* output;
  uint32_to_hex(output, number);
  puts(output);
}

void scan(char* output)
{
  uint32_t i = 0;
  char input = 0;
  while (input != '\n')
  {
    input = scanc();
    if (input == '\b' && i > 0)
    {
      --i;
      display_deletec();
    }
    else if (input == '\n') output[i] = 0;
    else if (input != '\b')
    {
      putc(input);
      output[i] = input;
      ++i;
    }
  }
  putc('\n');
}

void __stack_chk_fail() {}
