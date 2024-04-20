#ifndef __LedBlink__
#define __LedBlink__

#include "GpioOutput.h"

#define LedBlink_MEMBERS \
    GpioOutput_MEMBERS \
    int state; \
    int delay; \
    int lastTime; \

#define LedBlink_METHODS \
    GpioOutput_METHODS \
    void (*blink)();

typedef struct LedBlinkClass {
    GpioOutputClass *super;
    LedBlink_METHODS
} LedBlinkClass;

typedef struct LedBlink {
    LedBlinkClass *class;
    LedBlink_MEMBERS
} LedBlink;

extern LedBlink *LedBlink_new(LedBlink *this, char *name, uint pin, int delay);
extern LedBlink *LedBlinkClass_init(LedBlinkClass *class);

#endif // __LedBlink__