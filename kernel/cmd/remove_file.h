#pragma once

#include <io.h>

#include <fs/core.h>
#include <drivers/display.h>


#include <kernel/config.h>

void ksh_remove_file() {
  printf("%s ", KSH_PROMPT2);
  char file_to_remove[255];
  scan(file_to_remove);

  if (file_remove(file_to_remove) == FILE_NOT_FOUND) {
    printf("File not found!\n");
  }
}