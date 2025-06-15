/*
 * Copyright (c) Salmon 2025 under the ANTIFA-MIT license.
 * If your copy of this program doesn't include the license, it is
 * available to read at: 
 *
 *     https://github.com/jamiebuilds/anti-fascist-mit-license
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