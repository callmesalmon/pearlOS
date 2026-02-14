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