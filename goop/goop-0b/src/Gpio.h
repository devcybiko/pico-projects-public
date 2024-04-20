#ifndef __Xyzzy__
#define __Xyzzy__

#include "GObj.h"

typedef struct Xyzzy {
    char *name;
    void (*debug)(char *msg);
    void (*delete)();
    uint pin;
    int dir;
    void (*reset)();
} Xyzzy;

extern Xyzzy *new(Xyzzy *this, char *name, uint pin, int dir);

#endif // __Xyzzy__