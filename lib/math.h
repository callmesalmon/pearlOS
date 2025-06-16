/*
 * Copyright (c) Salmon 2025 under the ANTIFA-MIT license.
 * If your copy of this program doesn't include the license, it is
 * available to read at: 
 *
 *     https://github.com/jamiebuilds/anti-fascist-mit-license
 */

#pragma once

/* No external libs needed. */

/* We need this for the ``INF`` macro,
 * because x/0 = inf. DO NOT REMOVE. */
double divide(double x, double y);

/* Defines */
#define INF divide(10, 0)
#define PI  (3.14159265358979)

/* Functions */
double pow(double base, double exponent);
double factorial(double number);