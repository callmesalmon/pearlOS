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

#pragma once

/* Includes */
#include <stddef.h>
#include <cpu/port.h>
#include <kernel/config.h>

#define VIDEO_MEMORY_OFFSET (uint*) 0xb8000

/* Config */
#define DISPLAY_WIDTH  80
#define DISPLAY_HEIGHT 25

/* Don't touch these */
#define DISPLAY_SCROLL_DEBUG           80
#define DISPLAY_SCROLL_DETECTION_DEBUG -2

/* Colour */
#define TRANSPARENT 0x00
#include <drivers/display_color.h>

/* Code */
#define INIT_VIDEO char* video_memory = (char*) VIDEO_MEMORY_OFFSET

/* Kernel API */
void printc(char character);
void cprintc(char character, char color);
void print(char* text, uint32_t depth);
void cprint(char* text, uint32_t depth, byte color);
void printnl();
void display_clear();
void display_scroll();
void display_theme(char color);
void display_deletec();
void display_init();
void rowcpy(uint dest, uint src);
void set_cursor_position(uint column, uint row);