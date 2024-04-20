#include "GpioOutput.h"

static void set(int value) {
    GpioOutput *this = _THAT_;
    gpio_put(this->pin, value);
}

static GpioOutputClass _class;

GpioOutputClass *GpioOutputClass_init(GpioOutputClass *class) {
    if (class->super) return &_class;
    class->super = GpioClass_init(class);
    class->set = set;
    return &_class;
}

GpioOutput *GpioOutput_new(GpioOutput *this, char *name, int pin) {
    if (!this) this = calloc(1, sizeof(GpioOutput));
    Gpio_new(this, name, pin, 1); // initialize the parent object as output
    this->class = GpioOutputClass_init(&_class);
    return this;
}
