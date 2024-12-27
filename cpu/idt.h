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

/* Segment selectors */
#define KERNEL_CS 0x08
#define IDT_ENTRIES 256

/* Structs */
typedef struct {
    word low_offset; /* Lower 16 bits of handler address */
    word selector; /* Kernel seg selector */
    byte always0;
    byte flags;
    word high_offset;
} __attribute__((packed)) idt_gate_t;

/* Pointer to interrupt handler array */
typedef struct {
    word limit;
    uint32_t base;
} __attribute__((packed)) idt_register_t;

/* Defines */
static idt_gate_t idt[IDT_ENTRIES];
static idt_register_t idt_reg;

/* Functions */
void set_idt_gate(int n, uint32_t handler);
void apply_idt();