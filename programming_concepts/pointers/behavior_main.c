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
        Value at the address of local number in display: 0x7ffec547375c %p\n", *(&number) <<<<< Imp
        - Because the float power(float *input_num, float p) expects first argument as a pointer to float 
          If you pass &number then it would become *(&number) so at this the value is address of main() fucntion
          number variable Hence it’s not expected.
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
