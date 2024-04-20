#ifndef __GpioInput__
#define __GpioInput__

#include "Gpio.h"

typedef struct GpioInput {
    char *name;
    void (*debug)(char *msg);
    void (*delete)();
    uint pin;
    int dir;
    void (*reset)();
    int (*get)(); // notice you cannot "set" an input
} GpioInput;

extern GpioInput *GpioInput_new(GpioInput *this, char *name, int pin);

#endif // __GpioInput__