#ifndef __GObj__
#define __GObj__

#include "pico/stdlib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

extern void *_THIS_;
#define _(OBJ) (_THIS_=OBJ, (OBJ))

extern uint32_t now();

#define GObj_MEMBERS \
    char *name; \
    void (*debug)(char *msg); \
    void (*delete)();

typedef struct GObj {
    GObj_MEMBERS
} GObj;

extern GObj *GObj_new(GObj *this, char *name);

#endif // __GObj__