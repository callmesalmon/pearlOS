/*
 * Copyright (c) Salmon 2025 under the ANTIFA-MIT license.
 * If your copy of this program doesn't include the license, it is
 * available to read at: 
 *
 *     https://github.com/jamiebuilds/anti-fascist-mit-license
 */

#pragma once

/* Includes */
#include <kernel/messages.h>

/* Functions */
void kinfo(char* msg);
void kwarning(char* msg);
void kerror(char* msg);
void kpanic(char* msg);