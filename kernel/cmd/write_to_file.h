/*
 * Copyright (c) Salmon 2025 under the ANTIFA-MIT license.
 * If your copy of this program doesn't include the license, it is
 * available to read at: 
 *
 *     https://github.com/jamiebuilds/anti-fascist-mit-license
 */

#pragma once

#include <io.h>
#include <string.h>
#include <mem.h>

#include <fs/core.h>

void ksh_write_to_file() {
  printf("> ");
  char* filename = (char*) kmalloc(256);
  strcls(filename);
  scan(filename);

  char* data = (char*) kmalloc(256);
  strcls(data);
  printf("> ");
  scan(data);
  stradd(data, "\n");

  file_clean(filename);
  int response = file_writes(filename, data);
  if (response == FILE_NOT_FOUND) {
    printf("File not found!\n");
  }

  kfree(filename);
  kfree(data);
}