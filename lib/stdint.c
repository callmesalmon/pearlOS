/*
 * Copyright (c) Salmon 2025 under the Hippocratic 3.0 license.
 * If your copy of this program doesn't include the license, it is
 * available to read at:
 * 
 *     <https://firstdonoharm.dev/version/3/0/core.txt>
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