/* Write a function that determines whether a given year is a leap year. Your program should:

Take a year as input
Return 1 (true) if it's a leap year, or 0 (false) if it's not
Follow these leap year rules:

A year is a leap year if it's divisible by 4
However, if the year is also divisible by 100, it is NOT a leap year
But if the year is divisible by 400, it IS a leap year

Example test cases:

2000 is a leap year (divisible by 400)
2100 is not a leap year (divisible by 100 but not 400)
2024 is a leap year (divisible by 4 but not 100)
2023 is not a leap year (not divisible by 4)
*/
#include <stdio.h>

void checkLeapYear(unsigned int year);

int main(void) {
    checkLeapYear(2001);
    return 0;
}

void checkLeapYear(unsigned int year) {
    if(year % 4 == 0) {
        if(year % 100 == 0) {
            if (year % 400 == 0) {
                printf("%d is a leap year\n", year);
            }
            else
                printf("%d is not a leap year\n", year);
        }
        else if (year % 100 != 0)
            printf("%d is a leap year\n", year);
        else
            printf("%d is not a leap year\n", year);
    }
    else
        printf("%d is not a leap year\n", year);
}
