#ifndef __GpioInput__
#define __GpioInput__

#include "Gpio.h"

#define GpioInput_MEMBERS \
    Gpio_MEMBERS \

#define GpioInput_METHODS \
    Gpio_METHODS \
    int (*get)();

typedef struct GpioInputClass {
    GpioClass *super;
    GpioInput_METHODS
} GpioInputClass;

typedef struct GpioInput {
    GpioClass *class;
    GpioInput_MEMBERS
} GpioInput;

extern GpioInput *GpioInput_new(GpioInput *this, char *name, int pin);
extern GpioInputClass *GpioInputClass_init(GpioInputClass *class);

#endif // __GpioInput__