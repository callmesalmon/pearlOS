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

KERNEL_SIZE   db  33
STACK_OFFSET  db  9000
KERNEL_OFFSET equ 0x1000

MSG_REAL_MODE    db "Started in 16-bit Real Mode",     0
MSG_PROT_MODE    db "Landed in 32-bit Protected Mode", 0
MSG_LOAD_KERNEL  db "Loading kernel into memory...",   0
MSG_CRASH_KERNEL db "[KERNEL PANIC] Nothing to do!!!", 0