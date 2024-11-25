#include "math.h"

double pow(double base, double exponent)  // only positive numbers
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

double fac(double number)
{
    if (number == 0)
    {
        return 1;
    }
    return number * fac(number-1);
}
