#pragma once

/* Types */
typedef __builtin_va_list va_list;

/* Defines */
#define va_start(ap, ...)  __builtin_va_start(ap, __VA_ARGS__)
#define va_end(ap)         __builtin_va_end(ap)
#define va_arg(ap, type)   __builtin_va_arg(ap, type)
#define va_copy(dest, src) __builtin_va_copy(dest, src)