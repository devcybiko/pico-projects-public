#ifndef __LedPwm__
#define __LedPwm__

#include "LedBlink.h"

#define LedPwm_MEMBERS \
    LedBlink_MEMBERS \
    int cycles; \
    int dutyCycle; \
    int delayOn; \
    int delayOff; \
    void (*setDutyCycle)(int dutyCycle);

typedef struct LedPwm {
    LedPwm_MEMBERS
} LedPwm;

extern LedPwm *LedPwm_new(LedPwm *this, char *name, uint pin, int dutyCycle);

#endif // __LedPwm__