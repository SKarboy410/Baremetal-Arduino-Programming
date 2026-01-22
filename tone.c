#include "tone.h"


volatile uint8_t* active_pin_reg = 0;
volatile uint8_t* active_port_reg = 0;
volatile uint8_t active_pin_mask = 0;
volatile uint32_t interrupts_remaining = 0;

volatile uint8_t busy_flag = 0;

ISR(TIMER1_COMPA_vect){
        *active_pin_reg = active_pin_mask; 
        if(interrupts_remaining == TONE_INFINITE)
                return;
        
        interrupts_remaining--;
        if(interrupts_remaining==0)
                noTone();
        
}

void tone(uint16_t frequency, uint32_t duration, uint8_t pin){
        cli(); // clear global interrupts
        if(busy_flag ==1 ){
                sei(); // set enable interrupts
                return;
        }
        
        busy_flag = 1;

        pinmap_t p = digital_pin_table[pin];
        *(p.ddr) |= p.bitmask;

        active_pin_reg = p.pin_reg;
        active_port_reg = p.port;       
        active_pin_mask = p.bitmask;
 
        uint32_t interrupts_needed = duration*(frequency*2)/1000;
        if(duration > 0)
                interrupts_remaining = interrupts_needed;
        else
           interrupts_remaining = TONE_INFINITE;

        TCNT1 = 0; //set timer to 0
        TCCR1A = 0; // timer control register 
        TCCR1B = 0; 
        TCCR1B |= (1<<WGM12); // to set to CTC mode
        TCCR1B |= (1<<CS11); // set prescaler value
        OCR1A = (F_CPU/(2*8*frequency))-1; // compare value
        TIMSK1 |= (1<<OCIE1A); // set compare interrupt
        sei(); // set enable interrupt

        


}

void noTone(void){
        cli();
        TIMSK1 &= ~(1<<OCIE1A); // disable compare interrupt
        TCCR1A = 0; 
        TCCR1B = 0;
        *active_port_reg &= ~(active_pin_mask);
        
        //set everything to 0
        interrupts_remaining = 0;
        active_pin_mask=0;
        active_pin_reg=0;                
        active_port_reg=0;
        busy_flag = 0;

        sei();

}