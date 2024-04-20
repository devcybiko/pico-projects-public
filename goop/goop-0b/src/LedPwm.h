#ifndef __LedPwm__
#define __LedPwm__

#include "LedBlink.h"

typedef struct LedPwm {
    char *name;
    void (*debug)(char *msg);
    void (*delete)();
    uint pin;
    int dir;
    void (*reset)();
    void (*set)(int value); // notice you cannot "get" from an output
    int state;
    int delay;
    int lastTime;
    void (*blink)();
    int cycles;
    int dutyCycle;
    int delayOn;
    int delayOff;
    void (*setDutyCycle)(int dutyCycle);
} LedPwm;

extern LedPwm *LedPwm_new(LedPwm *this, char *name, uint pin, int dutyCycle);

#endif // __LedPwm__