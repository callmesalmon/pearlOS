#include "../io.h"
#include "../mem.h"
#include "../../fs/fscore.h"
#include "../../lib/string.h"

void ksh_write_to_file()
{
  kprintc('>');
  char* filename = (char*) kmalloc(256);
  strcls(filename);
  kinputs(filename);

  char* data = (char*) kmalloc(256);
  strcls(data);
  kprintc('>');
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
