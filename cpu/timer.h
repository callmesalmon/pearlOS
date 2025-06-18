/*
 * Copyright (c) Salmon 2025 under the Hippocratic 3.0 license.
 * If your copy of this program doesn't include the license, it is
 * available to read at:
 * 
 *     <https://firstdonoharm.dev/version/3/0/core.txt>
 */

#pragma once

#include <stddef.h>
#include <stdint.h>
#include <cpu/port.h>

#define PIT_BASE 0x40
#define PIT_COMMAND 0x43
#define PIT_CHANNEL0 0x40
#define PIT_FREQUENCY 1193182  // PIT clock frequency
#define DESIRED_HZ 100         // 100 Hz timer (10ms resolution)

// Time structure
typedef struct {
    uint64_t ticks;
    uint64_t seconds;
    uint64_t minutes;
    uint64_t hours;
} time_t;

extern time_t current_time;

void timer_init();
void timer_handler();
uint64_t get_ticks();
time_t get_time();
