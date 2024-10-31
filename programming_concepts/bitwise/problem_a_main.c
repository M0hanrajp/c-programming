/* YPK - Bitwise operators - problem a
 * Integer number that represent colors in a rainbow
 * a char color variable that holds all bits, bit -0 - violet etc..
 * ask user to enter any number and check what color the number represents */

#include <stdio.h>

void colorRepresentation(unsigned int number);

int main(void) {
    // this might not be required ? char color = 127;
    /* binary = 0111 1111
     * bit 0 - violet
     * bit 1 - Indigo
     * bit 2 - blue
     * bit 3 - green
     * bit 4 - yellow
     * bit 5 - orange
     * bit 6 - red
     * bit 7 - none */
    unsigned int userInput = 0;
    printf("Enter any integer : ");
    scanf("%d", &userInput);
    colorRepresentation(userInput);
    return 0;
}

void colorRepresentation(unsigned int number) {
    printf("Your number represents the following colors::\n");
    for(int bit = 7; bit >= 0; bit--) {
        int andMask = 1 << bit;
        int checkColorBitSet = number & andMask;
        if(checkColorBitSet >= 1) {
            if(bit == 6)
                printf("Red ");
            if(bit == 5)
                printf("Orange ");
            if(bit == 4)
                printf("Yellow ");
            if(bit == 3)
                printf("Green ");
            if(bit == 2)
                printf("Blue ");
            if(bit == 1)
                printf("Indigo ");
            if(bit == 0)
                printf("Violet ");
        }
    }
    printf("\n");
}
