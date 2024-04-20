#ifndef __LedBlink__
#define __LedBlink__

#include "GpioOutput.h"

typedef struct LedBlink {
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
} LedBlink;

extern LedBlink *LedBlink_new(LedBlink *this, char *name, uint pin, int delay);

#endif // __LedBlink__