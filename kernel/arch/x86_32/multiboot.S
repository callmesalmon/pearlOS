; Multiboot header
section .multiboot
align 4
    dd 0x1BADB002
    dd 0x00000003
    dd -(0x1BADB002 + 0x00000003)

; Stack
section .bss
align 16
stack_bottom:
    resb 16384
stack_top:

; Entry point
section .text
global _start
_start:
    ; Set up stack
    mov esp, stack_top
    
    ; Push multiboot info
    push ebx
    push eax
    
    ; Call kernel main
    extern kmain
    call kmain
    
    ; Halt if kmain returns
    cli
.hang:
    hlt
    jmp .hang
