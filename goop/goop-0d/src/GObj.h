#ifndef __GObj__
#define __GObj__

#include "Goop.h"

#define GObj_MEMBERS \
    char *name; \

#define GObj_METHODS \
    void (*debug)(char *msg); \
    void (*delete)();

typedef struct GObjClass {
    void *super;
    GObj_METHODS
} GObjClass;

typedef struct GObj {
    GObjClass *class;
    GObj_MEMBERS
} GObj;

extern GObj *GObj_new(GObj *this, char *name);
extern GObjClass *GObjClass_init(GObjClass *class);

#endif // __GObj__