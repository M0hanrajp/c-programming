// Program to verify credit card number
#include <stdio.h>
#include <stdbool.h>

bool checkIsCreditCardValid(int *ccNum);

int main(void) {
    int userInput[16] = {4,5,6,7,1,2,3,4,5,6,7,8,9,1,2,9};
    checkIsCreditCardValid(userInput) ? printf("Credit card is not valid\n") : printf("Credit card is valid\n");
    return 0;
}

bool checkIsCreditCardValid(int *ccNum) {
    int oddIndex = 1;
    int evenIndex = 0;
    int oddIndexSum = 0;
    int evenIndexSum = 0;
    int multiplyEvenDigit = 0;
    bool isCCNumValid = false;
    // 2 * int, sum of all digits at even place
    for(evenIndex = 14; evenIndex >= 0; evenIndex -= 2) {
        multiplyEvenDigit = ccNum[evenIndex] * 2;
        if(multiplyEvenDigit >= 10) {
            evenIndexSum += (multiplyEvenDigit - 9);
            continue;
        }
        evenIndexSum += multiplyEvenDigit;
    }
    for(oddIndex = 1; oddIndex < 16; oddIndex += 2) {
        oddIndexSum += ccNum[oddIndex];
    }
    isCCNumValid = ((oddIndexSum + evenIndexSum) % 10);
    return isCCNumValid;
}
