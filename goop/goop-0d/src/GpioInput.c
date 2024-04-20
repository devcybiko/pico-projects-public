#include "GpioInput.h"

static int get() {
    GpioInput *this = _THAT_;
    return gpio_get(this->pin);;
}

static GpioInputClass _class;

GpioInputClass *GpioInputClass_init(GpioInputClass *class) {
    if (class->super) return &_class;
    class->super = GpioClass_init(class);
    class->get = get;
    return &_class;
}

GpioInput *GpioInput_new(GpioInput *this, char *name, int pin) {
    if (!this) this = calloc(1, sizeof(GpioInput));
    Gpio_new(this, name, pin, 0); // initialize the parent object as input
    this->class = GpioInputClass_init(&_class);
    return this;
}
