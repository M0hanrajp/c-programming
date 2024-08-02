/* A c program to calculate the series upto 10 terms :
 * sin(x) = x - (x ^ 3/3!) + (x ^ 5/5!) .... till 10th term */

#include <stdio.h>

float taylor_series(float *number);
float factorial(float number);
float power(float *input_num, float p);

int main(void)
{
    float number = 0;
    printf("Enter the value of X = ");
    scanf("%f", &number);

    printf("the value of taylor series upto 10th term is : %f\n", taylor_series(&number));
    return 0;
}
// Taylor series function
float taylor_series(float *number)
{    
    float factorial_power_number = 1.0;
    float expression = 0.0;
    for(int term = 1; term < 11; term++)
    {
        if(term % 2 == 0)
        {
            for(;factorial_power_number < 21.0;)
            {
                printf("expression: - %.2f ^ %.2f / %.2f !\n", *number, factorial_power_number, factorial_power_number); 
                expression -= (power(&number, factorial_power_number) / factorial(factorial_power_number));
                break;
            }
        }
        if(term % 2 != 0)
        {
            for(;factorial_power_number < 21.0;)
            {
                printf("expression: + %.2f ^ %.2f / %.2f !\n", *number, factorial_power_number, factorial_power_number); 
                expression += (power(number, factorial_power_number) / factorial(factorial_power_number));
                break;
            }
        }
        factorial_power_number = factorial_power_number + 2;
    }
    return expression;
}
// Factorial funciton
float factorial(float number)
{
    float result = 1;
    for (int i = 1; i <= number; i++)
    {
        result *= i;
    }
    return result;
}
// Power function
float power(float *input_num, float p)
{
    float result = 1; 
    for (int i = 0; i < p; i++)
    {
        result *= *input_num;
    }
    return result;
}
/* NOTE: figure out - & + alternative addition
    int sum = 0;
    int j = 1;
    for(int i = 1; i < 11; i++)
    {
        if(i % 2 == 0)
        {
            for(;j < 21;)
            {
                printf(" %d: sum = %d\n", i, sum -= j);
                break;
            }
        }
        if(i % 2 != 0)
        {
            for(;j < 21;)
            {
                printf("%d: sum = %d\n", i, sum += j);
                break;
            }
        }
        j = j + 2;
    }
===============================================*/
