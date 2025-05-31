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
            printf("M[%d][%d]= %d & A:%p  ",rowIndex, columnIndex, 
                    TwoDimensionArray[rowIndex][columnIndex], &TwoDimensionArray[rowIndex][columnIndex]);
        }
        printf("\n");
    }
        // checking what TwoDimension contains ?, the value and address
    printf("\nwhat does TwoDimension contain ?: value:%p & address:%p\n", *TwoDimensionArray, TwoDimensionArray);
    // NOTE: the TwoDimension contains Address of 1st element as value., 
    // if using **TwoDimension then it will give value of the first element
    // Only using the variable TwoDimensionArray is the address of whole 1D array
    printf("Addition of 1 to TwoDimension = value:%d & address:%p\n", **(TwoDimensionArray + 1), TwoDimensionArray + 1);
    // NOTE: The above statement resulted in TwoDimesion moving to the next row instead of element.
    // Because TwoDimension holds the address of 1D array, size of 20 bytes
    // Pointer arithmetic will lead to moving by 20 bytes ahead
    printf("Addition of 1 to (a pointer to an array of 5 integers i.e. *TwoDimension + 1 = value:%d & address:%p\n", 
            *(*TwoDimensionArray + 1), *TwoDimensionArray + 1);
    // NOTE: the above statement gave me second element of first array
        /* treating TwoDimension as a pointer to an array of 5 integers and adding 1 to it. 
         * This effectively increments the pointer by the size of the array it points to (
         * which is 5 integers, or 20 bytes on a system where an int is 4 bytes). This operation 
         * gives you a pointer to the next array of 5 integers in memory, so the value printed is
         * the address of the first element of the next array, not the value of the element itself.*/
    printf("The size of TwoDimension should be equal to size of 1st row array i.e 20 bytes: size is %zu & total size of array = %zu\n", 
            sizeof(*TwoDimensionArray), sizeof(TwoDimensionArray));
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
// below way is not recommended for parsing a 2D array but also is one of the way to do it
// best way is to use int (*array)[column_size]
void ModifyTwoDimensionalArray(int *array, int row_size, int column_size)
    /* When you pass a 2D array address that will always decay to (*)[COLUMN]
     * But here inside this function we are casting the 2D address as int *
     * By doing this any pointer arithemtic on the variable will move it by sizeof(int)
     * This is not recommended, just type casting a pointer address.
     *
     * we can also cast it to char * and read 4 bytes at a time and then print integer value too
     */
{
    printf("2D array from custom function::\n");
    for(int rowIndex = 0; rowIndex < row_size; rowIndex++)
    {
        for(int columnIndex = 0; columnIndex < column_size; columnIndex++, array++)
        {
            printf("M[%d][%d]= %d & A:%p  ",rowIndex, columnIndex, *array, array);
        }
        printf("\n");
    }
}

// output
/*
$ ./a.out
2D array from main function::
M[0][0]= 1 & A:0x7ffed53b5860  M[0][1]= 2 & A:0x7ffed53b5864  M[0][2]= 3 & A:0x7ffed53b5868  M[0][3]= 4 & A:0x7ffed53b586c  M[0][4]= 5 & A:0x7ffed53b5870
M[1][0]= 2 & A:0x7ffed53b5874  M[1][1]= 2 & A:0x7ffed53b5878  M[1][2]= 2 & A:0x7ffed53b587c  M[1][3]= 2 & A:0x7ffed53b5880  M[1][4]= 2 & A:0x7ffed53b5884
M[2][0]= 1 & A:0x7ffed53b5888  M[2][1]= 2 & A:0x7ffed53b588c  M[2][2]= 3 & A:0x7ffed53b5890  M[2][3]= 1 & A:0x7ffed53b5894  M[2][4]= 2 & A:0x7ffed53b5898
M[3][0]= 3 & A:0x7ffed53b589c  M[3][1]= 4 & A:0x7ffed53b58a0  M[3][2]= 4 & A:0x7ffed53b58a4  M[3][3]= 2 & A:0x7ffed53b58a8  M[3][4]= 1 & A:0x7ffed53b58ac

what does TwoDimension contain ?: value:0x7ffed53b5860 & address:0x7ffed53b5860
Addition of 1 to TwoDimension = value:2 & address:0x7ffed53b5874
Addition of 1 to (a pointer to an array of 5 integers i.e. *TwoDimension + 1 = value:2 & address:0x7ffed53b5864
The size of TwoDimension should be equal to size of 1st row array i.e 20 bytes: size is 20 & total size of array = 80
2D array from custom function::
M[0][0]= 1 & A:0x7ffed53b5860  M[0][1]= 2 & A:0x7ffed53b5864  M[0][2]= 3 & A:0x7ffed53b5868  M[0][3]= 4 & A:0x7ffed53b586c  M[0][4]= 5 & A:0x7ffed53b5870
M[1][0]= 2 & A:0x7ffed53b5874  M[1][1]= 2 & A:0x7ffed53b5878  M[1][2]= 2 & A:0x7ffed53b587c  M[1][3]= 2 & A:0x7ffed53b5880  M[1][4]= 2 & A:0x7ffed53b5884
M[2][0]= 1 & A:0x7ffed53b5888  M[2][1]= 2 & A:0x7ffed53b588c  M[2][2]= 3 & A:0x7ffed53b5890  M[2][3]= 1 & A:0x7ffed53b5894  M[2][4]= 2 & A:0x7ffed53b5898
M[3][0]= 3 & A:0x7ffed53b589c  M[3][1]= 4 & A:0x7ffed53b58a0  M[3][2]= 4 & A:0x7ffed53b58a4  M[3][3]= 2 & A:0x7ffed53b58a8  M[3][4]= 1 & A:0x7ffed53b58ac
*/
