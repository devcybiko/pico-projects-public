#include "LedBlink.h"
#include "LedPwm.h"
#include "XButton.h"

int dutyCycle = 0;
int dutyCycleDir = 1;
bool buttonState = false;

void updateDutyCycle(LedPwm *red) {
     dutyCycle += dutyCycleDir;
    if ((dutyCycle >= 5) || (dutyCycle <=0)) dutyCycleDir = -dutyCycleDir;
    _(red)->setDutyCycle(dutyCycle);
    printf("dutyCycle: %d, dutyCycleDir=%d\n", dutyCycle, dutyCycleDir);
}

int main()
{
    stdio_init_all();

    printf("Hello World\n");

    LedPwm *red = LedPwm_new(NULL, "RED", 6, dutyCycle);
    LedBlink *green = LedBlink_new(NULL, "GREEN", 7, 500);
    LedBlink *yellow = LedBlink_new(NULL, "YELLOW", 8, 250);
    XButton *button = XButton_new(NULL, "Button", 5);
    while (true) {
        _(red)->blink();
        _(green)->blink();
        _(yellow)->blink();
        if (_(button)->isClicked()) updateDutyCycle(red);
    }
}
