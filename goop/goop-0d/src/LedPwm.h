#ifndef __LedPwm__
#define __LedPwm__

#include "LedBlink.h"

#define LedPwm_MEMBERS \
    LedBlink_MEMBERS \
    int cycles; \
    int dutyCycle; \
    int delayOn; \
    int delayOff; \

#define LedPwm_METHODS \
    LedBlink_METHODS \
    void (*setDutyCycle)(int dutyCycle);

typedef struct LedPwmClass {
    LedBlinkClass *super;
    LedPwm_METHODS
} LedPwmClass;

typedef struct LedPwm {
    LedPwmClass *class;
    LedPwm_MEMBERS
} LedPwm;

extern LedPwm *LedPwm_new(LedPwm *this, char *name, uint pin, int dutyCycle);
extern LedPwm *LedPwmClass_init(LedPwmClass *class);

#endif // __LedPwm__