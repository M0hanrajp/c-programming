/* A C program to interchange odd & even numbers */
#include <stdio.h>
int main(void)
{
    int stored_array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int temp = 0;
    
    // display at what positions array elemetns are odd and even
    printf("Before interchanging odd and even elements:\n");
    for(int elements = 0; elements < 10; elements++)
    {
        if(stored_array[elements] % 2 == 0)
            printf("Array element %d = %2d is even\n", elements, stored_array[elements]);
        else
            printf("Array element %d = %2d is  odd\n", elements, stored_array[elements]);   
    }
    for(int elements = 0; elements < 10; elements++)
    {
        if(stored_array[elements] % 2 == 0)
        {
            temp = stored_array[elements]; // temp has 2, 1 position is empty
            stored_array[elements] = stored_array[elements - 1]; // 1 position is assigned value 1 is odd, 0th empty
            stored_array[elements - 1] = temp; // 0th position has 2 value which is even
        }
    }
    printf("After interchanging odd and even elements:\n");
    for(int elements = 0; elements < 10; elements++)
    {
        if(stored_array[elements] % 2 == 0)
            printf("Array element %d = %2d is even\n", elements, stored_array[elements]);
        else
            printf("Array element %d = %2d is  odd\n", elements, stored_array[elements]);   
    }

    return 0;
}
