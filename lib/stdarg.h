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

/* * * * * * * * * * * * * * * * * * *
 *     The sixth commandment.        *
 * * * * * * * * * * * * * * * * * * *
 * When there is a builtin function  *
 * achieving thy goal, thou shall    *
 * utilize that function, e.g this   *
 * is a sin:                         *
 *                                   *
 *     #define va_start(ap, ...) \   *
 *         // Complicated impl...    *
 *                                   *
 * Yet thy soul shall be spared      *
 * should thou commence with this:   *
 *                                   *
 *     #define va_start(ap, ...) \   *
 *     __builtin_va_start(ap, 0)     *
 *                                   *
 * We DO NOT need more complicated   *
 * implementations, MARTHA. FOR THE  *
 * LOVE OF C AND C++!                *
 * * * * * * * * * * * * * * * * * * */

/* Types */
typedef __builtin_va_list va_list;

/* Defines */
#define va_start(ap, ...)  __builtin_va_start(ap, 0)
#define va_end(ap)         __builtin_va_end(ap)
#define va_arg(ap, type)   __builtin_va_arg(ap, type)
#define va_copy(dest, src) __builtin_va_copy(dest, src)