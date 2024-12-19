#pragma once

#include <io.h>

#include "../../fs/fscore.h"

void ksh_make_file()
{
  puts("> ");
  char* file_to_make = kmalloc(512);
  scan(file_to_make);

  int response = file_make(file_to_make);

  if (response == FILE_ALREADY_EXISTS)
  {
    puts("File already exists!\n");
  }
  else if (response == FILE_NAME_INVALID)
  {
    puts("File name can only contain the following characters:\n");
    puts(FS_FILE_NAME_VALID_CHARS);
    putc('\n');
  }
  else if (response == FILE_COUNT_MAX_EXCEEDED)
  {
    puts("There are too many files!\n");
  }

  kfree(file_to_make);
}
