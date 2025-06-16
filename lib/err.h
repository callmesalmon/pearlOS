/*
 * Copyright (c) Salmon 2025 under the ANTIFA-MIT license.
 * If your copy of this program doesn't include the license, it is
 * available to read at: 
 *
 *     https://github.com/jamiebuilds/anti-fascist-mit-license
 */

#pragma once

typedef struct {
    int code;
} excode;

excode exitval = {
        .code = 0
};

excode errval = {
    .code = 1
};

excode errval256 = {
    .code = 256
};

#define fetch return