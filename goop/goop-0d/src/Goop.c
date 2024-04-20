#include "Goop.h"

void *_THAT_; // Global variable to store the current object

uint32_t now() {
    return time_us_64() / 1000;
}
