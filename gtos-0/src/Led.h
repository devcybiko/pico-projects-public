#ifndef __Led__
#define __Led__

#include "pico/stdlib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Led {
    uint pin;
    int state;
    int delay;
    int lastTime;
    void (*init)();
    void (*blink)();
} Led;

extern Led *_THIS_;
#define _(OBJ) (_THIS_=OBJ, (OBJ))

extern Led *Led_new(uint pin, int delay);

#endif // __Led__