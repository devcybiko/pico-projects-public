#ifndef __Pwm__
#define __Pwm__

#include "pico/stdlib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Led.h"

typedef struct Pwm {
    Led led;
    int cycles;
    int dutyCycle;
    int delayOn;
    int delayOff;
    void (*setDutyCycle)(int dutyCycle);
} Pwm;

extern Pwm *Pwm_new(Pwm *this, uint pin, int dutyCycle);
extern void Pwm_setDutyCycle(int dutyCycle);
#endif // __Pwm__