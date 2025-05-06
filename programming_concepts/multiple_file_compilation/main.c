/* The following program acts as a device */

#include <stdio.h>
#include "device_capabilities.h"

int main(void) {
    // use keys w, a, s, d to play the game.
    char key = 'y';

    printf("Enter the direction, w - forward, s - back, a - left, d - right\n");
    while (key) {
        printf("Key: ");
        scanf(" %c", &key);
        // The leading space tells scanf to skip any whitespace characters
        // (including the newline) before reading the actual character.

        if(key == 'n'){break;} // program exit condition

        switch (key) {
            case 'w': pGoForward();   break;
            case 'a': pGoLeft();      break;
            case 's': pGoBackwards(); break;
            case 'd': pGoRight();     break;
            default : return 0;       break;
        }
    }
    return 0;
}
