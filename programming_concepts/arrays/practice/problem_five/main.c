/* A C program to find the smallest integer in an array */

#include <stdio.h>
#define SIZE 10
// Function declaration
int smallest_integer(int input_array[SIZE]);
// main
int main(void)
{
    int array[SIZE] = {3, 4, 5, 6, 0, 9, 10, 2, 12, 11};
    // Calling function to print smallest 
    printf("The smallest integer present in array is %d\n", smallest_integer(array));
    return 0;
}
// Function definiton
int smallest_integer(int input_array[SIZE])
{
    int small = input_array[0];
    for(int elements = 0; elements < SIZE; elements++)
    {
        printf("Array[%d] = %2d\n", elements, input_array[elements]);
        if(input_array[elements] < small)
            small = input_array[elements];
    }
    return small;
}

