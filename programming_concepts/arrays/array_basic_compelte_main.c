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
        // we use the address of (&) operator to get the address of a variable
        // &MainFuncitonArray[element] --> is same as &(&MainFuncitonArray[element])
        // [] has higher precedence than & operator
        printf("Main function - array[%d] = %d & address: %p\n", element, MainFuncitonArray[element], &MainFuncitonArray[element]);
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
    for(int element = 0; element < array_size; element++)
    {
        *array_input = 1 + element;
        // array_input - base address of the array, "element" helps to get the next array element's value
        printf("Display & Modify function - array[%d] = %d & address: %p\n", element, *array_input, array_input + element);
    }
}
// Function definition - Function two:
void DisplayTypeTwo(int array_input[SIZE])
{
    for(int element = 0; element < SIZE; element++)
    {
        printf("Display using subscript inside the function - array[%d] = %d & address: %p\n", 
                element, array_input[element], &array_input[element]);
        /* NOTE:
         * Alternative use *array_input display the value of elements
         * Also array_input will give the address of the elements from MainFuncitonArray
         * Remeber to include array_input++ to increment to the next element */
    }
}

// output
/* program output
Main function - array[0] = 0 & address: 0x7ffda0a80e40
Main function - array[1] = 0 & address: 0x7ffda0a80e44
Main function - array[2] = 0 & address: 0x7ffda0a80e48
Main function - array[3] = 0 & address: 0x7ffda0a80e4c
Main function - array[4] = 0 & address: 0x7ffda0a80e50
Display & Modify function - array[0] = 1 & address: 0x7ffda0a80e40
Display & Modify function - array[1] = 2 & address: 0x7ffda0a80e44
Display & Modify function - array[2] = 3 & address: 0x7ffda0a80e48
Display & Modify function - array[3] = 4 & address: 0x7ffda0a80e4c
Display & Modify function - array[4] = 5 & address: 0x7ffda0a80e50
Display using subscript inside the function - array[0] = 1 & address: 0x7ffda0a80e40
Display using subscript inside the function - array[1] = 2 & address: 0x7ffda0a80e44
Display using subscript inside the function - array[2] = 3 & address: 0x7ffda0a80e48
Display using subscript inside the function - array[3] = 4 & address: 0x7ffda0a80e4c
Display using subscript inside the function - array[4] = 5 & address: 0x7ffda0a80e50
*/
