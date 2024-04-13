#include "LedPwm.h"

static void blink() {
    LedPwm *this = _THIS_;
    if (now() < this->lastTime + this->delay) return;
    this->lastTime = now();
    this->state = !this->state;
    this->delay = this->state ? this->delayOn : this->delayOff;
    if (this->delay) _(this)->set(this->state);

}

static void setDutyCycle(int dutyCycle) {
    LedPwm *this = _THIS_;
    this->delayOn = this->cycles * dutyCycle / 10;
    this->delayOff = this->cycles - this->delayOn;
    this->dutyCycle = dutyCycle;
    this->delay = this->state ? this->delayOn : this->delayOff;
}

LedPwm *LedPwm_new(LedPwm *this,char *name, uint pin, int dutyCycle) {
    if (!this) this = calloc(1, sizeof(LedPwm));
    LedBlink_new(this, name, pin, 0);
    this->blink = blink; // overriding
    this->cycles = 10;
    this->setDutyCycle = setDutyCycle;
    _(this)->setDutyCycle(dutyCycle);
    return this;
}
