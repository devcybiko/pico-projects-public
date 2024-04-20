#include "Gpio.h"

static void reset() {
    Gpio *this = _THAT_;
    gpio_init(this->pin);
    gpio_set_dir(this->pin, this->dir ? GPIO_OUT : GPIO_IN);
}

static GpioClass _class;

GpioClass *GpioClass_init(GpioClass *class) {
    if (class->super) return &_class;
    class->super = GObjClass_init(class);
    class->reset = reset;
    return &_class;
}

Gpio *Gpio_new(Gpio *this, char *name, uint pin, int dir) {
    if (!this) this = calloc(1, sizeof(Gpio));
    GObj_new(this, name); // initialize the parent object
    this->class = GpioClass_init(&_class);
    this->pin = pin;
    this->dir = dir;
    return this;
}
