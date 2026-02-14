#pragma once

#include <io.h>
#include <drivers/display.h>
#include <fs/core.h>

void ksh_list_files() {
  char *name;
  for (int i = 0; i < file_count(); ++i) {
    name = file_get_name(i);
    if (name != (char *)FILE_NOT_FOUND) {
      printf("%s\n", name);
    }
  }
}