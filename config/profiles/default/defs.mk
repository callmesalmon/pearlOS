.DEFAULT_GOAL=dist/pearl.bin

EMULATOR = qemu-system-i386
LINKER   = ld -m elf_i386 -s
CC       = gcc
CFLAGS   = -m32 -ffreestanding -fno-pie -Os \
           -c -ggdb -I./lib -I. -std=c17
