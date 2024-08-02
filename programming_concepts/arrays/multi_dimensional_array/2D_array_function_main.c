#include <stdio.h>
#define ROWS 4
#define COLUMNS 5
void MyCustomDisplay(int *array_input, int row_size, int column_size);

void DisplayOne(int *array_input, int row_size, int column_size);

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
            printf("M[%d][%d] = %d & A:%u ", 
                    RowIndex, ColumnIndex, *(*array_pointer + ColumnIndex), *array_pointer + ColumnIndex);
        }
        printf("\n");
    }
    // Call MyCustomDisplay
    MyCustomDisplay((int *)TwoDimension, ROWS, COLUMNS);
    DisplayOne(TwoDimension, ROWS, COLUMNS);
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
            printf("M[%d][%d] = %d & A:%u ", RowIndex, ColumnIndex, *array_input, array_input);
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
            printf("M[%d][%d] = %d & A:%u ", RowIndex, ColumnIndex, 
                    *(array + RowIndex * column_size + ColumnIndex), 
                     (array + RowIndex * column_size + ColumnIndex));
        }
        printf("\n");
    }
}   

void DisplayTwo(int (*p)[COLUMNS], int row_size, int column_size)
{
    printf("Array displayed from DisplayTwo\n");
    int *q = NULL;
    for(int RowIndex = 0; RowIndex < row_size; RowIndex++)
    {
        q = p + RowIndex;
        for(int ColumnIndex = 0; ColumnIndex < column_size; ColumnIndex++)
        {
            printf("M[%d][%d] = %d & A:%u ", RowIndex, ColumnIndex, *(q + ColumnIndex), q + ColumnIndex);
        }
        printf("\n");
    }
}
