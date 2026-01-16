#ifndef UTIL
#define UTIL


#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

typedef struct  {
    volatile uint8_t* ddr;
    volatile uint8_t* port;
    volatile uint8_t* pin_reg;
    uint8_t bitmask;
} pinmap_t;


extern pinmap_t digital_pin_table[14];
#endif

