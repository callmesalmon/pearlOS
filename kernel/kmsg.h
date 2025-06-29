/*
 * Copyright (c) Salmon 2025 under the Hippocratic 3.0 license.
 * If your copy of this program doesn't include the license, it is
 * available to read at:
 * 
 *     <https://firstdonoharm.dev/version/3/0/core.txt>
 */

#pragma once

/* Includes */
#include <kernel/messages.h>

/* Functions */
void kinfo(char* msg);
void kwarning(char* msg);
void kerror(char* msg);
void kpanic(char* msg);