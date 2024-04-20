#include "Led.h"

Led *_THIS_;

static uint32_t now() {
    return time_us_64() / 1000;
}

void Led_init() {
    Led *this = _THIS_;
    gpio_init(this->pin);
    gpio_set_dir(this->pin, GPIO_OUT);
    gpio_put(this->pin, this->state);
}

void Led_blink() {
    Led *this = _THIS_;
    if (now() < this->lastTime + this->delay) return;
    this->lastTime = now();
    // sleep_ms(this->delay);
    this->state = !this->state;
    gpio_put(this->pin, this->state);
}

Led *Led_new(uint pin, int delay) {
    Led *this = calloc(1, sizeof(Led));
    this->pin = pin;
    this->state = 0;
    this->delay = delay;
    this->lastTime = now();
    this->init = Led_init;
    this->blink = Led_blink;
    _(this)->init();
    return this;
}
