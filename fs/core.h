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
#include <string.h>
#include <stddef.h>
#include <mem.h>

#include <fs/prop.h>
#include <kernel/config.h>
#include <kernel/kmsg.h>
#include <kernel/version.h>

/* Defines */
#define OK                      0
#define FILE_COUNT_MAX_EXCEEDED 1
#define FILE_ALREADY_EXISTS     2
#define FILE_NAME_INVALID       3
#define FILE_NOT_FOUND          1

#define FS_SECTOR_DATA_SIZE FS_SECTOR_SIZE - sizeof(struct Sector*)
#define END_SECTOR 0

/* Structs and Types */
struct SectorStruct {
  struct Sector* next;
  byte data[FS_SECTOR_DATA_SIZE];
};
typedef struct SectorStruct Sector;

typedef struct {
  char name[FS_FILE_NAME_BUFFER];
  char tags[FS_FILE_TAGS_BUFFER];
  Sector* first_sector;
} File;

/* Functions */
void mkfs();
int file_remove(char* name);
int file_make(char* name);
char* file_get_name(int id);
int file_get_id(char* name);
int file_count();
bool file_exists(char* name);
int file_size(char* name);
int file_read(char* filename, char* output);
int file_write(char* filename, char* data, uint32_t depth);
int file_writes(char* filename, char* text);
int file_clean(char* filename);