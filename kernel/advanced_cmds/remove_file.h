#include <io.h>

#include "../../fs/fscore.h"

void ksh_remove_file()
{
  puts("> ");
  char file_to_remove[255];
  scan(file_to_remove);

  if (file_remove(file_to_remove) == FILE_NOT_FOUND)
  {
    puts("File not found!");
    putc('\n');
  }
}
