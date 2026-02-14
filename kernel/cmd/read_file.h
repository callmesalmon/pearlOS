#pragma once

#include <io.h>
#include <mem.h>

#include <kernel/config.h>

#include <fs/core.h>

void ksh_read_file() {
  char* filename = (char*) kmalloc(256);
  printf("%s ", KSH_PROMPT2);
  scan(filename);

  char* content = (char*) kmalloc(file_size(filename));
  int response = file_read(filename, content);

  if (response == FILE_NOT_FOUND) {
    printf("File not found\n");
  }
  printf(content);

  kfree(filename);
  kfree(content);
}