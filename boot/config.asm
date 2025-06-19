; Copyright (c) Salmon 2025 under the Hippocratic 3.0 license.
; If your copy of this program doesn't include the license, it is
; available to read at:
;
;     <https://firstdonoharm.dev/version/3/0/core.txt>

KERNEL_SIZE   db  41
STACK_OFFSET  equ  16384
KERNEL_OFFSET equ 0x1000

MSG_REAL_MODE    db "Started in 16-bit Real Mode",     0
MSG_PROT_MODE    db "Landed in 32-bit Protected Mode", 0
MSG_LOAD_KERNEL  db "Loading kernel into memory...",   0
MSG_CRASH_KERNEL db "[KERNEL PANIC] Nothing to do!!!", 0