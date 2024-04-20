
#include "pico/stdlib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Led {
    uint pin;
    int state;
    int delay;
} Led;

void led_init(Led *led) {
    gpio_init(led->pin);
    gpio_set_dir(led->pin, GPIO_OUT);
}

Led *led_new(uint pin, int delay) {
    Led *new_led = calloc(1, sizeof(Led));
    new_led->pin = pin;
    new_led->state = 0;
    new_led->delay = delay;
    led_init(new_led);
    return new_led;
}

void led_blink(Led *led) {
    sleep_ms(led->delay);
    gpio_put(led->pin, led->state);
    led->state = !led->state;
}

int main()
{
    Led *board_led = led_new(PICO_DEFAULT_LED_PIN, 250);
    Led *red = led_new(6, 500);
    Led *green = led_new(7, 1000);
    Led *yellow = led_new(8, 2000);
    while (true) {
        led_blink(board_led);
        led_blink(red);
        led_blink(green);
        led_blink(yellow);
    }
}
