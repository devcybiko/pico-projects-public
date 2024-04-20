#ifndef __XButton__
#define __XButton__

#include "GpioInput.h"

typedef struct XButton {
    char *name;
    void (*debug)(char *msg);
    void (*delete)();
    uint pin;
    int dir;
    void (*reset)();
    int (*get)();
    int wasPressed;
    int (*isPressed)();
    int (*isReleased)();
    int (*isClicked)();
} XButton;

extern XButton *XButton_new(XButton *this, char *name, int pin);

#endif // __XButton__