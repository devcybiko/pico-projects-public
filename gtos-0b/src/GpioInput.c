#include "GpioInput.h"

static int get() {
    GpioInput *this = _THIS_;
    return gpio_get(this->pin);;
}

GpioInput *GpioInput_new(GpioInput *this, char *name, int pin) {
    if (!this) this = calloc(1, sizeof(GpioInput));
    Gpio_new(this, name, pin, 0); // initialize the parent object as input
    this->get = get;
    return this;
}
