global long_mode_start

; get __main from
; /src/impl/kernel/main.c
extern __main

section .text
bits 64
long_mode_start:
    ; load null into all data segment registers
    mov ax, 0
    mov ss, ax
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    ; call __main
    call __main
    hlt
