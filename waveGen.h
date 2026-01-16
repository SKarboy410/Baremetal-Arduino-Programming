#ifndef WAVEGEN
#define WAVEGEN

#include "util.h"

void tone(volatile uint16_t frequency,volatile uint32_t duration,volatile uint8_t pin);
void noTone(void); 


#endif 
