#ifndef __Xyzzy__
#define __Xyzzy__

#include "SUPER.h"

#define Xyzzy_MEMBERS \
    SUPER_MEMBERS \
    int member1; \
    int member2; \

#define Xyzzy_METHODS \
    SUPER_METHODS \
    int (*method1)(); \
    int (*method2)();

typedef struct XyzzyClass {
    SUPERClass *super;
    Xyzzy_METHODS
} XyzzyClass;

typedef struct Xyzzy {
    XyzzyClass *class;
    Xyzzy_MEMBERS
} Xyzzy;

extern Xyzzy *Xyzzy_new(Xyzzy *this, int value1, int value2);
extern XyzzyClass *XyzzyClass_init(XyzzyClass *class);

#endif // __Xyzzy__