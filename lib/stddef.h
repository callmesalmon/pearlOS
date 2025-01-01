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

#pragma once

/* Generic types */
typedef unsigned long uint32_t;
typedef unsigned char byte;
typedef unsigned char* bytes;
typedef unsigned int uint;
typedef unsigned short word;
typedef unsigned char uchar;
typedef unsigned short ushort;

/* size_t */
#ifdef __SIZE_TYPE__
     typedef __SIZE_TYPE__ size_t;
#else
#    error "[ERROR] \"__SIZE_TYPE__\" is not defined. Can't compile."
#endif

/* Boolean definitions */
#if !defined(true) && !defined(false)
#    define true (bool) 1
#    define false (bool) 0
#endif

/* NULL definition */
#ifndef NULL
#    define NULL (void*) 0
#endif

/* High/Low 16 definitions */
#if !defined(low_16) && !defined(high_16)
#    define low_16(address) (word)((address) & 0xFFFF)
#    define high_16(address) (word)(((address) >> 16) & 0xFFFF)
#endif