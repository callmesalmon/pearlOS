/*
Licensed to the Apache Software Foundation (ASF) under one
or more contributor license agreements.  See the LICENSE file
distributed with this work for additional information
regarding copyright ownership.  The ASF licenses this file
to you under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance
with the License.  You may obtain a copy of the License at

  http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing,
software distributed under the License is distributed on an
"AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
KIND, either express or implied.  See the License for the
specific language governing permissions and limitations
under the License.
*/

#include <cpu/port.h>

/* Get from port */
byte port_byte_in(word port) {
    byte result;
    __asm__("in %%dx, %%al" : "=a" (result) : "d" (port));
    return result;
}

/* Send to port */
void port_byte_out(word port, byte data) {
    __asm__("out %%al, %%dx" : : "a" (data), "d" (port));
}

/* Get from port */
word port_word_in(word port) {
    unsigned short result;
    __asm__("in %%dx, %%ax" : "=a" (result) : "d" (port));
    return result;
}

/* Send to port */
void port_word_out(unsigned short port, word data) {
    __asm__("out %%ax, %%dx" : : "a" (data), "d" (port));
}