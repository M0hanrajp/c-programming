/* A C program to modify the elements of an array */

#include <stdio.h>
#define SIZE 5

// Function declaration
void modify(int input_array[SIZE]);
// main
int main(void)
{
    int array[SIZE] = {1, 1, 1, 1, 1};
    // Modifying the array
    modify(array);
    // printing the modified array
    for(int elements = 0; elements < SIZE; elements++)
    {
        printf("Array[%d] = %d\n", elements, array[elements]);
    }
    return 0;
}
// Function definition
void modify(int input_array[SIZE])
{
    for(int elements = 0; elements < SIZE; elements++)
    {
        input_array[elements] *= 3;
    }
}
