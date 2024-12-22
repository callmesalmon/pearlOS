#include <math.h>

/* do (1 *= base) * exponent */
double pow(double base, double exponent)
{
  double result = 1;
  while (exponent > 0)
  {
    result *= base;
    --exponent;
  }
  return result;
}

double abs(double number)
{
  if (number < 0) return -number;
  return number;
}

/* do while(--number != 1) (number * (number - 1)) */
double fac(double number)
{
    if (number == 1)
    {
        return 1;
    }
    return number * fac(number - 1);
}
