#include "Pwm.h"

static uint32_t now() {
    return time_us_64() / 1000;
}

void Pwm_blink() {
    Pwm *pwm = _THIS_;
    if (now() < pwm->led.lastTime + pwm->led.delay) return;
    pwm->led.lastTime = now();
    pwm->led.state = !pwm->led.state;
    pwm->led.delay = pwm->led.state ? pwm->delayOn : pwm->delayOff;
    if (pwm->led.delay) gpio_put(this->led.pin, this->led.state);
}

void Pwm_setDutyCycle(int dutyCycle) {
    Pwm *this = _THIS_;
    this->delayOn = this->cycles * dutyCycle / 10;
    this->delayOff = this->cycles - this->delayOn;
    this->dutyCycle = dutyCycle;
    this->led.delay = this->led.state ? this->delayOn : this->delayOff;
}

Pwm *Pwm_new(Pwm *this, uint pin, int dutyCycle) {
    if (!this) this = calloc(1, sizeof(Pwm));
    Led *led = &(this->led);
    Led_new(led, pin, 0);
    this->led.blink = Pwm_blink; // overriding

    // PWM initialization
    this->cycles = 10;
    this->setDutyCycle = Pwm_setDutyCycle;
    _(this)->setDutyCycle(dutyCycle);
    return this;
}
