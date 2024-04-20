#include "XButton.h"

static int isPressed() {
    XButton *this = _THAT_;
    return _(this)->get();
}
static int isReleased() {
    XButton *this = _THAT_;
    return !_(this)->get();
}
static int isClicked() {
    XButton *this = _THAT_;
    int clicked = 0;
    if (!this->wasPressed && _(this)->isPressed()) {
        this->wasPressed = 1;
    } else if (this->wasPressed && _(this)->isReleased()) {
        this->wasPressed = 0;
        clicked = 1;
    }
    return clicked;
}

static XButtonClass _class;

XButton *XButtonClass_init(XButtonClass *class) {
    if (class->super) return &_class;
    class->super = GpioInputClass_init(class);
    class->isClicked = isClicked;
    class->isPressed = isPressed;
    class->isReleased = isReleased;
    return &_class;
}

XButton *XButton_new(XButton *this, char *name, int pin) {
    if (!this) this = calloc(1, sizeof(XButton));
    GpioInput_new(this, name, pin); // initialize the parent object as input
    this->class = XButtonClass_init(&_class);
    return this;
}
