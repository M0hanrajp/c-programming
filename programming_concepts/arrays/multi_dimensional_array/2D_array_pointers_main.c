#include <stdio.h>
#define ROW 4
#define COL 5
void dispay(int *array_input, int row_size, int column_size);
int main(void)
{
    // 2D array initialized 
    int TwoDimension[ROW][COL] = {
					{10, 20, 30, 40, 50},
					{10, 20, 30, 40, 50},
					{10, 20, 30, 40, 50},
					{10, 20, 30, 40, 50}
    };
    /* NOTE: declare a pointer that can point to whole array instead of only one element of the array
        data_type (*var_name)[size_of_array];
        - data_type is the type of data that the array holds.
        - var_name is the name of the pointer variable.
        - size_of_array is the size of the array to which the pointer will point.
        - Since subscript have higher precedence than indirection, it is necessary to enclose the indirection
        operator and pointer name inside parentheses.
        - Also if there are no brackets enclosed then it will make p an array of 2 integer pointers (let us C)
        */ 
    int (*p)[COL];
    printf("Printing out information regarding pointer to the array:\n"
            "Pointer p, size of p: %d, size of (array)*p: %d, address: %u, value: %u\n", sizeof(p), sizeof(*p), &p, **p);
            /* NOTE: size of *p (pointer to an array of 5 elements, int 4 bytes * 5 elements = 20 bytes)*/
    printf("2D array reference:\n");
    for(int RowIndex = 0; RowIndex < ROW; RowIndex++)
    {
        for(int ColumnIndex = 0; ColumnIndex < COL; ColumnIndex++)
        {
            printf("M[%d][%d] = %d & A:%u ", RowIndex, ColumnIndex, TwoDimension[RowIndex][ColumnIndex], &TwoDimension[RowIndex][ColumnIndex]);
        }
        printf("\n");
    }   
    printf("2D array using pointer to an array:\n");
    for(int RowIndex = 0; RowIndex < ROW; RowIndex++)
    {
        p = TwoDimension + RowIndex;//NOTE: p will hold address of the 5 * 1D arrays
        for(int ColumnIndex = 0; ColumnIndex < COL; ColumnIndex++)
        {
            printf("*p + colindex = %u + %d >> M[%d][%d] = %d & A:%u\n", 
                    *p, ColumnIndex, RowIndex, ColumnIndex, *(*p + ColumnIndex), *p + ColumnIndex);
        }
    }
    return 0;
} 
