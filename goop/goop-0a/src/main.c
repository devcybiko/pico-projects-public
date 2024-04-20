#include "Led.h"
#include "Pwm.h"
#include "pico_button.h"

int main()
{
    stdio_init_all();
    int dutyCycle = 0;
    int dutyCycleDir = 1;
    bool buttonState = false;

    printf("Hello World\n");

    Pwm *redPWM = Pwm_new(NULL, 6, dutyCycle);
    Led *redLED = &(redPWM->led);
    Led *green = Led_new(NULL, 7, 500);
    while (true) {
        _(redLED)->blink();
        _(green)->blink();
        if (get_bootsel_button()) {
            buttonState = true;
        }
        if (!get_bootsel_button() && buttonState) {
            buttonState = false;
            dutyCycle += dutyCycleDir;
            if ((dutyCycle >= 5) || (dutyCycle <=0)) dutyCycleDir = -dutyCycleDir;
            _(redPWM)->setDutyCycle(dutyCycle);
            printf("dutyCycle: %d, dutyCycleDir=%d\n", dutyCycle, dutyCycleDir);
        }
    }
}
