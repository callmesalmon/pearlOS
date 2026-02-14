#pragma once

/* No external libs needed. */

/* We need this for the ``INF`` macro,
 * because x/0 = inf. DO NOT REMOVE. */
double divide(double x, double y);

/* Defines */
#define INF      divide(10, 0)
#define INFINITY divide(10, 0)

/* Functions */
double pow(double base, double exponent);