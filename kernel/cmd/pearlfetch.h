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

#include <kernel/ksh.h>
#include <drivers/display.h>
#include <cpu/smbios.h>

/* I did NOT make this art btw */
#define PEARLFETCH_ART \
  "           _.-''|''-._         \n" \
  "        .-'     |     `-.      \n" \
  "      .'\\       |       /`.   \n" \
  "    .'   \\      |      /   `. \n" \
  "    \\     \\     |     /     /\n" \
  "     `\\    \\    |    /    /' \n" \
  "       `\\   \\   |   /   /'   \n" \
  "         `\\  \\  |  /  /'     \n" \
  "        _.-`\\ \\ | / /'-._    \n" \
  "       {_____`\\\\|//'_____}   \n" \
  "               `-'             \n"


void ksh_pearlfetch() {
  printf(PEARLFETCH_ART);
  printf("OS: pearlOS %s\n", OS_VERSION);

  printf("BIOS name: %s\n", smbios_get_bios_name());
  printf("BIOS version: %s\n", smbios_get_bios_version());

  printf("Memory: %d/%d\n", memory_usage(), memory_total());
  printf("Theme: %s\n", theme);
}