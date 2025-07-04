/*
 * Copyright (c) Salmon 2025 under the Hippocratic 3.0 license.
 * If your copy of this program doesn't include the license, it is
 * available to read at:
 * 
 *     <https://firstdonoharm.dev/version/3/0/core.txt>
 */

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