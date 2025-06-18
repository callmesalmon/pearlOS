/*
 * Copyright (c) Salmon 2025 under the Hippocratic 3.0 license.
 * If your copy of this program doesn't include the license, it is
 * available to read at:
 * 
 *     <https://firstdonoharm.dev/version/3/0/core.txt>
 */

#include <cpu/timer.h>
#include <kernel/cmd/time.h>
#include <lib/string.h>
#include <lib/num.h>

void set_time(uint32_t hours, uint32_t minutes) {
    if (hours >= 24 || minutes >= 60) {
        printf("Invalid time format! Hours must be 0-23, minutes must be 0-59\n");
        return;
    }
    
    current_time.hours = hours;
    current_time.minutes = minutes;
    current_time.seconds = 0;
    current_time.ticks = 0;
}

void time_cmd(char** args) {
    if (args[1] && args[2]) {
        uint32_t hours = str_to_uint8(args[1]);
        uint32_t minutes = str_to_uint8(args[2]);
        
        if (hours >= 24 || minutes >= 60) {
            printf("Invalid time format! Hours must be 0-23, minutes must be 0-59\n");
            return;
        }
        
        set_time(hours, minutes);
        printf("Time set to %02d:%02d:00\n", hours, minutes);
    } else {
        time_t time = get_time();
        printf("Time: %02d:%02d:%02d\n", 
               time.hours, time.minutes, time.seconds);
    }
}
