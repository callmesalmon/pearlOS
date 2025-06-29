/*
 * Copyright (c) Salmon 2025 under the Hippocratic 3.0 license.
 * If your copy of this program doesn't include the license, it is
 * available to read at:
 * 
 *     <https://firstdonoharm.dev/version/3/0/core.txt>
 */

#pragma once

typedef struct {
    int code;
} excode;

excode exitval = { 
    .code = 0 
};

excode errval    = { .code = 1   };
excode errval256 = { .code = 256 };

#define fetch return