#ifndef __Goop__
#define __Goop__

#include "pico/stdlib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern void *_THAT_;
#define _(OBJ) (_THAT_=OBJ, (OBJ->class))
#define __(OBJ) (_THAT_=OBJ, (OBJ->class->super))

extern uint32_t now();

#endif // __Goop__