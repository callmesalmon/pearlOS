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

#pragma once

#include <io.h>
#include <mem.h>

#include <fs/fscore.h>

void ksh_read_file() {
  char* filename = (char*) kmalloc(256);
  printk("> ");
  scan(filename);

  char* content = (char*) kmalloc(file_size(filename));
  int response = file_read(filename, content);

  if (response == FILE_NOT_FOUND) {
    printk("File not found\n");
  }
  printk(content);

  kfree(filename);
  kfree(content);
}