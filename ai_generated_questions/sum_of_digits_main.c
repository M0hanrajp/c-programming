/* Problem statement 
 * Write a C program that takes an integer as input and calculates the sum of its digits.
 * n = 1234, Sum of digits of 1234 is: 10
 */
#include <stdio.h>
#include <stdlib.h>

// funciton declaration
int sumOfDigits(int input);

int main(void) {
    int user_int = 0;
    printf("Enter number : ");
    scanf("%d", &user_int);
    printf("The sum of digits of %d is %d\n", user_int, sumOfDigits(user_int));
    return 0;
}

// Function definiton
int sumOfDigits(int input) {
    int sum = 0;
    while (input > 0) {
        if(input >= 1000) {
            sum = input / 1000;
            input = input % 1000;
        }
        else if (input >= 100) {
            sum = sum + (input / 100);
            input = input % 100;
        }
        else if (input >= 10) {
            sum = sum + (input / 10);
            input = input % 10;
        }
        else if (input >= 0) {
            sum = sum + input;
            input = input % 1;
        }
    }
    return sum;
}

// Function definition for improvised logic
int sumOfDigitsImprovedLogic(int input) {
    int sum = 0;
    input = abs(input);  // Make sure the number is positive

    // Loop to sum all digits
    while (input > 0) {
        sum += input % 10;  // Get the last digit
        input /= 10;        // Remove the last digit
    }
    return sum;
}
