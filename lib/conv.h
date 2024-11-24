#pragma once

#include "stddef.h"
#include "math.h"
#include "string.h"

#define INVALID_BYTE (byte)0x1099

void uint32_to_str(char* output, uint32_t number);
void uint32_to_hex(char* output, uint32_t number);
void uint_to_str(char* output, uint number);
void int_to_str(char* output, int number);
void short_to_str(char* output, short number);
char uint32_to_char(uint32_t number);
char uint_to_char(uint number);
int str_to_int(char *array, int n);
byte char_to_hex(char character);
