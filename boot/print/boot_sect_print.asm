; Copyright (c) Salmon 2025 under the Hippocratic 3.0 license.
; If your copy of this program doesn't include the license, it is
; available to read at:
;
;     <https://firstdonoharm.dev/version/3/0/core.txt>

print:
    pusha

; Keep this in mind:
; while (string[i] != 0) { print string[i]; i++ }

; the comparison for string end (null byte)
start:
    mov al, [bx] ; 'bx' is the base address for the string
    cmp al, 0 
    je done

    ; the part where we print with the BIOS help
    mov ah, 0x0e
    int 0x10 ; 'al' already contains the char

    ; increment pointer and do next loop
    add bx, 1
    jmp start

done:
    popa
    ret

print_nl:
    pusha
    
    mov ah, 0x0e
    mov al, 0x0a ; newline char (\n)
    int 0x10
    mov al, 0x0d ; carriage return (\r)
    int 0x10
    
    popa
    ret