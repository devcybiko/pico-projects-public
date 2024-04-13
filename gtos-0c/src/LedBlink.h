#ifndef __LedBlink__
#define __LedBlink__

#include "GpioOutput.h"

#define LedBlink_MEMBERS \
    GpioOutput_MEMBERS \
    int state; \
    int delay; \
    int lastTime; \
    void (*blink)();

typedef struct LedBlink {
    LedBlink_MEMBERS
} LedBlink;

extern LedBlink *LedBlink_new(LedBlink *this, char *name, uint pin, int delay);

#endif // __LedBlink__