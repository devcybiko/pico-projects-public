#include "GpioOutput.h"

static void set(int value) {
    GpioOutput *this = _THIS_;
    gpio_put(this->pin, value);
}

GpioOutput *GpioOutput_new(GpioOutput *this, char *name, int pin) {
    if (!this) this = calloc(1, sizeof(GpioOutput));
    Gpio_new(this, name, pin, 1); // initialize the parent object as output
    this->set = set;
    return this;
}
