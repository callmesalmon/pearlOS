/*
 * Copyright (c) Salmon 2025 under the ANTIFA-MIT license.
 * If your copy of this program doesn't include the license, it is
 * available to read at: 
 *
 *     https://github.com/jamiebuilds/anti-fascist-mit-license
 */

#include <stdint.h>
#include <stddef.h>

bool chint(char ch) {
    if ((ch >= 'a' && ch <= 'z') || 
        (ch >= 'A' && ch <= 'Z')) {
        return false;
    }
    return true;
}