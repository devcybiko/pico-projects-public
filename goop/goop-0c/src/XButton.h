#ifndef __XButton__
#define __XButton__

#include "GpioInput.h"

#define XButton_MEMBERS \
    GpioInput_MEMBERS \
    int wasPressed; \
    int (*isPressed)(); \
    int (*isReleased)(); \
    int (*isClicked)();

typedef struct XButton {
    XButton_MEMBERS
} XButton;

extern XButton *XButton_new(XButton *this, char *name, int pin);

#endif // __XButton__