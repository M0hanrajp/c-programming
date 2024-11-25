// A program to check if ISBN is valid
#include "string_to_int_convert.h"

int main(void) {
    // ISBN format 10
    char userInput[10];
    printf("Enter a 10 digit ISBN number without hiphens, use 'X' for check digit if required\nEnter the digits :: ");
    scanf("%s", userInput);
    // call the function from string_to_int_convert.c
    checkIsValidISBN(userInput) ? printf("ISBN is not valid\n") : printf("ISBN is valid\n");
    return 0;
}
