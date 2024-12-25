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

#include <stddef.h>
#include <math.h>
#include <string.h>

#define INVALID_BYTE (byte)0x1099
#define INVALID_INT (int)INF

void uint32_to_str(char* output, uint32_t number);
void uint32_to_hex(char* output, uint32_t number);
void uint_to_str(char* output, uint number);
void int_to_str(char* output, int number);
void short_to_str(char* output, short number);
char uint32_to_char(uint32_t number);
char uint_to_char(uint number);
int str_to_int(char *array, size_t n);
byte char_to_hex(char character);