#include "Pwm.h"

static uint32_t now() {
    return time_us_64() / 1000;
}

void Pwm_blink() {
    Pwm *this = _THIS_;
    if (now() < this->lastTime + this->delay) return;
    this->lastTime = now();
    this->state = !this->state;
    this->delay = this->state ? pwm->delayOn : pwm->delayOff;
    if (this->delay) gpio_put(this->pin, this->state);
}

void Pwm_setDutyCycle(int dutyCycle) {
    Pwm *this = _THIS_;
    this->delayOn = this->cycles * dutyCycle / 10;
    this->delayOff = this->cycles - this->delayOn;
    this->dutyCycle = dutyCycle;
    this->delay = this->state ? this->delayOn : this->delayOff;
}

Pwm *Pwm_new(Pwm *this, uint pin, int dutyCycle) {
    if (!this) this = calloc(1, sizeof(Pwm));
    Led_new((Led *) pwm, pin, 0);
    this->blink = Pwm_blink; // overiding

    // PWM initialization
    this->cycles = 10;
    this->setDutyCycle = Pwm_setDutyCycle;
    _(this)->setDutyCycle(dutyCycle);
    return this;
}
