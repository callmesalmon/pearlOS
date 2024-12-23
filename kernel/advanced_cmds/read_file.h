#pragma once

#include <io.h>
#include <mem.h>

#include <fs/fscore.h>

void ksh_read_file() {
  char* filename = (char*) kmalloc(256);
  puts("> ");
  scan(filename);

  char* content = (char*) kmalloc(file_size(filename));
  int response = file_read(filename, content);

  if (response == FILE_NOT_FOUND) {
    puts("File not found\n");
  }
  puts(content);

  kfree(filename);
  kfree(content);
}