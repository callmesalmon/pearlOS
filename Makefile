.DEFAULT_GOAL=dist/pearl.bin
.PHONY: clean run run-iso all full

CC       = gcc
CFLAGS   = -m32 -ffreestanding -fno-pie -Os -c -ggdb -I./lib
ASMC     = nasm 
ASMF     = elf32
LINKER   = ld -m elf_i386 -s
EMULATOR = qemu-system-i386
EMUFLAGS = -cdrom

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

KERNEL_OBJECTS     = $(KERNEL_C_OBJECTS) mk/kernel/kernel_entry.o
DRIVER_OBJECT      = $(DRIVER_C_OBJECTS)
CPU_OBJECTS        = $(CPU_C_OBJECTS)
LIB_OBJECTS        = $(LIB_C_OBJECTS)
FILESYSTEM_OBJECTS = $(FILESYSTEM_C_OBJECTS)

dist/pearl.bin: mk/bin/kernel.bin mk/bin/bootsect.bin
	rm -f dist/pearl.bin
	cat mk/bin/* > $@
	chmod +x dist/pearl.bin

dist/pearl.iso: $(.DEFAULT_GOAL)
	mkdir -p mk/iso/
	rm -f dist/pearl.iso
	truncate $(.DEFAULT_GOAL) -s 1200k
	cp $(.DEFAULT_GOAL) mk/iso/kernel.bin
	mkisofs -b kernel.bin -o dist/pearl.iso mk/iso/

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

mk/kernel/kernel_entry.o: kernel/kernel_entry.asm
	$(ASMC) -f $(ASMF) -o $@ $<

run: $(.DEFAULT_GOAL)
	$(EMULATOR) $^

run-iso: dist/pearl.iso
	$(EMULATOR) $(EMUFLAGS) $^

clean:
	rm -f dist/*
	rm -f mk/bin/*
	rm -f mk/kernel/*
	rm -f mk/drivers/*
	rm -f mk/cpu/*
	rm -f mk/lib/*
	rm -f mk/fs/*
	rm -f mk/iso/*
