#include "extern_storage_class.h"
#include <stdio.h>

extern int x;

extern int y;

void foo(void) {
    printf("value of x before modifiying in foo = %d\n", x);
    x += 10;
    printf("value of x after modifiying in foo = %d\n", x);

    printf("value of y before modifiying in foo = %d\n", y);
    y /= 10;
    printf("value of y after modifiying in foo = %d\n", y);

}

