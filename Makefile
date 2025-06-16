# Copyright (c) Salmon 2025 under the ANTIFA-MIT license.
# If your copy of this program doesn't include the license, it is
# available to read at:
#
# https://github.com/jamiebuilds/anti-fascist-mit-license

.DEFAULT_GOAL=dist/pearl.bin
.PHONY: clean run run-iso all full

EMULATOR = qemu-system-i386
EMUFLAGS = -display gtk
LINKER   = ld -m elf_i386 -s
CC       = clang
CFLAGS   = -m32 -ffreestanding -fno-pie -Os -c -ggdb -I./lib -I. --target=i686-pc-none-elf \
		   -march=i686 -I. -fno-builtin -nostdlib -nostdinc -std=c17
ASMC     = nasm
ASMF     = elf32

KERNEL_C_SOURCES     := $(wildcard kernel/*.c)
KERNEL_C_OBJECTS     := $(patsubst kernel/%.c, mk/kernel/%.o, $(KERNEL_C_SOURCES))
CMD_C_SOURCES        := $(wildcard kernel/cmd/*.c)
CMD_C_OBJECTS        := $(patsubst kernel/cmd/%.c, mk/kernel/cmd/%.o, $(CMD_C_SOURCES))
DRIVER_C_SOURCES     := $(wildcard drivers/*.c)
DRIVER_C_OBJECTS     := $(patsubst drivers/%.c, mk/drivers/%.o, $(DRIVER_C_SOURCES))
CPU_C_SOURCES        := $(wildcard cpu/*.c)
CPU_C_OBJECTS        := $(patsubst cpu/%.c, mk/cpu/%.o, $(CPU_C_SOURCES))
LIB_C_SOURCES        := $(wildcard lib/*.c)
LIB_C_OBJECTS        := $(patsubst lib/%.c, mk/lib/%.o, $(LIB_C_SOURCES))
FILESYSTEM_C_SOURCES := $(wildcard fs/*.c)
FILESYSTEM_C_OBJECTS := $(patsubst fs/%.c, mk/fs/%.o, $(FILESYSTEM_C_SOURCES))

C_PROGRAMS = $(wildcard kernel/cmd/*.h)
C_HEADERS  = $(wildcard */*.h) $(wildcard kernel/programs/*.h)
C_OBJ_REQS = $(C_PROGRAMS) $(C_HEADERS)

KERNEL_OBJECTS     = $(KERNEL_C_OBJECTS) $(CMD_C_OBJECTS) mk/kernel/kentry.o
DRIVER_OBJECT      = $(DRIVER_C_OBJECTS)
CPU_OBJECTS        = $(CPU_C_OBJECTS) mk/cpu/interrupt.o
LIB_OBJECTS        = $(LIB_C_OBJECTS)
FILESYSTEM_OBJECTS = $(FILESYSTEM_C_OBJECTS)

# Directories needed for build output
BUILD_DIRS = mk mk/bin mk/kernel mk/kernel/cmd mk/drivers mk/cpu mk/lib mk/fs dist
$(BUILD_DIRS):
	mkdir -p $@

all: $(.DEFAULT_GOAL)

dist/pearl.bin: mk/bin/kernel.bin mk/bin/bootsect.bin | dist
	rm -f dist/pearl.bin
	cat mk/bin/* > $@
	chmod +x dist/pearl.bin

mk/bin/kernel.bin: $(KERNEL_OBJECTS) $(DRIVER_OBJECT) $(CPU_OBJECTS) $(LIB_OBJECTS) $(FILESYSTEM_OBJECTS) | mk/bin
	$(LINKER) -o $@ -Ttext 0x1000 $^ --oformat binary

mk/bin/bootsect.bin: boot/* | mk/bin
	$(ASMC) -f bin -o $@ boot/bootsect.asm
	chmod +x $@

mk/kernel/%.o: kernel/%.c $(C_OBJ_REQS) | mk/kernel
	$(CC) $(CFLAGS) -c $< -o $@

mk/kernel/cmd/%.o: kernel/cmd/%.c $(C_OBJ_REQS) | mk/kernel/cmd
	$(CC) $(CFLAGS) -c $< -o $@

mk/drivers/%.o: drivers/%.c $(C_OBJ_REQS) | mk/drivers
	$(CC) $(CFLAGS) -c $< -o $@

mk/cpu/%.o: cpu/%.c $(C_OBJ_REQS) | mk/cpu
	$(CC) $(CFLAGS) -c $< -o $@

mk/lib/%.o: lib/%.c $(C_OBJ_REQS) | mk/lib
	$(CC) $(CFLAGS) -c $< -o $@

mk/fs/%.o: fs/%.c $(C_OBJ_REQS) | mk/fs
	$(CC) $(CFLAGS) -c $< -o $@

mk/kernel/kentry.o: kernel/kentry.asm | mk/kernel
	$(ASMC) -f $(ASMF) -o $@ $<

mk/cpu/interrupt.o: cpu/interrupt.asm | mk/cpu
	$(ASMC) -f $(ASMF) -o $@ $<

qemu: $(.DEFAULT_GOAL)
	$(EMULATOR) $(EMUFLAGS) $^

clean:
	rm -f dist/*
	rm -f mk/bin/*
	rm -f mk/kernel/*
	rm -f mk/kernel/cmd/*
	rm -f mk/drivers/*
	rm -f mk/cpu/*
	rm -f mk/lib/*
	rm -f mk/fs/*

