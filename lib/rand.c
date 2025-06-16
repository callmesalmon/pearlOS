/*
 * Copyright (c) Salmon 2025 under the ANTIFA-MIT license.
 * If your copy of this program doesn't include the license, it is
 * available to read at: 
 *
 *     https://github.com/jamiebuilds/anti-fascist-mit-license
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
  rand_seed = rand_lcg(rand_seed);
  return rand_seed;
}