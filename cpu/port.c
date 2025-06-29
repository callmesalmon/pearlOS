/*
 * Copyright (c) Salmon 2025 under the Hippocratic 3.0 license.
 * If your copy of this program doesn't include the license, it is
 * available to read at:
 * 
 *     <https://firstdonoharm.dev/version/3/0/core.txt>
 */

#include <cpu/port.h>

/* * * * * * * * * * * * * * * * * * *
 *     The fifth commandment.        *
 * * * * * * * * * * * * * * * * * * *
 * When in peril, and in need of     *
 * assistance, *never* turn to       *
 * the __asm__ keyword. It will      *
 * tempt you, but you must resist    *
 * __asm__'s temptation.             *
 * You shall only use __asm__        *
 * when there's no other way out,    *
 * e.g this a sin:                   *
 *                                   *
 *     byte sin() {                  *
 *         __asm__("call hello");    *
 *     }                             *
 *                                   *
 * But this is completely pure:      *
 *      byte pure(word port) {       *
 *         byte result;              *
 *         __asm__("in %%dx, %%al" \ *
 *          : "=a" (result) \        *
 *          : "d" (port));           *
 *      }                            *
 *                                   *
 * Also some other, less important   *
 * commandments also exist like      *
 * "Don't be racist" and "Don't      *
 * be... Like, a nazi or             *
 * something.", but those are less   *
 * important than these.             *
 * * * * * * * * * * * * * * * * * * */

/* Get from port */
byte port_byte_in(word port) {
    byte result;
    __asm__("in %%dx, %%al" : "=a" (result) : "d" (port));
    return result;
}

/* Send to port */
void port_byte_out(word port, byte data) {
    __asm__("out %%al, %%dx" : : "a" (data), "d" (port));
}

/* Get from port */
word port_word_in(word port) {
    ushort result;
    __asm__("in %%dx, %%ax" : "=a" (result) : "d" (port));
    return result;
}

/* Send to port */
void port_word_out(ushort port, word data) {
    __asm__("out %%ax, %%dx" : : "a" (data), "d" (port));
}