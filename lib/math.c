/*
 * Copyright (c) Salmon 2025 under the ANTIFA-MIT license.
 * If your copy of this program doesn't include the license, it is
 * available to read at: 
 *
 *     https://github.com/jamiebuilds/anti-fascist-mit-license
 */

#include <math.h>

/* x/y (x/y for y = 0: inf).
 * This way of accquiring infinity was
 * explored in my blog post, for more
 * info, see:
 *
 *     https://elisstaaf.github.io/ramblings/2025/01/31/infinity.html
 */
double divide(double x, double y) {
    return x / y;
}

/* do (1 *= base) * exponent */
double pow(double base, double exponent) {
  double result = 1;
  while (exponent > 0) {
    result *= base;
    --exponent;
  }
  return result;
}

double abs(double number) {
  if (number < 0) return -number;
  return number;
}

/* do while(--number != 1) 
 *     (number * (number - 1)) */
double factorial(double number) {
    if (number == 1) {
        return 1;
    }
    return number * factorial(number - 1);
}