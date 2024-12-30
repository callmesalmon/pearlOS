/*
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
#include <drivers/display.h>
#include <cpu/port.h>

/* Defines */
#define REG_KEYBOARD_DATA 0x60
#define REG_KEYBOARD_CMD  0x64
#define UNPRINTALBE_CHAR  0x0

/* Enumerations */
typedef enum {
  KEY_VOID,
  KEY_DOWN_BACKTICK,
  KEY_DOWN_DASH,
  KEY_DOWN_EQUALS,
  KEY_DOWN_BACKSPACE,
  KEY_DOWN_TAB,
  KEY_DOWN_1,
  KEY_DOWN_2,
  KEY_DOWN_3,
  KEY_DOWN_4,
  KEY_DOWN_5,
  KEY_DOWN_6,
  KEY_DOWN_7,
  KEY_DOWN_8,
  KEY_DOWN_9,
  KEY_DOWN_0,
  KEY_DOWN_Q,
  KEY_DOWN_W,
  KEY_DOWN_E,
  KEY_DOWN_R,
  KEY_DOWN_T,
  KEY_DOWN_Y,
  KEY_DOWN_U,
  KEY_DOWN_I,
  KEY_DOWN_O,
  KEY_DOWN_P,
  KEY_DOWN_LEFT_SQUARE_BRACKET,
  KEY_DOWN_RIGHT_SQUARE_BRACKET,
  KEY_DOWN_ENTER,
  KEY_DOWN_CAPS_LOCK,
  KEY_DOWN_A,
  KEY_DOWN_S,
  KEY_DOWN_D,
  KEY_DOWN_F,
  KEY_DOWN_G,
  KEY_DOWN_H,
  KEY_DOWN_J,
  KEY_DOWN_K,
  KEY_DOWN_L,
  KEY_DOWN_SEMICOLON,
  KEY_DOWN_APOSTROPHE,
  KEY_DOWN_BACKSLASH,
  KEY_DOWN_LEFT_SHIFT,
  KEY_DOWN_SMALLER,
  KEY_DOWN_Z,
  KEY_DOWN_X,
  KEY_DOWN_C,
  KEY_DOWN_V,
  KEY_DOWN_B,
  KEY_DOWN_N,
  KEY_DOWN_M,
  KEY_DOWN_COMMA,
  KEY_DOWN_DOT,
  KEY_DOWN_FRONT_SLASH,
  KEY_DOWN_RIGHT_SHIFT,
  KEY_DOWN_LEFT_CTRL,
  KEY_DOWN_LEFT_SUPER,
  KEY_DOWN_LEFT_ALT,
  KEY_DOWN_SPACE,
  KEY_DOWN_RIGHT_ALT,
  KEY_DOWN_RIGHT_SUPER,
  KEY_DOWN_FN,
  KEY_DOWN_RIGHT_CTRL,
  /* ... */
} KeyEvent;

/* Functions */
char scanc();
void keyboard_init();
void kbh();
int atoi(char* str);