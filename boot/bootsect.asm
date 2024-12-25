; Licensed to the Apache Software Foundation (ASF) under one
; or more contributor license agreements.  See the LICENSE file
; distributed with this work for additional information
; regarding copyright ownership.  The ASF licenses this file
; to you under the Apache License, Version 2.0 (the
; "License"); you may not use this file except in compliance
; with the License.  You may obtain a copy of the License at
;
;     http://www.apache.org/licenses/LICENSE-2.0
;
; Unless required by applicable law or agreed to in writing,
; software distributed under the License is distributed on an
; "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
; KIND, either express or implied.  See the License for the
; specific language governing permissions and limitations
; under the License.

[org 0x7c00]

boot_start:
    ; prepare stack and boot drive
    mov [BOOT_DRIVE], dl
    mov bp, [STACK_OFFSET]
    mov sp, bp

    ; real mode msg
    mov bx, MSG_REAL_MODE
    call print
    call print_nl

    call load_kernel

    call switch_to_pm
    mov ebx, MSG_PROT_MODE
    call print_string_pm

    call enter_kernel
    jmp $ ; Just for safety lol

%include "boot/boot_sect_disk.asm"
%include "boot/print/boot_sect_print.asm"
%include "boot/print/boot_sect_print_hex.asm"
%include "boot/b32/32bit-gdt.asm"
%include "boot/b32/32bit-print.asm"
%include "boot/b32/32bit-switch.asm"

[bits 16]
load_kernel:
    mov bx, MSG_LOAD_KERNEL
    call print
    call print_nl

    mov bx, KERNEL_OFFSET ; Read from disk and store in 0x1000
    mov dh, [KERNEL_SIZE]
    mov dl, [BOOT_DRIVE]
    call disk_load
    ret

[bits 32]
enter_kernel:
    call KERNEL_OFFSET ; Call kernel_entry
    mov ebx, MSG_CRASH_KERNEL
    call print_string_pm
    jmp $ ; if the kernel crashes

BOOT_DRIVE db 0
%include "boot/config.asm"

; padding
times 510 - ($-$$) db 0
dw 0xaa55