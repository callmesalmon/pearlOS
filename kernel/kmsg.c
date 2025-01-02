/*
Copyright 2025 Elis Staaf

Licensed to the Apache Software Foundation (ASF) under one
or more contributor license agreements.  See the LICENSE file
distributed with this work for additional information
regarding copyright ownership.  The ASF licenses this file
to you under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance
with the License.  You may obtain a copy of the License at

  http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing,
software distributed under the License is distributed on an
"AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
KIND, either express or implied.  See the License for the
specific language governing permissions and limitations
under the License.
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