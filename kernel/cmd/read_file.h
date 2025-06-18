/* 
 * Copyright (c) Salmon 2025 under the Hippocratic 3.0 license.
 * If your copy of this program doesn't include the license, it is
 * available to read at:
 * 
 *     <https://firstdonoharm.dev/version/3/0/core.txt>
 */

#pragma once

#include <io.h>
#include <mem.h>

#include <fs/core.h>

void ksh_read_file() {
  char* filename = (char*) kmalloc(256);
  printk("> ");
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