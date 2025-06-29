/*
 * Copyright (c) Salmon 2025 under the Hippocratic 3.0 license.
 * If your copy of this program doesn't include the license, it is
 * available to read at:
 * 
 *     <https://firstdonoharm.dev/version/3/0/core.txt>
 */

#include <io.h>
#include <kernel/kmsg.h>
#include <drivers/display_color.h>
#include <drivers/display.h>

/* Info from system and programs */
void kinfo(char* msg) {
  printf("[INFO] %s\n", msg);
}

/* Posibility of problem */
void kwarning(char* msg) {
  printf("[WARNING] %s\n", msg);
}

/* There is a problem */
void kerror(char* msg) {
  printf("[ERROR] %s\n", msg);
}

/* FATAL problem */
void kpanic(char* msg) {
  cprintk("[PANIC] ", RED_ON_BLACK);
  cprintk(msg, RED_ON_BLACK);
  printnl();
  while (1) {} /* Infinite loop */
}