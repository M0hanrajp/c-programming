/* YPK - problem e
 * Write a program to recieve an unsigned 16 bit integer and then exchange 
 * the contents of its 2 bytes using bit wise operator
 */
#include <stdio.h>

int exchangeBitsOfNumber(unsigned short int userInput);

int main(void) {

    printf("Value: %x\n", exchangeBitsOfNumber(4660));
    return 0;
}

int exchangeBitsOfNumber(unsigned short int userInput) {
    int firstHalf = userInput >> 8;
    printf("FH: %x\n", firstHalf);
    int secondHalf = userInput << 8;
    printf("SH: %x\n", secondHalf);
    int result = firstHalf | secondHalf;
    return result;
}
