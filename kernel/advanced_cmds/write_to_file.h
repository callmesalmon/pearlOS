#include <io.h>
#include <string.h>

#include "../mem.h"
#include "../../fs/fscore.h"

void ksh_write_to_file()
{
  kprints("> ");
  char* filename = (char*) kmalloc(256);
  strcls(filename);
  kinputs(filename);

  char* data = (char*) kmalloc(256);
  strcls(data);
  kprints("> ");
  kinputs(data);
  stradd(data, "\n");

  file_clean(filename);
  int response = file_writes(filename, data);
  if (response == FILE_NOT_FOUND)
  {
    kprints("File not found!\n");
  }

  kfree(filename);
  kfree(data);
}
