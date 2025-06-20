; Copyright (c) Salmon 2025 under the Hippocratic 3.0 license.
; If your copy of this program doesn't include the license, it is
; available to read at:
;
;     <https://firstdonoharm.dev/version/3/0/core.txt>

[bits 32]

VIDEO_MEMORY equ 0xb8000
WHITE_ON_BLACK equ 0x0f 

print_string_pm:
    pusha
    mov edx, VIDEO_MEMORY

print_string_pm_loop:
    mov al, [ebx] ; [ebx] is the address of our character
    mov ah, WHITE_ON_BLACK

    cmp al, 0 ; check if end of string
    je print_string_pm_done

    mov [edx], ax ; store character + attribute in video memory
    add ebx, 1 ; next char, [ebx][i + 1]
    add edx, 2 ; next video memory position

    jmp print_string_pm_loop

print_string_pm_done:
    popa
    ret