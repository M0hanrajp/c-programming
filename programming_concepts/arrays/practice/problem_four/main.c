/* A c program that copies elements from one array into another in reverse manner */
#include <stdio.h>
#define SIZE 10
// Funciton declaration
void reverse_array(int source_array[SIZE], int target_array[SIZE]);
// Main
int main(void)
{
    // creating two different arrays
    int normal_order[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int reverse_order[SIZE] = {0};
    // calling reverse array function to modify values:
    reverse_array(normal_order, reverse_order);
    // Printing out both arrays:
    for(int elements = 0; elements < SIZE; elements++)
    {
        printf("Normal Array[%2d] = %2d & Reverse Array[%2d] = %2d\n", elements, normal_order[elements], elements, reverse_order[elements]);
    }
    return 0;
}
// Function definition
void reverse_array(int source_array[SIZE], int target_array[SIZE])
{
    for(int elements = SIZE - 1; elements > -1; elements--)
    {
        target_array[elements] = source_array[(SIZE - elements) - 1];
    }
}

