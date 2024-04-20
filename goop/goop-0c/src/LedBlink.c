#include "LedBlink.h"

static void blink() {
    LedBlink *this = _THIS_;
    if (now() < this->lastTime + this->delay) return;
    this->lastTime = now();
    this->state = !this->state;
    _(this)->set(this->state);
}

LedBlink *LedBlink_new(LedBlink *this, char *name, uint pin, int delay) {
    if (!this) this = calloc(1, sizeof(LedBlink));
    GpioOutput_new(this, name, pin); // initialize the parent object as output
    this->state = 0;
    this->delay = delay;
    this->lastTime = now();
    this->blink = blink;
    return this;
}
