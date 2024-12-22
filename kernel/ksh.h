#pragma once

#include <stddef.h>
#include <io.h>
#include <string.h>
#include <magic.h>
#include <mem.h>

#include <kernel/kmsg.h>
#include <kernel/version.h>
#include <kernel/config.h>

#include <cpu/smbios.h>
#include <drivers/display_color.h>

char *theme;

#include <kernel/advanced_cmds/pearlfetch.h>
#include <kernel/advanced_cmds/list_files.h>
#include <kernel/advanced_cmds/read_file.h>
#include <kernel/advanced_cmds/write_to_file.h>
#include <kernel/advanced_cmds/make_file.h>
#include <kernel/advanced_cmds/fortune.h>
#include <kernel/advanced_cmds/remove_file.h>
#include <kernel/advanced_cmds/echo.h>
#include <kernel/advanced_cmds/help.h>
#include <kernel/advanced_cmds/calc.h>
#include <kernel/advanced_cmds/panic.h>
#include <kernel/advanced_cmds/alloc.h>
#include <kernel/advanced_cmds/loop.h>
#include <kernel/advanced_cmds/memstat.h>

#define KSH_OK           0x0
#define KSH_EXIT         0x1
#define KSH_INPUT_BUFFER 31

byte ksh_interpret(char* command)
{
  if (!*command)
  {
    return KSH_OK;
  }
  else if (command[0] == KSH_COMMENT)
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
  else if (strcmp(command, "loop"))
  {
    ksh_loop();
  }
  else if (strcmp(command, "wipe"))
  {
    display_clear();
  }
  else if (strcmp(command, "version"))
  {
    puts("pearlOS\n");
    puts("Version: ");
    puts(OS_VERSION);
    putc('\n');
  }
  else if (strcmp(command, "memstat"))
  {
    ksh_memstat();
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
    cputs("You are a hacker now! >:D\n", RED_ON_BLACK);
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
    ksh_calc();
  }
  else if (strcmp(command, "memalloc"))
  {
    ksh_alloc();
  }
  else if (strcmp(command, "theme-pascal"))
  {
    display_theme(WHITE_ON_BLUE);
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
    putu(rand() % 100);  // random number between 0-100
    putc('\n');
  }
  else if (strcmp(command, "panic"))
  {
    usrpanic();
  }
  else
  {
    puts(KERNEL_INFO_SHELL_UNKNOWN_COMMAND);
  }
  return KSH_OK;
}

void ksh_start()
{
  theme = "Hacker >:D";

  char c[KSH_INPUT_BUFFER];
  for (uint i = 0; i < KSH_INPUT_BUFFER; ++i)
  {
    c[i] = (char) 0;
  }

  byte response;

  puts(KERNEL_INFO_SHELL_WELCOME);
  puts(KERNEL_INFO_MANUAL_HELP);

  while (true)
  {
    puts(KSH_PROMPT " ");
    scan(c);
    response = ksh_interpret(c);

    if (response == KSH_EXIT)
    {
      break;
    }

    strcls(c);
  }
}
