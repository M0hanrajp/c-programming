#include <stdio.h>

// Function to calculate power of a number
float power(float **input_num, float p);
// Function to display output
void display(float *number);

int main(void)
{
    float number = 0;
    printf("Enter the value of X = ");
    scanf("%f", &number);
    display(&number);
    return 0;
}
// Funciton display
void display(float *number)
{
    float expression = power(&number, 2);
    /*NOTE: the following are the reasons why you cannot send &number by calling power:
        Enter the value of X = 2
        Address of number in main: 0x7ffec547375c %p\n", (void*)&number
        Value of number in main: 2.000000 %f\n", number
        Address of number in display from main: 0x7ffec547375c %p\n", (void *)number
        Address of number in display(local variable number in display): 0x7ffec5473728 %p\n", &number
        // This variable number has auto storage duration, block scope, no linkage
        // display(float *number) takes precedence over main() number due to block scope.
        Value at the address of local number in display: 0x7ffec547375c %p\n", *(&number) <<<<< Imp
        // in the past below was my mistake
        - Because the float power(float *input_num, float p) expects first argument as a pointer to float 
          - If you pass &number then it is pointing to address 0x7ffec547375c
          - Value at the address of local number in display: 0x7ffec547375c %p\n", *(&number) <<<<< Imp
            Hence the following error is observed and compiler prints error saying it expects float ** not float *
            behavior_main.c: In function ‘display’:
            behavior_main.c:19:30: warning: passing argument 1 of ‘power’ from incompatible pointer type [-Wincompatible-pointer-types]
           19 |     float expression = power(&number, 2);
              |                              ^~~~~~~
              |                              |
              |                              float **
        behavior_main.c:4:20: note: expected ‘float *’ but argument is of type ‘float **’
            4 | float power(float *input_num, float p);
              |             ~~~~~~~^~~~~~~~~
     */
    printf("The square of the number is : %f\n", expression);
}
// Power function
float power(float **input_num, float p)
{
    float result = 1; 
    for (int i = 0; i < p; i++)
    {
        result *= **input_num;
    }
    return result;
}
