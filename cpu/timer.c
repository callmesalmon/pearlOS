/*
 * Copyright (c) Salmon 2025 under the Hippocratic 3.0 license.
 * If your copy of this program doesn't include the license, it is
 * available to read at:
 * 
 *     <https://firstdonoharm.dev/version/3/0/core.txt>
 */

#include <cpu/timer.h>
#include <cpu/isr.h>

time_t current_time = {0, 0, 0, 0};

void timer_init() { 
    uint16_t divisor = PIT_FREQUENCY / DESIRED_HZ;
    
    port_byte_out(PIT_COMMAND, 0x36);  
    port_byte_out(PIT_CHANNEL0, (uint8_t)(divisor & 0xFF));
    port_byte_out(PIT_CHANNEL0, (uint8_t)((divisor >> 8) & 0xFF));
    
    set_idt_gate(32, (uint32_t)timer_handler);
}

void timer_handler() {
    current_time.ticks++;
    
    if (current_time.ticks >= DESIRED_HZ) { 
        current_time.ticks = 0;
        current_time.seconds++;
        
        if (current_time.seconds >= 60) {
            current_time.seconds = 0;
            current_time.minutes++;
            
            if (current_time.minutes >= 60) {
                current_time.minutes = 0;
                current_time.hours++;
                
                if (current_time.hours >= 24) {
                    current_time.hours = 0;
                }
            }
        }
    }
    
    port_byte_out(0x20, 0x20);  
}

uint32_t get_ticks() {
    return current_time.ticks;
}

time_t get_time() {
    return current_time;
}
