/* A C program that inserts all the prime numbers to an array */

#include <stdio.h>
#define SIZE 100

int main(void)
{
    // Array definition
    int prime[SIZE] = {0};
    
    for(int numbers = 2; numbers <= SIZE; numbers++)
    {
        int flag = 1;
        for(int divisor = 2; divisor <= numbers/2; divisor++)
        {
            if(numbers % divisor == 0)
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            printf("From array prime(%2d) = %2d\n", (numbers - 2), (prime[numbers - 2] = numbers));
        }
    }

    // Printing prime using loop
    for(int element = 0; element <= SIZE; element++)
    {
        printf("Prime[%2d - element] = %2d\n", element, prime[element]);
    }

    return 0;
}
/*NOTE:
 *   for(int o = 2; o <= 20; o++)
    {
        int flag = 1;
        for(int i = 2; i <= o/2; i++)
        {
            if(o % i == 0)
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            printf("%d is prime\n", o);
        }
    }
*/
