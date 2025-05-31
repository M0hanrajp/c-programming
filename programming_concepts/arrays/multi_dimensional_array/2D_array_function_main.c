#include <stdio.h>
#define ROWS 4
#define COLUMNS 5
void MyCustomDisplay(int *array_input, int row_size, int column_size);

void DisplayOne(int *array_input, int row_size, int column_size);

// recommended way of printing out the arrays
void DisplayTwo(int (*p)[COLUMNS], int row_size, int column_size);

int main(void)
{
    // 2D array initialized
    int TwoDimension[ROWS][COLUMNS] = {
                                        {10, 20, 30, 40, 50},
                                        {10, 20, 30, 40, 50},
                                        {10, 20, 30, 40, 50},
                                        {10, 20, 30, 40, 50}
    };
    int (*array_pointer)[COLUMNS] = NULL;
    /* it's is read as, array_pointer is a pointer to array of COLUMNS integers
     * it's a pointer to a whole array not an element
     */
    
    // the below function is written to check the address & elements for reference.
    printf("Array displayed from main function:\n");
    for(int RowIndex = 0; RowIndex < ROWS; RowIndex++)
    {
        array_pointer = TwoDimension + RowIndex;
        /* TwoDimension is an variable that is declared as 2D array
         * so this variable decays as a pointer to the whole 1D array (0th Row)
         * so any pointer arithmetic on TwoDimesion will take us x step by sizeof(1D array)
         * 
         * here we are adding RowIndex to TwoDimension,
         * for each outer for loop iteration, we are pointing to address of 1D array
         * ex: 0 -> 0th Row, 1 -> 1st row
         */
        for(int ColumnIndex = 0; ColumnIndex < COLUMNS; ColumnIndex++)
        {
            printf("M[%d][%d] = %d & A:%p ", 
                    // expanded form of writing array
                    RowIndex, ColumnIndex, *(*array_pointer + ColumnIndex), *array_pointer + ColumnIndex);
                    /*
                     * When we enter the inner for loop:
                     *
                     * Let's say RowIndex is 0. Then, array_pointer points to TwoDimension[0],
                     * which is the address of the first row (a 1D array of integers).
                     *
                     * - Dereferencing it once:      *array_pointer → TwoDimension[0]
                     *   This gives us the start of the first row — a pointer to the first element (TwoDimension[0][0]).
                     *
                     * - Dereferencing it twice:     *(*array_pointer) → TwoDimension[0][0]
                     *   This gives us the actual integer value stored at the beginning of the first row (e.g., 10).
                     *
                     * So in the inner for loop, we use:
                     *     *(*array_pointer + ColumnIndex)
                     *
                     * Here's how it works:
                     * per operator precedence * has more priority
                     * - `*array_pointer` gives us a pointer to the first element of the current row (type: int *).
                     * - Adding ColumnIndex to this pointer moves us forward by ColumnIndex elements,
                     *   because pointer arithmetic on `int *` moves by sizeof(int).
                     * - Finally, the outer `*` dereferences that pointer to get the value at that column in the current row.
                     *
                     * Example:
                     *     RowIndex = 0, ColumnIndex = 2
                     *     → *(*array_pointer + 2) → TwoDimension[0][2]
                     */
        }
        printf("\n");
    }
    // Call MyCustomDisplay, not recommended way of accessing array elements
    MyCustomDisplay((int *)TwoDimension, ROWS, COLUMNS);
    DisplayOne((int *)TwoDimension, ROWS, COLUMNS);
    DisplayTwo(TwoDimension, ROWS, COLUMNS);
    return 0;
}
// Function definition of MyCustomDisplay
void MyCustomDisplay(int *array_input, int row_size, int column_size)
    /* When you pass a 2D array address that will always decay to (*)[COLUMN]
     * But here inside this function we are casting the 2D address as int *
     * By doing this any pointer arithemtic on the variable will move it by sizeof(int)
     * This is not recommended, just type casting a pointer address.
     *
     * we can also cast it to char * and read 4 bytes at a time and then print integer value too
     */
{
    printf("Array displayed from MyCustomDisplay:\n");
    for(int RowIndex = 0; RowIndex < row_size; RowIndex++)
    {
        for(int ColumnIndex = 0; ColumnIndex < column_size; ColumnIndex++, array_input++)
        {
            printf("M[%d][%d] = %d & A:%p ", RowIndex, ColumnIndex, *array_input, array_input);
        }
        printf("\n");
    }
}
void DisplayOne(int *array, int row_size, int column_size)
{
    printf("Array displayed from DisplayOne:\n");
    for(int RowIndex = 0; RowIndex < row_size; RowIndex++)
    {
        for(int ColumnIndex = 0; ColumnIndex < column_size; ColumnIndex++)
        {
            printf("M[%d][%d] = %d & A:%p ", RowIndex, ColumnIndex, 
                    *(array + RowIndex * column_size + ColumnIndex), 
                     (array + RowIndex * column_size + ColumnIndex));
        }
        printf("\n");
    }
}   

// recommended way of printing out the arrays
void DisplayTwo(int (*p)[COLUMNS], int row_size, int column_size)
{
    printf("Array displayed from DisplayTwo\n");
    int *q = NULL;
    for(int RowIndex = 0; RowIndex < row_size; RowIndex++)
    {
        q = *p + RowIndex;
        for(int ColumnIndex = 0; ColumnIndex < column_size; ColumnIndex++)
        {
            printf("M[%d][%d] = %d & A:%p ", RowIndex, ColumnIndex, *(q + ColumnIndex), q + ColumnIndex);
        }
        printf("\n");
    }
}

// output
/*
Array displayed from main function:
M[0][0] = 10 & A:0x7fff7e6adde0 M[0][1] = 20 & A:0x7fff7e6adde4 M[0][2] = 30 & A:0x7fff7e6adde8 M[0][3] = 40 & A:0x7fff7e6addec M[0][4] = 50 & A:0x7fff7e6addf0
M[1][0] = 10 & A:0x7fff7e6addf4 M[1][1] = 20 & A:0x7fff7e6addf8 M[1][2] = 30 & A:0x7fff7e6addfc M[1][3] = 40 & A:0x7fff7e6ade00 M[1][4] = 50 & A:0x7fff7e6ade04
M[2][0] = 10 & A:0x7fff7e6ade08 M[2][1] = 20 & A:0x7fff7e6ade0c M[2][2] = 30 & A:0x7fff7e6ade10 M[2][3] = 40 & A:0x7fff7e6ade14 M[2][4] = 50 & A:0x7fff7e6ade18
M[3][0] = 10 & A:0x7fff7e6ade1c M[3][1] = 20 & A:0x7fff7e6ade20 M[3][2] = 30 & A:0x7fff7e6ade24 M[3][3] = 40 & A:0x7fff7e6ade28 M[3][4] = 50 & A:0x7fff7e6ade2c
Array displayed from MyCustomDisplay:
M[0][0] = 10 & A:0x7fff7e6adde0 M[0][1] = 20 & A:0x7fff7e6adde4 M[0][2] = 30 & A:0x7fff7e6adde8 M[0][3] = 40 & A:0x7fff7e6addec M[0][4] = 50 & A:0x7fff7e6addf0
M[1][0] = 10 & A:0x7fff7e6addf4 M[1][1] = 20 & A:0x7fff7e6addf8 M[1][2] = 30 & A:0x7fff7e6addfc M[1][3] = 40 & A:0x7fff7e6ade00 M[1][4] = 50 & A:0x7fff7e6ade04
M[2][0] = 10 & A:0x7fff7e6ade08 M[2][1] = 20 & A:0x7fff7e6ade0c M[2][2] = 30 & A:0x7fff7e6ade10 M[2][3] = 40 & A:0x7fff7e6ade14 M[2][4] = 50 & A:0x7fff7e6ade18
M[3][0] = 10 & A:0x7fff7e6ade1c M[3][1] = 20 & A:0x7fff7e6ade20 M[3][2] = 30 & A:0x7fff7e6ade24 M[3][3] = 40 & A:0x7fff7e6ade28 M[3][4] = 50 & A:0x7fff7e6ade2c
Array displayed from DisplayOne:
M[0][0] = 10 & A:0x7fff7e6adde0 M[0][1] = 20 & A:0x7fff7e6adde4 M[0][2] = 30 & A:0x7fff7e6adde8 M[0][3] = 40 & A:0x7fff7e6addec M[0][4] = 50 & A:0x7fff7e6addf0
M[1][0] = 10 & A:0x7fff7e6addf4 M[1][1] = 20 & A:0x7fff7e6addf8 M[1][2] = 30 & A:0x7fff7e6addfc M[1][3] = 40 & A:0x7fff7e6ade00 M[1][4] = 50 & A:0x7fff7e6ade04
M[2][0] = 10 & A:0x7fff7e6ade08 M[2][1] = 20 & A:0x7fff7e6ade0c M[2][2] = 30 & A:0x7fff7e6ade10 M[2][3] = 40 & A:0x7fff7e6ade14 M[2][4] = 50 & A:0x7fff7e6ade18
M[3][0] = 10 & A:0x7fff7e6ade1c M[3][1] = 20 & A:0x7fff7e6ade20 M[3][2] = 30 & A:0x7fff7e6ade24 M[3][3] = 40 & A:0x7fff7e6ade28 M[3][4] = 50 & A:0x7fff7e6ade2c
Array displayed from DisplayTwo
M[0][0] = 10 & A:0x7fff7e6adde0 M[0][1] = 20 & A:0x7fff7e6adde4 M[0][2] = 30 & A:0x7fff7e6adde8 M[0][3] = 40 & A:0x7fff7e6addec M[0][4] = 50 & A:0x7fff7e6addf0
M[1][0] = 20 & A:0x7fff7e6adde4 M[1][1] = 30 & A:0x7fff7e6adde8 M[1][2] = 40 & A:0x7fff7e6addec M[1][3] = 50 & A:0x7fff7e6addf0 M[1][4] = 10 & A:0x7fff7e6addf4
M[2][0] = 30 & A:0x7fff7e6adde8 M[2][1] = 40 & A:0x7fff7e6addec M[2][2] = 50 & A:0x7fff7e6addf0 M[2][3] = 10 & A:0x7fff7e6addf4 M[2][4] = 20 & A:0x7fff7e6addf8
M[3][0] = 40 & A:0x7fff7e6addec M[3][1] = 50 & A:0x7fff7e6addf0 M[3][2] = 10 & A:0x7fff7e6addf4 M[3][3] = 20 & A:0x7fff7e6addf8 M[3][4] = 30 & A:0x7fff7e6addfc
*/
