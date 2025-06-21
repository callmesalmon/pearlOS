/*
 * Copyright (c) Salmon 2025 under the Hippocratic 3.0 license.
 * If your copy of this program doesn't include the license, it is
 * available to read at:
 * 
 *     <https://firstdonoharm.dev/version/3/0/core.txt>
 */

#include <conv.h>
#include <stddef.h>

void uint32_to_str(char* output, uint32_t number) {
    const char digits[] = "0123456789";
    int i = 0;
    int j;
    unsigned remains;
    char c;

    do {
      remains = number % 10;
      output[i++] = digits[remains];
      number = number / 10;
    } while (number != 0);
    output[i] = '\0';

    for (j = 0, i--; j < i; j++, i--) {
      c = output[j];
      output[j] = output[i];
      output[i] = c;
    }
}

void uint32_to_hex(char* output, uint32_t number)
{
    const char digits[] = "0123456789ABCDEF";
    int i = 0;
    int j;
    unsigned remains;
    char c;

    do {
      remains = number % 16;
      output[i++] = digits[remains];
      number = number / 16;
    } while (number != 0);
    output[i] = '\0';

    for (j = 0, i--; j < i; j++, i--) {
      c = output[j];
      output[j] = output[i];
      output[i] = c;
    }
}

void uint_to_str(char* output, uint number) {
  uint32_to_str(output, (uint32_t) number);
}

void int_to_str(char* output, int number) {
  if (number < 0) {
    output[0] = '-';  /* set the first byte to '-', indicating its a negative */
    ++output;         /* we dont want to overwrite the '-' */
    number = -number; /* negate the negative number, making it positive */
  }
  uint_to_str(output, number);
}

void short_to_str(char* output, short number) {
  int_to_str(output, (int) number);
}

char uint32_to_char(uint32_t number) {
  switch (number) {
    case 0: return '0';
    case 1: return '1';
    case 2: return '2';
    case 3: return '3';
    case 4: return '4';
    case 5: return '5';
    case 6: return '6';
    case 7: return '7';
    case 8: return '8';
    case 9: return '9';
  }
  return '?'; /* Just in case */
}

char uint_to_char(uint number) {
  return uint32_to_char((uint32_t) number);
}

int str_to_int(char *array, size_t n) {    
    int number = 0;
    int mult = 1;

    n = (int)n < 0 ? -n : n; /* quick absolute value check  */

    /* for each character in array */
    while (n--) {
        /* array[n] = char -> exit */
        if ((array[n] >= 'a' && array[n] <= 'z') || \
        (array[n] >= 'A' && array[n] <= 'Z')) {
            return INVALID_INT;
        }

        /* if not digit or '-', check if number > 0, break or continue */
        if ((array[n] < '0' || array[n] > '9') && array[n] != '-') {
            if (number) {
                break;
            }
            else {
                continue;
            }
        }

        if (array[n] == '-') { /* if '-' if number, negate, break */
            if (number) {
                number = -number;
                break;
            }
        }
        else { /* convert digit to numeric value   */
        
            number += (array[n] - '0') * mult;
            mult *= 10;
        }
    }

    return number;
}

byte char_to_hex(char character) {
  switch (character) {
    case '0': return 0x0;
    case '1': return 0x1;
    case '2': return 0x2;
    case '3': return 0x3;
    case '4': return 0x4;
    case '5': return 0x5;
    case '6': return 0x6;
    case '7': return 0x7;
    case '8': return 0x8;
    case '9': return 0x9;
    case 'a': return 0xA;
    case 'A': return 0xA;
    case 'b': return 0xB;
    case 'B': return 0xB;
    case 'c': return 0xC;
    case 'C': return 0xC;
    case 'd': return 0xD;
    case 'e': return 0xE;
    case 'E': return 0xE;
    case 'f': return 0xF;
    case 'F': return 0xF;
  }
  return INVALID_BYTE;
}

int hex_to_int(char* hex_str, size_t len) {
    if (!hex_str || len <= 0) return INVALID_INT;
    
    int number = 0;
    bool negative = false;

    for (size_t i = 0; i < len; i++) {
        if (hex_str[i] == '-') {
            if (i > 0 || negative) return INVALID_INT;
            negative = true;
            continue;
        }

        byte hex_val = char_to_hex(hex_str[i]);
        if (hex_val == INVALID_BYTE) return INVALID_INT;

        // Check for overflow
        if (number > (INT_MAX - hex_val) / 16) return INVALID_INT;

        number = number * 16 + hex_val;
    }

    return negative ? -number : number;
}