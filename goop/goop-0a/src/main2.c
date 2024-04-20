#include "Led.h"
#include "Pwm2.h"
#include "pico_button.h"

int main()
{
    stdio_init_all();
    int dutyCycle = 0;
    int dutyCycleDir = 1;
    bool buttonState = false;

    printf("Hello World\n");

    Pwm *red = Pwm_new(NULL, 6, dutyCycle);
    Led *green = Led_new(NULL, 7, 500);
    Led *yellow = Led_new(NULL, 8, 250);
    while (true) {
        _(red)->blink();
        _(green)->blink();
        _(yellow)->blink();
        if (get_bootsel_button()) {
            buttonState = true;
        }
        if (!get_bootsel_button() && buttonState) {
            buttonState = false;
            dutyCycle += dutyCycleDir;
            if ((dutyCycle >= 5) || (dutyCycle <=0)) dutyCycleDir = -dutyCycleDir;
            _(red)->setDutyCycle(dutyCycle);
            printf("dutyCycle: %d, dutyCycleDir=%d\n", dutyCycle, dutyCycleDir);
        }
    }
}
