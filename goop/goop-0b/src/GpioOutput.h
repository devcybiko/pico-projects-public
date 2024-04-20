#ifndef __GpioOutput__
#define __GpioOutput__

#include "Gpio.h"

typedef struct GpioOutput {
    char *name;
    void (*debug)(char *msg);
    void (*delete)();
    uint pin;
    int dir;
    void (*reset)();
    void (*set)(int value); // notice you cannot "get" from an output
} GpioOutput;

extern GpioOutput *GpioOutput_new(GpioOutput *this, char *name, int pin);

#endif // __GpioOutput__