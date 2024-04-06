
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
    void (*init)(Led *led);
    void (*blink)(Led *led);
} Led;


void led_init(Led *led) {
    gpio_init(led->pin);
    gpio_set_dir(led->pin, GPIO_OUT);
    gpio_put(led->pin, led->state);
}

void led_blink(Led *led) {
    if (now() < led->lastTime + led->delay) return;
    led->lastTime = now();
    // sleep_ms(led->delay);
    led->state = !led->state;
    gpio_put(led->pin, led->state);
}

Led *led_new(uint pin, int delay) {
    Led *new_led = calloc(1, sizeof(Led));
    new_led->pin = pin;
    new_led->state = 0;
    new_led->delay = delay;
    new_led->lastTime = now();
    new_led->init = led_init;
    new_led->blink = led_blink;
    new_led->init(new_led);
    return new_led;
}

int main()
{
    Led *board_led = led_new(PICO_DEFAULT_LED_PIN, 250);
    Led *red = led_new(6, 500);
    Led *green = led_new(7, 1000);
    Led *yellow = led_new(8, 2000);
    while (true) {
        board_led->blink(board_led);
        red->blink(red);
        green->blink(green);
        yellow->blink(yellow);
    }
}
