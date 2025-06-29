/* 
 * Copyright (c) Salmon 2025 under the Hippocratic 3.0 license.
 * If your copy of this program doesn't include the license, it is
 * available to read at:
 * 
 *     <https://firstdonoharm.dev/version/3/0/core.txt>
 */

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