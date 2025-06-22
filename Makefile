# Copyright (c) Salmon 2025 under the Hippocratic 3.0 license.
# If your copy of this program doesn't include the license, it is
# available to read at:
#
#     <https://firstdonoharm.dev/version/3/0/core.txt>

# Default target
.PHONY: all clean run iso

# Directories
BUILD_DIR = build
ISO_DIR = $(BUILD_DIR)/iso
BOOT_DIR = $(ISO_DIR)/boot
GRUB_DIR = $(BOOT_DIR)/grub

# Output files
KERNEL = $(BUILD_DIR)/pearlos.kernel
ISO = $(BUILD_DIR)/pearlos.iso

# Toolchain
CC = clang
LD = ld
AS = nasm
GRUB_MKRESCUE = grub-mkrescue
QEMU = qemu-system-i386

# Flags
CFLAGS = -m32 -std=c17 -ffreestanding -fno-pie -fno-builtin -fno-stack-protector \
         -Wall -Wextra -I. -I./kernel -I./kernel/arch/x86 -I./lib -I./cpu -I./drivers -I./fs \
         -nostdlib -nostdinc -g

ASFLAGS := -f elf32 -g
NASMFLAGS := -f elf32 -g
LDFLAGS = -m elf_i386 -T kernel/arch/x86/linker.ld -nostdlib

# Source files
KERNEL_C_SOURCES = $(shell find kernel/ -name '*.c')
KERNEL_ASM_SOURCES = $(shell find kernel/arch/x86/ -name '*.S')
CPU_C_SOURCES = $(shell find cpu/ -name '*.c')
CPU_ASM_SOURCES = $(shell find cpu/ -name '*.asm')
DRIVERS_C_SOURCES = $(shell find drivers/ -name '*.c')
FS_C_SOURCES = $(shell find fs/ -name '*.c')
LIB_C_SOURCES = $(shell find lib/ -name '*.c')

# Object files
KERNEL_OBJS = $(patsubst %.c, $(BUILD_DIR)/%.o, $(KERNEL_C_SOURCES)) \
              $(patsubst %.S, $(BUILD_DIR)/%.o, $(KERNEL_ASM_SOURCES)) \
              $(patsubst %.c, $(BUILD_DIR)/%.o, $(CPU_C_SOURCES)) \
              $(patsubst %.asm, $(BUILD_DIR)/%.o, $(CPU_ASM_SOURCES)) \
              $(patsubst %.c, $(BUILD_DIR)/%.o, $(DRIVERS_C_SOURCES)) \
              $(patsubst %.c, $(BUILD_DIR)/%.o, $(FS_C_SOURCES)) \
              $(patsubst %.c, $(BUILD_DIR)/%.o, $(LIB_C_SOURCES))

# Default target
all: $(ISO)

# Create ISO
$(ISO): $(KERNEL) | $(GRUB_DIR)
	@mkdir -p $(BOOT_DIR)/grub
	@cp $(KERNEL) $(BOOT_DIR)/
	@cp grub.cfg $(GRUB_DIR)/
	@$(GRUB_MKRESCUE) -o $@ $(ISO_DIR)

# Link kernel
$(KERNEL): $(KERNEL_OBJS)
	@echo "  LD    $@"
	@$(LD) $(LDFLAGS) -o $@ $^

# Compile C files
$(BUILD_DIR)/%.o: %.c
	@echo "  CC    $<"
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

# Assemble ASM files with NASM
$(BUILD_DIR)/%.o: %.S
	@echo "  AS    $<"
	@mkdir -p $(@D)
	@nasm $(NASMFLAGS) $< -o $@

# Assemble .asm files with NASM
$(BUILD_DIR)/%.o: %.asm
	@echo "  ASM   $<"
	@mkdir -p $(@D)
	@nasm -f elf32 $< -o $@

# Create GRUB directory
$(GRUB_DIR):
	@mkdir -p $@

# Run in QEMU
run qemu: $(ISO)
	$(QEMU) -cdrom $(ISO) -m 128M -serial stdio

# Clean build files
clean:
	rm -rf $(BUILD_DIR)

# Create ISO directory structure
$(shell mkdir -p $(GRUB_DIR))