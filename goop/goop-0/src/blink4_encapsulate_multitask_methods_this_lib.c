#include "Led.h"

int main()
{
    Led *board_led = Led_new(PICO_DEFAULT_LED_PIN, 125);
    Led *red = Led_new(6, 250);
    Led *green = Led_new(7, 500);
    Led *yellow = Led_new(8, 1000);
    while (true) {
        _(board_led)->blink();
        _(red)->blink();
        _(green)->blink();
        _(yellow)->blink();
    }
}
