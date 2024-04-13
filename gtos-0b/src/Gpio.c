#include "Gpio.h"

static void reset() {
    Gpio *this = _THIS_;
    gpio_init(this->pin);
    gpio_set_dir(this->pin, this->dir ? GPIO_OUT : GPIO_IN);
}

Gpio *Gpio_new(Gpio *this, char *name, uint pin, int dir) {
    if (!this) this = calloc(1, sizeof(Gpio));
    GObj_new(this, name); // initialize the parent object
    this->pin = pin;
    this->dir = dir;
    this->reset = reset;
    _(this)->reset();
    return this;
}
