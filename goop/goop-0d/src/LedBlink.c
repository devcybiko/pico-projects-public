#include "LedBlink.h"

static void blink() {
    LedBlink *this = _THAT_;
    if (now() < this->lastTime + this->delay) return;
    this->lastTime = now();
    this->state = !this->state;
    _(this)->set(this->state);
}

static LedBlinkClass _class;

LedBlink *LedBlinkClass_init(LedBlinkClass *class) {
    if (class->super) return &_class;
    class->super = GpioOutputClass_init(class);
    class->blink = blink;
    return &_class;
}

LedBlink *LedBlink_new(LedBlink *this, char *name, uint pin, int delay) {
    if (!this) this = calloc(1, sizeof(LedBlink));
    GpioOutput_new(this, name, pin); // initialize the parent object as output
    this->class = LedBlinkClass_init(&_class);
    this->state = 0;
    this->delay = delay;
    this->lastTime = now();
    return this;
}
