// program to convert a string to an integer
#include <stdio.h>

int convertStrToInt(char *inputString);
// int asciiNumeric(char inputChar);

int main(void) {
    char str[10] = "111";
    printf("Based on the entered string %s, integer value is %d\n", str, convertStrToInt(str));
    return 0;
}

int convertStrToInt(char *inputString) {
    int resultingInt = 0;
    int isNegative = 0;
    int index = 0;
    if(inputString[0] == '-') {
        isNegative++;
        index++;
    }
    while (inputString[index] != '\0') {
        resultingInt = resultingInt * 10 + (inputString[index] - '0');
        index++;
    }
    if(isNegative)
        resultingInt = -resultingInt;
    return resultingInt;
}

// Below is the old logic which I came up, this lacks genrealization
/* int converStrToInt(char *inputString) {
    int resultingInt = 0;
    resultingInt += asciiNumeric(inputString[0]) * 100;
    resultingInt += asciiNumeric(inputString[1]) * 10;
    resultingInt += asciiNumeric(inputString[2]);
    return resultingInt;
}

int asciiNumeric(char inputChar) {
    switch (inputChar) {
        case 48:
            return 0;
        case 49:
            return 1;
        case 50:
            return 2;
        case 51:
            return 3;
        case 52:
            return 4;
        case 53:
            return 5;
        case 54:
            return 6;
        case 55:
            return 7;
        case 56:
            return 8;
        case 57:
            return 9;
        default:
            return -1;
    }
} */
