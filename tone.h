#ifndef TONE
#define TONE

#include "util.h"

#define TONE_INFINITE UINT32_MAX

void tone(uint16_t frequency, uint32_t duration, uint8_t pin);
void noTone(void); 


#endif 
