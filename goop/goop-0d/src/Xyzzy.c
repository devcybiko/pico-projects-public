#include "Xyzzy.h"

static int method1() {
    Xyzzy *this = _THAT_;
    return 0;
}

static int method2() {
    Xyzzy *this = _THAT_;
    return 0;
}

static XyzzyClass _class;

XyzzyClass *XyzzyClass_init(XyzzyClass *class) {
    if (class->super) return &_class;
    class->super = SUPERClass_init(class);
    class->method1 = method1;
    class->method2 = method2;
    return &_class;
}

Xyzzy *Xyzzy_new(Xyzzy *this, int value1, int value2) {
    if (!this) this = calloc(1, sizeof(Xyzzy));
    SUPER_new(this, value1); // initialize the parent object
    this->class = XyzzyClass_init(&_class);
    this->member1 = value1;
    this->member2 = value2;
    return this;
}
