#include "pico/stdlib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static uint32_t now() {
    return time_us_64() / 1000;
}

typedef struct Led Led;

typedef struct Led {
    uint pin;
    int state;
    int delay;
    int lastTime;
    void (*init)();
    void (*blink)();
} Led;

Led *_THIS_;
#define _(OBJ) (_THIS_=OBJ, (OBJ))

void led_init() {
    Led *this = _THIS_;
    gpio_init(led->pin);
    gpio_set_dir(led->pin, GPIO_OUT);
    gpio_put(led->pin, led->state);
}

void led_blink() {
    Led *this = _THIS_;
    if (now() < led->lastTime + led->delay) return;
    led->lastTime = now();
    // sleep_ms(led->delay);
    led->state = !led->state;
    gpio_put(led->pin, led->state);
    printf("led->pin: %d, led->state: %d, led->delay: %d, led->lastTime: %d\n", led->pin, led->state, led->delay, led->lastTime);
}

Led *led_new(uint pin, int delay) {
    Led *this = _oc(1, sizeof(Led));
    this->pin = pin;
    this->state = 0;
    this->delay = delay;
    this->lastTime = now();
    this->init = led_init;
    this->blink = led_blink;
    this->init(this);
    return this;
}

int main()
{
    Led *board_led = led_new(PICO_DEFAULT_LED_PIN, 250);
    Led *red = led_new(6, 500);
    Led *green = led_new(7, 1000);
    Led *yellow = led_new(8, 2000);
    while (true) {
        _(board_led)->blink();
        _(red)->blink();
        _(green)->blink();
        _(yellow)->blink();
    }
}
