/* YPK - problem e
 * Write a program to recieve an unsigned 16 bit integer and then exchange 
 * the contents of its 2 bytes using bit wise operator
 */
#include <stdio.h>

unsigned short int exchangeBitsOfNumber(unsigned short int userInput);

int main(void) {

    printf("Value: %x\n", exchangeBitsOfNumber(0xffff));
    return 0;
}

unsigned short int exchangeBitsOfNumber(unsigned short int userInput) {
    unsigned short int firstHalf = userInput >> 8;
    unsigned short int secondHalf = userInput << 8;
    unsigned short int result = firstHalf | secondHalf;
    return result;
}
