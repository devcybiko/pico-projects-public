#ifndef __GpioOutput__
#define __GpioOutput__

#include "Gpio.h"

#define GpioOutput_MEMBERS \
    Gpio_MEMBERS \
    void (*set)(int value);

typedef struct GpioOutput {
    GpioOutput_MEMBERS
} GpioOutput;

extern GpioOutput *GpioOutput_new(GpioOutput *this, char *name, int pin);

#endif // __GpioOutput__