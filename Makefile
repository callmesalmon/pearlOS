# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements.  See the LICENSE file
# distributed with this work for additional information
# regarding copyright ownership.  The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License.  You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied.  See the License for the
# specific language governing permissions and limitations
# under the License.

.DEFAULT_GOAL=dist/pearl.bin
.PHONY: clean run run-iso all full

EMULATOR = qemu-system-i386
LINKER   = ld -m elf_i386 -s
CC       = gcc
CFLAGS   = -m32 -ffreestanding -fno-pie -Os -c -ggdb -I./lib -I. -std=c17
ASMC     = nasm 
ASMF     = elf32

KERNEL_C_SOURCES     := $(wildcard kernel/*.c)
KERNEL_C_OBJECTS     := $(patsubst kernel/%.c, mk/kernel/%.o, $(KERNEL_C_SOURCES))
DRIVER_C_SOURCES     := $(wildcard drivers/*.c)
DRIVER_C_OBJECTS     := $(patsubst drivers/%.c, mk/drivers/%.o, $(DRIVER_C_SOURCES))
CPU_C_SOURCES        := $(wildcard cpu/*.c)
CPU_C_OBJECTS        := $(patsubst cpu/%.c, mk/cpu/%.o, $(CPU_C_SOURCES))
LIB_C_SOURCES        := $(wildcard lib/*.c)
LIB_C_OBJECTS        := $(patsubst lib/%.c, mk/lib/%.o, $(LIB_C_SOURCES))
FILESYSTEM_C_SOURCES := $(wildcard fs/*.c)
FILESYSTEM_C_OBJECTS := $(patsubst fs/%.c, mk/fs/%.o, $(FILESYSTEM_C_SOURCES))

C_HEADERS = $(wildcard */*.h) $(wildcard kernel/advanced_cmds/*.h)

KERNEL_OBJECTS     = $(KERNEL_C_OBJECTS) mk/kernel/kentry.o
DRIVER_OBJECT      = $(DRIVER_C_OBJECTS)
CPU_OBJECTS        = $(CPU_C_OBJECTS) mk/cpu/interrupt.o
LIB_OBJECTS        = $(LIB_C_OBJECTS)
FILESYSTEM_OBJECTS = $(FILESYSTEM_C_OBJECTS)

dist/pearl.bin: mk/bin/kernel.bin mk/bin/bootsect.bin
	rm -f dist/pearl.bin
	cat mk/bin/* > $@
	chmod +x dist/pearl.bin

mk/bin/kernel.bin: $(KERNEL_OBJECTS) $(DRIVER_OBJECT) $(CPU_OBJECTS) $(LIB_OBJECTS) $(FILESYSTEM_OBJECTS)
	$(LINKER) -o $@ -Ttext 0x1000 $^ --oformat binary

mk/bin/bootsect.bin: boot/*
	$(ASMC) -f bin -o $@ boot/bootsect.asm
	chmod +x $@

mk/kernel/%.o: kernel/%.c $(C_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

mk/drivers/%.o: drivers/%.c $(C_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

mk/cpu/%.o: cpu/%.c $(C_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

mk/lib/%.o: lib/%.c $(C_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

mk/fs/%.o: fs/%.c $(C_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

mk/kernel/kentry.o: kernel/kentry.asm
	$(ASMC) -f $(ASMF) -o $@ $<

mk/cpu/interrupt.o: cpu/interrupt.asm
	$(ASMC) -f $(ASMF) -o $@ $<

qemu: $(.DEFAULT_GOAL)
	$(EMULATOR) $^

clean:
	rm -f dist/*
	rm -f mk/bin/*
	rm -f mk/kernel/*
	rm -f mk/drivers/*
	rm -f mk/cpu/*
	rm -f mk/lib/*
	rm -f mk/fs/*