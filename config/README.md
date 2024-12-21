# Configuration Guide
PearlOS prides itself in its configuration. It is incredibly easy to use and create
new configurations with! Follow this quick tutorial to learn how to make your own!

## Tutorial
To start, create a new folder in the "profiles" directory, like this:
```console
mkdir ./profiles/<dir>
```
Enter the directory. Now create a new file called "config.h", like this:
```console
touch config.h
```
Open it using your favourite editor, and let's get configuring! This configuration
operates using macros, refer to this table when defining them:
```
DEFAULT_THEME<macro>             : Refer to your favourite colourscheme
                                   defined in drivers/display_color.h.

KERNEL_STARTUP<function>         : Entry point for kernel, pick one or
                                   maybe add your own?

KERNEL_UPDATE<null>              : Infinity macro, the main kernel part
                                   (kernel/kernel.c) needs this one.

KSH_PROMPT<char*>                : The prompt that shows up when writing
                                   commands in the Kernel SHell.

KSH_COMMENT<char>                : The character that is required to
                                   start a comment line.

KERNEL_MEMORY_OFFSET_{START,
                      END}<byte> : Kernel memory offsets,
                                   defaults are "0x{f*x}".

MEMORY_INDEX_BASE_SIZE           : Basically how many calls of the
                                   allocator (kmalloc) you can do.
```
So, a good configuration might be:
```c
#pragma once

#define DEFAULT_THEME  WHITE_ON_BLUE
#define KERNEL_STARTUP ksh_start();
#define KERNEL_UPDATE

#define KSH_PROMPT  "pearl>"
#define KSH_COMMENT ';'

#define KERNEL_MEMORY_OFFSET_START 0xffffff
#define KERNEL_MEMORY_OFFSET_END   0xffffffff
#define MEMORY_INDEX_BASE_SIZE     100
```
Now, create a file called "kentry.asm", like this:
```console
touch kentry.asm
```
This is the script that enters the kernel and runs
it. You can just use the default here:
```asm
[bits 32]
[extern main]
call main
jmp $
```
But if you're good at assembly, you can customize this!
After that, create a file called "config.asm", like this:
```console
touch config.asm
```
This is the config file for the boot sector, refer to this
table for all of the rules required in this file:
```
KERNEL_SIZE<db>      : Size of the kernel, preferably 33,
                       because if not, it barely compiles.

STACK_OFFSET<db>     : Simply the offset of the
                       "stack" datastructure.

KERNEL_OFFSET<equ>   : Simply the offset of the
                       kernel part of the OS.

MSG_REAL_MODE<db>    : Message that prints when
                       kernel has entered real mode.

MSG_PROT_MODE<db>    : Message that prints when
                       kernel has entered protected
                       mode.

MSG_LOAD_KERNEL<db>  : Message that prints when
                       kernel is loading.

MSG_CRASH_KERNEL<db> : Message that prints if 
                       kernel crashes.
```
A good config.asm might be:
```asm
KERNEL_SIZE   db  33
STACK_OFFSET  db  9000
KERNEL_OFFSET equ 0x1000

MSG_REAL_MODE    db "16-bit real mode entered.",     0
MSG_PROT_MODE    db "32-bit protected mode entered.", 0
MSG_LOAD_KERNEL  db "Kernel is loading...",   0
MSG_CRASH_KERNEL db "[KERNEL PANIC] Something has gone wrong!!!", 0
```
Finally, navigate into the root of this repository
and run:
```console
./config.sh <profile-name>
```
