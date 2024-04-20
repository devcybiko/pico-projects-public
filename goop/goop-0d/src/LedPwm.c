#include "LedPwm.h"

static void blink() {
    LedPwm *this = _THAT_;
    _(this)->super->blink();
    this->delay = this->state ? this->delayOn : this->delayOff;
    if (this->delay) _(this)->set(this->state);
}

static void setDutyCycle(int dutyCycle) {
    LedPwm *this = _THAT_;
    this->delayOn = this->cycles * dutyCycle / 10;
    this->delayOff = this->cycles - this->delayOn;
    this->dutyCycle = dutyCycle;
    this->delay = this->state ? this->delayOn : this->delayOff;
}

static LedPwmClass _class;

LedPwm *LedPwmClass_init(LedPwmClass *class) {
    if (class->super) return &_class;
    class->super = LedBlinkClass_init(class);
    class->blink = blink; // override
    class->setDutyCycle = setDutyCycle;
    return &_class;
}

LedPwm *LedPwm_new(LedPwm *this,char *name, uint pin, int dutyCycle) {
    if (!this) this = calloc(1, sizeof(LedPwm));
    LedBlink_new(this, name, pin, 0);
    this->class = LedPwmClass_init(&_class);
    this->cycles = 10;
    _(this)->setDutyCycle(dutyCycle);
    return this;
}
