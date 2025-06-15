/*
 * Copyright (c) Salmon 2025 under the ANTIFA-MIT license.
 * If your copy of this program doesn't include the license, it is
 * available to read at: 
 *
 *     https://github.com/jamiebuilds/anti-fascist-mit-license
 */

#pragma once

/* Includes */
#include <stddef.h>

/* Functions */
byte port_byte_in(word port);
void port_byte_out(word port, byte data);
word port_word_in(word port);
void port_word_out(word port, word data);