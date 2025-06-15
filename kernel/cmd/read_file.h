/*
 * Copyright (c) Salmon 2025 under the ANTIFA-MIT license.
 * If your copy of this program doesn't include the license, it is
 * available to read at: 
 *
 *     https://github.com/jamiebuilds/anti-fascist-mit-license
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