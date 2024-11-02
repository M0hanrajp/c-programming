/* YPK - problem f
 * Write a program to recieve an unsigned 8 bit integer and then exchange 
 * the contents of its 2 bytes using bit wise operator
 */
#include <stdio.h>
#include <stdint.h>

// function declaration 
uint8_t fourBitSwap(uint8_t inputNumber);

int main() {
    printf("Bit Swapp :: %x\n", fourBitSwap(0x12));
    return 0;
}
// function declaration 
uint8_t fourBitSwap(uint8_t inputNumber) {
    uint8_t higherByte = inputNumber >> 4;
    uint8_t lowerByte = inputNumber << 4;
    return higherByte | lowerByte;
}
