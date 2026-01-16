#include "util.h"

pinmap_t digital_pin_table[14] = {
    {&DDRD,&PORTD,&PIND,(1<<PD0)},
    {&DDRD,&PORTD,&PIND,(1<<PD1)},
    {&DDRD,&PORTD,&PIND,(1<<PD2)},
    {&DDRD,&PORTD,&PIND,(1<<PD3)},
    {&DDRD,&PORTD,&PIND,(1<<PD4)},
    {&DDRD,&PORTD,&PIND,(1<<PD5)},
    {&DDRD,&PORTD,&PIND,(1<<PD6)},
    {&DDRD,&PORTD,&PIND,(1<<PD7)},
    {&DDRB,&PORTB,&PINB,(1<<PB0)},
    {&DDRB,&PORTB,&PINB,(1<<PB1)},
    {&DDRB,&PORTB,&PINB,(1<<PB2)},
    {&DDRB,&PORTB,&PINB,(1<<PB3)},
    {&DDRB,&PORTB,&PINB,(1<<PB4)},
    {&DDRB,&PORTB,&PINB,(1<<PB5)}

};