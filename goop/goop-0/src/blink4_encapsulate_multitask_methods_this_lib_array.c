#include "Led.h"

int main()
{
    Led *leds[4];
    int nleds = 0;
    leds[n++] = Led_new(PICO_DEFAULT_LED_PIN, 125);
    leds[n++] = Led_new(6, 250);
    leds[n++] = Led_new(7, 500);
    leds[n++] = Led_new(8, 1000);
    while (true) {
        for(int i = 0; i < nleds; i++) {
            _(leds[i])->blink();
        }
    }
}
