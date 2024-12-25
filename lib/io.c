/*
Licensed to the Apache Software Foundation (ASF) under one
or more contributor license agreements.  See the LICENSE file
distributed with this work for additional information
regarding copyright ownership.  The ASF licenses this file
to you under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance
with the License.  You may obtain a copy of the License at

  http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing,
software distributed under the License is distributed on an
"AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
KIND, either express or implied.  See the License for the
specific language governing permissions and limitations
under the License.
*/

#include <io.h>
#include <conv.h>
#include <stddef.h>
#include <drivers/display.h>
#include <drivers/keyboard.h>
#include <drivers/display_color.h>

// print string to cursor with color
void cputs(char* text, char color) {
	while (*text) {
		cputc(*text, color);
		++text;
	}
}

// print string to cursor with default color
void puts(char* text) {
  cputs(text, TRANSPARENT);
}

void puti(int number) {
  char output[12];
  int_to_str(output, number);
  puts(output);
}

void putu(uint number) {
  char output[12];
  uint_to_str(output, number);
  puts(output);
}

void putu32(uint32_t number) {
  char output[12];
  uint32_to_str(output, number);
  puts(output);
}

void puthex(uint32_t number) {
  char* output;
  uint32_to_hex(output, number);
  puts(output);
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
      putc(input);
      output[i] = input;
      ++i;
    }
  }
  putc('\n');
}

void __stack_chk_fail() {}