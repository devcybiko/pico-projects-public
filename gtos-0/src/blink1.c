
#include "pico/stdlib.h"

const uint BOARD_LED = PICO_DEFAULT_LED_PIN;

int board_state = 0;

int board_delay = 250;

void init_led() {
    gpio_init(BOARD_LED);
    gpio_set_dir(BOARD_LED, GPIO_OUT);
}

int blink_led(int led_pin, int delay, int state) {
    sleep_ms(delay);
    gpio_put(led_pin, state);
    return !state;
}
int main()
{
    
    init_led();
    while (true) {
     board_state = blink_led(BOARD_LED, board_delay, board_state);
    }
}
