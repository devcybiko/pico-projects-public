#include "GObj.h"

static void debug(char *msg) {
    GObj *this = _THAT_;
    printf("%s: %s\n", this->name, msg);
}

static void delete() {
    GObj *this = _THAT_;
    free(this);
}

static GObjClass _class;

GObjClass *GObjClass_init(GObjClass *class) {
    class->super = NULL;
    class->debug = debug;
    class->delete = delete;
    return &_class;
}

GObj *GObj_new(GObj *this, char *name) {
    if (!this) this = calloc(1, sizeof(GObj));
    this->class = GObjClass_init(&_class);
    this->name = name;
    return this;
}
