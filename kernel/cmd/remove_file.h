/*
 * Copyright (c) Salmon 2025 under the ANTIFA-MIT license.
 * If your copy of this program doesn't include the license, it is
 * available to read at: 
 *
 *     https://github.com/jamiebuilds/anti-fascist-mit-license
 */

#pragma once

#include <io.h>

#include <fs/core.h>
#include <drivers/display.h>

void ksh_remove_file() {
  printf("> ");
  char file_to_remove[255];
  scan(file_to_remove);

  if (file_remove(file_to_remove) == FILE_NOT_FOUND) {
    printf("File not found!\n");
  }
}