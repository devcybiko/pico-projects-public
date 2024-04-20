#ifndef __BigButton__
#define __BigButton__

#include "XButton.h"

#define BigButton_MEMBERS \
    XButton_MEMBERS \
    int member1; \
    int member2; \

#define BigButton_METHODS \
    XButton_METHODS \
    int (*method1)(); \
    int (*method2)();

typedef struct BigButtonClass {
    XButtonClass *super;
    BigButton_METHODS
} BigButtonClass;

typedef struct BigButton {
    BigButtonClass *class;
    BigButton_MEMBERS
} BigButton;

extern BigButton *BigButton_new(BigButton *this, int value1, int value2);
extern BigButtonClass *BigButtonClass_init(BigButtonClass *class);

#endif // __BigButton__