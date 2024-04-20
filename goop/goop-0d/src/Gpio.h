#ifndef __Gpio__
#define __Gpio__

#include "GObj.h"

#define Gpio_MEMBERS \
    GObj_MEMBERS \
    uint pin; \
    int dir; \

#define Gpio_METHODS \
    GObj_METHODS \
    void (*reset)();

typedef struct GpioClass {
    GObjClass *super;
    Gpio_METHODS
} GpioClass;

typedef struct Gpio {
    GpioClass *class;
    Gpio_MEMBERS
} Gpio;

extern Gpio *Gpio_new(Gpio *this, char *name, uint pin, int dir);
extern GpioClass *GpioClass_init(GpioClass *class);

#endif // __Gpio__