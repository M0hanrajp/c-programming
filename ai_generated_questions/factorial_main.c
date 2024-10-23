#include <stdio.h>

// function declaration
int calculateFactorial(int *num);

int main(void) {
    // get user input
    int input_number = 0;
    printf("This program calculates the factorial of a number\nEnter a number: ");
    scanf("%d", &input_number);
    printf("%d factorial equals :: ", input_number);
    // call the function and get the answer
    printf("%d\n", calculateFactorial(&input_number));
    return 0;
}

// function definiton
int calculateFactorial(int *num) {
    int result = 1;
    while (*num != 0) {
    result = *num * result;
    (*num)--;
    }
    return result;
}
