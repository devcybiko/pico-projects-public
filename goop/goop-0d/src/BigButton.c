#include "BigButton.h"

static int method1() {
    BigButton *this = _THAT_;
    return 0;
}

static int method2() {
    BigButton *this = _THAT_;
    return 0;
}

static BigButtonClass _class;

BigButtonClass *BigButtonClass_init(BigButtonClass *class) {
    if (class->super) return &_class;
    class->super = XButtonClass_init(class);
    class->method1 = method1;
    class->method2 = method2;
    return &_class;
}

BigButton *BigButton_new(BigButton *this, int value1, int value2) {
    if (!this) this = calloc(1, sizeof(BigButton));
    XButton_new(this, value1); // initialize the parent object
    this->class = BigButtonClass_init(&_class);
    this->member1 = value1;
    this->member2 = value2;
    return this;
}
