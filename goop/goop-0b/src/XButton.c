#include "XButton.h"

static int isPressed() {
    XButton *this = _THIS_;
    return _(this)->get();
}
static int isReleased() {
    XButton *this = _THIS_;
    return !_(this)->get();
}
static int isClicked() {
    XButton *this = _THIS_;
    int clicked = 0;
    if (!this->wasPressed && _(this)->isPressed()) {
        this->wasPressed = 1;
    } else if (this->wasPressed && _(this)->isReleased()) {
        this->wasPressed = 0;
        clicked = 1;
    }
    return clicked;
}

XButton *XButton_new(XButton *this, char *name, int pin) {
    if (!this) this = calloc(1, sizeof(XButton));
    GpioInput_new(this, name, pin); // initialize the parent object as input
    this->isClicked = isClicked;
    this->isPressed = isPressed;
    this->isReleased = isReleased;
    return this;
}
