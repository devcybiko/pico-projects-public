#ifndef __XButton__
#define __XButton__

#include "GpioInput.h"

#define XButton_MEMBERS \
    GpioInput_MEMBERS \
    int wasPressed; \

#define XButton_METHODS \
    GpioInput_METHODS \
    int (*isPressed)(); \
    int (*isReleased)(); \
    int (*isClicked)();

typedef struct XButtonClass {
    GpioInputClass *super;
    XButton_METHODS
} XButtonClass;

typedef struct XButton {
    XButtonClass *class;
    XButton_MEMBERS
} XButton;

extern XButton *XButton_new(XButton *this, char *name, int pin);
extern XButton *XButtonClass_init(XButtonClass *class);

#endif // __XButton__