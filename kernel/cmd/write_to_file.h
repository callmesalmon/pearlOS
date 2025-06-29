/* 
 * Copyright (c) Salmon 2025 under the Hippocratic 3.0 license.
 * If your copy of this program doesn't include the license, it is
 * available to read at:
 * 
 *     <https://firstdonoharm.dev/version/3/0/core.txt>
 */

#pragma once

#include <io.h>
#include <string.h>
#include <mem.h>

#include <fs/core.h>

#include <kernel/config.h>

void ksh_write_to_file() {
  printf("%s ", KSH_PROMPT2);
  char* filename = (char*) kmalloc(256);
  strcls(filename);
  scan(filename);

  char* data = (char*) kmalloc(256);
  strcls(data);
  printf("%s ", KSH_PROMPT2);
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