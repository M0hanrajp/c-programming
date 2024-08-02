/* NOTE: The following program has all the array basics */
#include <stdio.h>
#define SIZE 5
// Funciton one: Display & modify the array using pointers
void DisplayAndModifyArray(int *array_input, int array_size);
// Function two: Another way to display an array
void DisplayTypeTwo(int array_input[SIZE]);
int main(void)
{
    int MainFuncitonArray[SIZE] = {};
    // Printing the array in main function with address & checking the elements.
    for (int element = 0; element < SIZE; element++)
    {
        // all the array elements will be initialized to 0.
        printf("Main function - array[%d] = %d & address: %u\n", element, MainFuncitonArray[element], &MainFuncitonArray[element]);
    }
    // Calling Funciton one, array will be modified to different value, address remain same
    DisplayAndModifyArray(MainFuncitonArray, SIZE);
    // Calling Function two, array is displayed using subscript
    DisplayTypeTwo(MainFuncitonArray);
    return 0;
}
// Function definition - Function one:
void DisplayAndModifyArray(int *array_input, int array_size)
{
    for(int element = 0; element < array_size; element++, array_input++)
    {
        *array_input = 1 + element;
        printf("Display & Modify function - array[%d] = %d & address: %u\n", element, *array_input, array_input);
    }
}
// Function definition - Function two:
void DisplayTypeTwo(int array_input[SIZE])
{
    for(int element = 0; element < SIZE; element++)
    {
        printf("Display using subscript inside the function - array[%d] = %d & address: %u\n", element, array_input[element], &array_input[element]);
        /* NOTE:
         * Alternative use *array_input display the value of elements
         * Also array_input will give the address of the elements from MainFuncitonArray
         * Remeber to include array_input++ to increment to the next element */
    }
}
