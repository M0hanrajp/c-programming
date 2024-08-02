/* Program for 2D array */
#include <stdio.h>
#define ROWS 4
#define COLUMNS 5
// Function to modify 2D array
void ModifyTwoDimensionalArray(int *array, int row_size, int column_size);
int main(void)
{
    // 2D array initialized with values:
    int TwoDimensionArray[ROWS][COLUMNS] = {
        {1, 2, 3, 4, 5},
        {2, 2, 2, 2, 2},
        {1, 2, 3, 1, 2},
        {3, 4, 4, 2, 1}
    };
    // Print out the initialized array with address:
    printf("2D array from main function::\n");
    for(int rowIndex = 0; rowIndex < ROWS; rowIndex++)
    {
        for(int columnIndex = 0; columnIndex < COLUMNS; columnIndex++)
        {
            printf("M[%d][%d]= %d & A:%u  ",rowIndex, columnIndex, TwoDimensionArray[rowIndex][columnIndex], &TwoDimensionArray[rowIndex][columnIndex]);
        }
        printf("\n");
    }
        // checking what TwoDimension contains ?, the value and address
    printf("\nwhat does TwoDimension contain ?: value:%u & address:%u\n", *TwoDimensionArray, TwoDimensionArray);
    // NOTE: the TwoDimension contains Address of 1st element as value., 
    // if using **TwoDimension then it will give value of the first element
    printf("Addition of 1 to TwoDimension = value:%d & address:%u\n", **(TwoDimensionArray + 1), TwoDimensionArray + 1);
    // NOTE: The above statement resulted in TwoDimesion moving to the next row instead of element.
    printf("Addition of 1 to (a pointer to an array of 5 integers i.e. *TwoDimension + 1 = value:%d & address:%u\n", *(*TwoDimensionArray + 1), *TwoDimensionArray + 1);
    // NOTE: the above statement gave me second element of first array
        /* treating TwoDimension as a pointer to an array of 5 integers and adding 1 to it. 
         * This effectively increments the pointer by the size of the array it points to (
         * which is 5 integers, or 20 bytes on a system where an int is 4 bytes). This operation 
         * gives you a pointer to the next array of 5 integers in memory, so the value printed is
         * the address of the first element of the next array, not the value of the element itself.*/
    printf("The size of TwoDimension should be equal to size of 1st row array i.e 20 bytes: size is %d & total size of array = %d\n", sizeof(*TwoDimensionArray), sizeof(TwoDimensionArray));
    // NOTE: Size of entire array = TwoDimension, size of first 1D array = *TwoDimension
    // Calling the function
    /* NOTE: when passing TwoDimension to funciton it is of the type int (*)[5] 
     * (a pointer to an array of 5 integers). In C, a 2D array like int TwoDimension[4][5]
     * decays to a pointer to the first element, which is an array of 5 integers, i.e., int (*)[5].*/
    // Call the function:
    ModifyTwoDimensionalArray((int *)TwoDimensionArray, ROWS, COLUMNS);
    return 0;
}
// Function definition for 2D array
void ModifyTwoDimensionalArray(int *array, int row_size, int column_size)
{
    printf("2D array from custom function::\n");
    for(int rowIndex = 0; rowIndex < row_size; rowIndex++)
    {
        for(int columnIndex = 0; columnIndex < column_size; columnIndex++, array++)
        {
            printf("M[%d][%d]= %d & A:%u  ",rowIndex, columnIndex, *array, array);
        }
        printf("\n");
    }
}
