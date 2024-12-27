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

#include <rand.h>

int rand_seed;

void rand_init() {
  int random_data;
  rand_seed = random_data + 2;
}

/* Linear congruential generator function
 * More info: https://en.wikipedia.org/wiki/Linear_congruential_generator
 */
int rand_lcg(int x) {
  /* Use the same parameters as glibc:
   * https://en.wikipedia.org/wiki/Linear_congruential_generator#Parameters_in_common_use
   */
  int a = 1103515245;
  int c = 12345;
  int m = -2147483648;
  int result = (a * x + c) % m;
  if (result < 0) result = -result;
  return result;
}

/* [USAGE] 
 * rand() or
 * rand() % (int)
 */
int rand() {
  rand_seed = rand_lcg(rand_seed);  /* I have no idea how this is valid C. */
  return rand_seed;
}