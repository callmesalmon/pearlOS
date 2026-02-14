#include <math.h>

/* x/y (x/y for y = 0: inf).
 * This way of accquiring infinity was
 * explored in my blog post, for more
 * info, see:
 *
 *     https://callmesalmon.github.io/ramblings/2025/01/31/infinity.html
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