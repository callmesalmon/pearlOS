#include <io.h>
#include <string.h>

#include "../mem.h"
#include "../../fs/fscore.h"

void ksh_write_to_file()
{
  puts("> ");
  char* filename = (char*) kmalloc(256);
  strcls(filename);
  scan(filename);

  char* data = (char*) kmalloc(256);
  strcls(data);
  puts("> ");
  scan(data);
  stradd(data, "\n");

  file_clean(filename);
  int response = file_writes(filename, data);
  if (response == FILE_NOT_FOUND)
  {
    puts("File not found!\n");
  }

  kfree(filename);
  kfree(data);
}
