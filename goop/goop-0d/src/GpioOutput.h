#ifndef __GpioOutput__
#define __GpioOutput__

#include "Gpio.h"

#define GpioOutput_MEMBERS \
    Gpio_MEMBERS \

#define GpioOutput_METHODS \
    GObj_METHODS \
    void (*set)(int value);

typedef struct GpioOutputClass {
    GpioClass *super;
    GpioOutput_METHODS
} GpioOutputClass;

typedef struct GpioOutput {
    GpioClass *class;
    GpioOutput_MEMBERS
} GpioOutput;

extern GpioOutput *GpioOutput_new(GpioOutput *this, char *name, int pin);
extern GpioOutputClass *GpioOutputClass_init(GpioOutputClass *class);

#endif // __GpioOutput__