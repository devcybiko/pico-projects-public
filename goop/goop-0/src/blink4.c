
#include "pico/stdlib.h"

const uint BOARD_LED = PICO_DEFAULT_LED_PIN;
const uint RED_LED = 6;
const uint GREEN_LED = 7;
const uint YELLOW_LED = 8;

int board_state = 0;
int red_state = 0;
int green_state = 0;
int yellow_state = 0;

int board_delay = 250;
int red_delay = 500;
int green_delay = 1000;
int yellow_delay = 2000;

void init_leds() {
    gpio_init(BOARD_LED);
    gpio_set_dir(BOARD_LED, GPIO_OUT);
    gpio_init(RED_LED);
    gpio_set_dir(RED_LED, GPIO_OUT);
    gpio_init(GREEN_LED);
    gpio_set_dir(GREEN_LED, GPIO_OUT);
    gpio_init(YELLOW_LED);
    gpio_set_dir(YELLOW_LED, GPIO_OUT);
}

int blink_led(int led_pin, int delay, int state) {
    sleep_ms(delay);
    gpio_put(led_pin, state);
    return !state;
}
int main()
{
    init_leds();
    while (true) {
        board_state = blink_led(BOARD_LED, board_delay, board_state);
        red_state = blink_led(RED_LED, red_delay, red_state);
        green_state = blink_led(GREEN_LED, green_delay, green_state);
        yellow_state = blink_led(YELLOW_LED, yellow_delay, yellow_state);
    }
}
