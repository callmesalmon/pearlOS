/*
Copyright 2025 Elis Staaf

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

#include <drivers/display_cursor.h>
#include <drivers/display.h>

uint32_t get_cursor_position_x() {
  uint32_t pos = 0;
  port_byte_out(0x3D4, 0x0F);
  pos |= port_byte_in(0x3D5);
  port_byte_out(0x3D4, 0x0E);
  pos |= ((uint32_t)port_byte_in(0x3D5)) << 8;
  return pos % DISPLAY_WIDTH;
}

uint32_t get_cursor_position_y() {
  uint32_t pos = 0;
  port_byte_out(0x3D4, 0x0F);
  pos |= port_byte_in(0x3D5);
  port_byte_out(0x3D4, 0x0E);
  pos |= ((uint32_t)port_byte_in(0x3D5)) << 8;
  return pos / DISPLAY_WIDTH;
}

uint get_cursor_offset() {
    port_byte_out(REG_DISPLAY_CTRL, 14);
    uint offset = port_byte_in(REG_DISPLAY_DATA) << 8;
    port_byte_out(REG_DISPLAY_CTRL, 15);
    offset += port_byte_in(REG_DISPLAY_DATA);
    return offset * 2;
}

void set_cursor_offset(uint offset) {
    offset /= 2;
    port_byte_out(REG_DISPLAY_CTRL, 14);
    port_byte_out(REG_DISPLAY_DATA, (byte) (offset >> 8));
    port_byte_out(REG_DISPLAY_CTRL, 15);
    port_byte_out(REG_DISPLAY_DATA, (byte) (offset & 0xff));
}