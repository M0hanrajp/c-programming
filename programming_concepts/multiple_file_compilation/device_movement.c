/* all functions defined and needed for main.c */
#include <stdio.h>
#include "device_capabilities.h"

void pGoForward(void) {
    printf("device moving forward\n");
}

void pGoBackwards(void) {
    printf("device moving backwards\n");
}

void pGoLeft(void) {
    printf("device moving left\n");
}

void pGoRight(void) {
    printf("device moving right\n");
}
