/* A C program to check if the entered number exists in the array ? */

#include <stdio.h>

int main(void)
{
    // stored array
    int numbers_array[10] = {1, 1, 2, 3, 4, 5, 4, 7, 8, 7};
    int count = 0; // to get occurrance rate
    // user number that needs to be searched
    int input_number = 0;
    printf("Enter the number that needs to be searched: ");
    scanf("%d", &input_number);

    // searching the number exists in the array ?
    for(int elements = 0; elements < 10; elements++)
    {
        if(input_number == numbers_array[elements])
        {
            count++;
            if(count < 2)
            {
                printf("%d was found in the array and occurred ", input_number);
            }
        }
    }
    printf("%d times !\n", count);
    if(count == 0)
    {
        printf("Entered number was not found in the array!\n");
    }
    return 0;
}
