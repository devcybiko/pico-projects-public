#ifndef __Gpio__
#define __Gpio__

#include "GObj.h"

#define Gpio_MEMBERS \
    GObj_MEMBERS \
    uint pin; \
    int dir; \
    void (*reset)();

typedef struct Gpio {
    Gpio_MEMBERS
} Gpio;

extern Gpio *Gpio_new(Gpio *this, char *name, uint pin, int dir);

#endif // __Gpio__