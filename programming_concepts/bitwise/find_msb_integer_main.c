/* write a function which take integer as input and return MSB of integer from that function */
#include <stdio.h>

int findMsb(int inputNumber);

int main(void) {
    unsigned int userInput = 0;
    printf("Enter a integer :: ");
    scanf("%d", &userInput);
    printf("MSB of the integer is at position :: %d\n", findMsb(userInput));
    return 0;
}

int findMsb(int inputNumber) {
    if(inputNumber == 0) {return -1;}
    int bitPosition = 31;
    int msb = 0;
    while(msb == 0) {
        msb = (unsigned int)inputNumber & (1 << bitPosition);
        if(msb > 0){break;}
        --bitPosition;
    }
    return bitPosition;
}
