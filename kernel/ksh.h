#pragma once

#include "../lib/type.h"
#include "../lib/string.h"
#include "../drivers/display_color.h"
#include "mem.h"
#include "kmsg.h"
#include "io.h"
#include "../cpu/smbios.h"
#include "version.h"

char *theme;

#include "advanced_cmds/pearlfetch.h"
#include "advanced_cmds/list_files.h"
#include "advanced_cmds/read_file.h"
#include "advanced_cmds/write_to_file.h"
#include "advanced_cmds/make_file.h"
#include "advanced_cmds/fortune.h"
#include "advanced_cmds/remove_file.h"
#include "advanced_cmds/echo.h"
#include "advanced_cmds/help.h"
#include "advanced_cmds/calc.h"
#include "advanced_cmds/panic.h"

#define KSH_OK           0x0
#define KSH_EXIT         0x1
#define KSH_PROMPT       "$ "
#define KSH_INPUT_BUFFER 31

byte ksh_interpret(char* command)
{
  if (!*command)
  {
    return KSH_OK;
  }
  else if (strcmp(command, "help"))
  {
    help_init();
  }
  else if (strcmp(command, "echo"))
  {
    ksh_echo();
  }
  else if (strcmp(command, "wipe"))
  {
    display_clear();
  }
  else if (strcmp(command, "version"))
  {
    kprints("pearlOS\n");
    kprints("Version: ");
    kprints(OS_VERSION);
    kprintc('\n');
  }
  else if (strcmp(command, "memstat"))
  {
    kprints("Memory usage:");
    kprints("\ntotal: ");
    kprintu32(memory_usage());
    kprints("\neffective: ");
    kprintu32(memory_usage_effective());
    kprintc('\n');
  }
  else if (strcmp(command, "theme-light"))
  {
    display_theme(BLACK_ON_WHITE);
    theme = "Generic light";
  }
  else if (strcmp(command, "theme-dark"))
  {
    display_theme(WHITE_ON_BLACK);
    theme = "Generic dark";
  }
  else if (strcmp(command, "hacker"))
  {
    display_theme(GREEN_ON_BLACK);
    theme = "Hacker >:D";
    kprints_color("You are a hacker now! >:D\n", RED_ON_BLACK);
  }
  else if (strcmp(command, "exit"))
  {
    display_clear();
    return KSH_EXIT;
  }
  else if (strcmp(command, "fortune"))
  {
    ksh_fortune();
  }
  else if (strcmp(command, "calc"))
  {
    calc_init();
  }
  else if (strcmp(command, "memtest"))
  {
      kmalloc(1);
  }
  else if (strcmp(command, "theme-pascal"))
  {
    display_theme(DEFAULT_THEME);
    theme = "Generic pascal";
  }
  else if (strcmp(command, "pearlfetch"))
  {
    ksh_pearlfetch();
  }
  else if (strcmp(command, "ls"))
  {
    ksh_list_files();
  }
  else if (strcmp(command, "mk"))
  {
    ksh_make_file();
  }
  else if (strcmp(command, "rm"))
  {
    ksh_remove_file();
  }
  else if (strcmp(command, "cat"))
  {
    ksh_read_file();
  }
  else if (strcmp(command, "to"))
  {
    ksh_write_to_file();
  }
  else if (strcmp(command, "random"))
  {
    kprintu(rand() % 100);  // random number between 0-100
    kprintc('\n');
  }
  else if (strcmp(command, "panic"))
  {
    usrpanic();
  }
  else
  {
    kprints(KERNEL_INFO_SHELL_UNKNOWN_COMMAND);
  }
  return KSH_OK;
}

void ksh_start()
{
  theme = "Hacker >:D";
  char c [KSH_INPUT_BUFFER];
  for (uint i = 0; i < KSH_INPUT_BUFFER; ++i)
  {
    c[i] = (char) 0;
  }
  byte response;
  kprints(KERNEL_INFO_SHELL_WELCOME);
  kprints(KERNEL_INFO_MANUAL_HELP);
  while (true)
  {
    kprints(KSH_PROMPT);
    kinputs(c);
    response = ksh_interpret(c);
    if (response == KSH_EXIT)
    {
      break;
    }
    strcls(c);
  }
}
