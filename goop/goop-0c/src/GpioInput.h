#ifndef __GpioInput__
#define __GpioInput__

#include "Gpio.h"

#define GpioInput_MEMBERS \
    Gpio_MEMBERS \
    int (*get)();

typedef struct GpioInput {
    GpioInput_MEMBERS
} GpioInput;

extern GpioInput *GpioInput_new(GpioInput *this, char *name, int pin);

#endif // __GpioInput__