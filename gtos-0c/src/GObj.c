#include "GObj.h"

void *_THIS_; // Global variable to store the current object

uint32_t now() {
    return time_us_64() / 1000;
}

static void debug(char *msg) {
    GObj *this = _THIS_;
    printf("%s: %s\n", this->name, msg);
}

static void delete() {
    GObj *this = _THIS_;
    free(this);
}

GObj *GObj_new(GObj *this, char *name) {
    if (!this) this = calloc(1, sizeof(GObj));
    this->name = name;
    this->debug = debug;
    this->delete = delete;
    return this;
}
