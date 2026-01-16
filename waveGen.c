#include "waveGen.h"

volatile uint8_t* active_pin_reg = 0;
volatile uint8_t* active_port_reg = 0;
volatile uint8_t active_pin_mask = 0;
volatile uint32_t interrupts_remaining = 0;

ISR(TIMER1_COMPA_vect){
        *active_pin_reg = active_pin_mask;
        if(interrupts_remaining>0)
                interrupts_remaining--;
        if(interrupts_remaining==0)
                noTone();
}

void tone(volatile uint16_t frequency,volatile uint32_t duration,volatile uint8_t pin){
        pinmap_t p = digital_pin_table[pin];
        *(p.ddr) |= p.bitmask;

        active_pin_reg = p.pin_reg;
        active_port_reg = p.port;       
        active_pin_mask = p.bitmask;

        uint32_t interrupts_needed = duration*(frequency*2)/1000;
        interrupts_remaining = interrupts_needed;

        TCNT1 = 0;
        TCCR1A = 0;
        TCCR1B = 0;
        TCCR1B |= (1<<WGM12);
        TCCR1B |= (1<<CS11);
        OCR1A = (F_CPU/(2*8*frequency))-1;
        TIMSK1 |= (1<<OCIE1A);
        sei();




}

void noTone(void){
        TIMSK1 &= ~(1<<OCIE1A);
        TCCR1A = 0;
        TCCR1B = 0;
        *active_port_reg &= ~(active_pin_mask);

        interrupts_remaining = 0;
        active_pin_mask=0;
        active_pin_reg=0;                
        active_port_reg=0;

}