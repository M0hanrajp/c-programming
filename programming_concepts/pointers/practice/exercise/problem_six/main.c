/* A C program to find the greatest common divisor */

#include <stdio.h>

// Function declaration
int gcd(int *num, int *deno);

int main(void)
{
    int numerator = 3, denominator = 5;
    printf("the greatest common divisor is %d\n", gcd(&numerator, &denominator));
    return 0;
}

// Funciton definition
int gcd(int *num, int *deno)
{
    int quotient = 0;
    int result = 0;
    int gcd = 0;
    while(1)
    {
        quotient = *num / *deno;
        result = *num - (quotient * *deno);
        if(result == 0)
        {
            gcd = *deno;
            break;
        }
        *num = *deno;
        *deno = result;
    }
    return gcd;
}

