#ifndef UTIL
#define UTIL


#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

typedef struct  {
    volatile uint8_t* ddr; // data direction register
    volatile uint8_t* port; // port register, can write any value
    volatile uint8_t* pin_reg; // pin register, value inverts when one is written
    uint8_t bitmask;
} pinmap_t; //for easier pin definitions


extern pinmap_t digital_pin_table[14];
#endif

