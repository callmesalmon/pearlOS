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

#include <magic.h>
#include <mem.h>
#include <stddef.h>
#include <kernel/kmsg.h>
#include <kernel/config.h>

/* 
 * [INDEX STRUCTURE]
 * Even index -> Page start
 * Odd index -> Page end
 */
byte* memory_index[MEMORY_INDEX_BASE_SIZE];

byte* get_memory_index() {
  return (byte*) memory_index;
}

/* Allocate memory, think
 * malloc() but worse. */
void* kmalloc(uint32_t size) {
  uint i = 0;

  while (1) {
    /* Search */
    while (memory_index[i] != MEMORY_EMPTY) {
        i += 2;
    }

    byte* last_page_end = memory_index[i - 1];
    uint next_page_start_id = i;

    while (memory_index[next_page_start_id] == MEMORY_EMPTY) {
        ++next_page_start_id;
    }

    /* Verify */
    if (memory_index[next_page_start_id] - last_page_end > size) {
      if (i >= MEMORY_INDEX_BASE_SIZE) {
        kpanic(KERNEL_PANIC_MEMORY_INDEX_FULL);
      }
      if (size + last_page_end + 1 >= (byte *)KERNEL_MEMORY_OFFSET_END) {
        kpanic(KERNEL_PANIC_MEMORY_FULL);
      }

      /* Allocate */
      memory_index[i] = last_page_end + 1;
      memory_index[i + 1] = memory_index[i] + size;
      return (void*) memory_index[i];
    }
  }
}

/* Free allocated memory */
void kfree(void* memory) {
  uint id = 0;
  while (memory_index[id] != memory) { id += 2; }
  memory_index[id] = MEMORY_EMPTY;
  memory_index[id + 1] = MEMORY_EMPTY;
}

/* Gets size of all used kmalloc pages */
uint32_t memory_usage() {
  uint i = 2;  /* Remember the first two bytes meta-data. */
  uint32_t usage = 0;
  while (i < MEMORY_INDEX_BASE_SIZE) {
    if (memory_index[i] != MEMORY_EMPTY) {
      usage += (uint32_t) memory_index[i + 1] - (uint32_t) memory_index[i];
    }
    i += 2;
  }
  return usage;
}

uint32_t memory_total() {
  return KERNEL_MEMORY_OFFSET_END - KERNEL_MEMORY_OFFSET_START;
}

/* Gets the total size of allocated
 * memory, counting freed pages. */
uint32_t memory_usage_effective() {
  uint i = 2;  /* Remember the first two bytes meta-data. */
  uint32_t usage = 0;
  while (i < MEMORY_INDEX_BASE_SIZE) {
    if ((uint32_t) memory_index[i + 1] > usage) {
      usage = (uint32_t) memory_index[i + 1];
    }
    i += 2;
  }
  return usage - (KERNEL_MEMORY_OFFSET_START + 1);
}

/* [INITIALIZER]
 * Initializes kernel memory pointer ->
 * allows for kmalloc() calls. */
void memory_init() {
  memory_index[0] = (byte*) KERNEL_MEMORY_OFFSET_START;
  memory_index[1] = (byte*) KERNEL_MEMORY_OFFSET_START;
  for (int i = 2; i < len(memory_index); ++i) {
    memory_index[i] = MEMORY_EMPTY;
  }
}

/* Copy memory */
void memcpy(byte* dest, byte* src, uint32_t size) {
  for (uint32_t i = 0; i < size; ++i) {
    dest[i] = src[i];
  }
}