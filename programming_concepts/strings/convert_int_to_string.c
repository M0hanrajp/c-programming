// program to convert integer to string
#include <stdio.h>

char *convertIntegerToString(unsigned long long number);

int main(void) {
    printf("Converting from integer to string :: %s\n", convertIntegerToString(242));
    return 0;
}

char *convertIntegerToString(unsigned long long number) {
    static char resultString[100];
    if(number >= 0 && number < 10) {
        resultString[0] = 48 + number;
        resultString[1] = '\0';
    }
    if(number >= 10 && number < 100) {
        resultString[0] = (number / 10) + 48;
        resultString[1] = (number - ((number / 10) * 10)) + 48;
        resultString[2] = '\0';
    }
    if(number >= 100 && number < 1000) {
        resultString[0] = (number / 100) + 48;
        resultString[1] = ((number - (number / 100) * 100) / 10) + 48;
        resultString[2] = (number - (number / 10) * 10) + 48;
        resultString[3] = '\0';
    }
    return resultString;
}
