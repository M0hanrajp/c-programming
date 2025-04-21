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
    // the below function is written to check the address & elements for reference.
    printf("Array displayed from main function:\n");
    for(int RowIndex = 0; RowIndex < ROWS; RowIndex++)
    {
        array_pointer = TwoDimension + RowIndex;
        for(int ColumnIndex = 0; ColumnIndex < COLUMNS; ColumnIndex++)
        {
            printf("M[%d][%d] = %d & A:%p ", 
                    // expanded form of writing array
                    RowIndex, ColumnIndex, *(*array_pointer + ColumnIndex), *array_pointer + ColumnIndex);
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
