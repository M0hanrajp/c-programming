#include <stdio.h>

// function declaration
void printBinaryBits(unsigned int userInput);

int main(void) {
    int userInput = 0;
    printf("Enter a number to display it's binary format: ");
    scanf("%d", &userInput);
    printBinaryBits(userInput);
    return 0;
}

// function definiton
void printBinaryBits(unsigned int userInput) {
    for(int i = 31; i >= 0; i--) {
        // Left shift by i bits
        int andMask = 1 << i;
        // checkBitsSet will have 0 or 1 based on the result
        int checkBitsSet = userInput & andMask;
        checkBitsSet == 0 ? printf("0") : printf("1");
        if(i % 4 == 0)
            printf(" ");
    }
    printf("\n");
}
