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
        - Also if there are no brackets enclosed then it will make p an array of 5 integer pointers (let us C)
        */ 
    int (*p)[COL] = TwoDimension;
    printf("Printing out information regarding pointer to the array:\n"
            "Pointer p :: size of p: %zu, size of (array)*p: %zu, address of p: %p, value p or *p: %p, access element **p : %d\n", 
            sizeof((void *)p), sizeof(*p), &p, *p, **p);
            /* NOTE: size of *p (pointer to an array of 5 elements, int 4 bytes * 5 elements = 20 bytes)
             * value of p -> the 1D array address (address of the first element)
             * value of *p -> address of the first element.
             * */
    printf("2D array reference:\n");
    for(int RowIndex = 0; RowIndex < ROW; RowIndex++)
    {
        for(int ColumnIndex = 0; ColumnIndex < COL; ColumnIndex++)
        {
            printf("M[%d][%d] = %d & A:%p ", RowIndex, ColumnIndex, TwoDimension[RowIndex][ColumnIndex], &TwoDimension[RowIndex][ColumnIndex]);
        }
        printf("\n");
    }   
    printf("2D array using pointer to an array:\n");
    for(int RowIndex = 0; RowIndex < ROW; RowIndex++)
    {
        p = TwoDimension + RowIndex;//NOTE: p will hold address of the 5 * 1D arrays
        for(int ColumnIndex = 0; ColumnIndex < COL; ColumnIndex++)
        {
            printf("*p + colindex = %p + %d >> M[%d][%d] = %d & A:%p\n", 
                    *p, ColumnIndex, RowIndex, ColumnIndex, *(*p + ColumnIndex), *p + ColumnIndex);
                    // *(*p + ColumnIndex) is the expanded form of (*p)[ColumnIndex]
                    // Both way of writing gives the same value of array
                    // *p gives you the address of first element of each 1D array
        }
    }
    return 0;
}
// output
/*
 
Printing out information regarding pointer to the array:
Pointer p :: size of p: 8, size of (array)*p: 20, address of p: 0x7ffc24853c78, value p or *p: 0x7ffc24853c80, access element **p : 10
2D array reference:
M[0][0] = 10 & A:0x7ffc24853c80 M[0][1] = 20 & A:0x7ffc24853c84 M[0][2] = 30 & A:0x7ffc24853c88 M[0][3] = 40 & A:0x7ffc24853c8c M[0][4] = 50 & A:0x7ffc24853c90
M[1][0] = 10 & A:0x7ffc24853c94 M[1][1] = 20 & A:0x7ffc24853c98 M[1][2] = 30 & A:0x7ffc24853c9c M[1][3] = 40 & A:0x7ffc24853ca0 M[1][4] = 50 & A:0x7ffc24853ca4
M[2][0] = 10 & A:0x7ffc24853ca8 M[2][1] = 20 & A:0x7ffc24853cac M[2][2] = 30 & A:0x7ffc24853cb0 M[2][3] = 40 & A:0x7ffc24853cb4 M[2][4] = 50 & A:0x7ffc24853cb8
M[3][0] = 10 & A:0x7ffc24853cbc M[3][1] = 20 & A:0x7ffc24853cc0 M[3][2] = 30 & A:0x7ffc24853cc4 M[3][3] = 40 & A:0x7ffc24853cc8 M[3][4] = 50 & A:0x7ffc24853ccc
2D array using pointer to an array:
// *p gives the address of the first element of the entire 1D array it is pointing too
*p + colindex = 0x7ffc24853c80 + 0 >> M[0][0] = 10 & A:0x7ffc24853c80
*p + colindex = 0x7ffc24853c80 + 1 >> M[0][1] = 20 & A:0x7ffc24853c84
*p + colindex = 0x7ffc24853c80 + 2 >> M[0][2] = 30 & A:0x7ffc24853c88
*p + colindex = 0x7ffc24853c80 + 3 >> M[0][3] = 40 & A:0x7ffc24853c8c
*p + colindex = 0x7ffc24853c80 + 4 >> M[0][4] = 50 & A:0x7ffc24853c90
*p + colindex = 0x7ffc24853c94 + 0 >> M[1][0] = 10 & A:0x7ffc24853c94
*p + colindex = 0x7ffc24853c94 + 1 >> M[1][1] = 20 & A:0x7ffc24853c98
*p + colindex = 0x7ffc24853c94 + 2 >> M[1][2] = 30 & A:0x7ffc24853c9c
*p + colindex = 0x7ffc24853c94 + 3 >> M[1][3] = 40 & A:0x7ffc24853ca0
*p + colindex = 0x7ffc24853c94 + 4 >> M[1][4] = 50 & A:0x7ffc24853ca4
*p + colindex = 0x7ffc24853ca8 + 0 >> M[2][0] = 10 & A:0x7ffc24853ca8
*p + colindex = 0x7ffc24853ca8 + 1 >> M[2][1] = 20 & A:0x7ffc24853cac
*p + colindex = 0x7ffc24853ca8 + 2 >> M[2][2] = 30 & A:0x7ffc24853cb0
*p + colindex = 0x7ffc24853ca8 + 3 >> M[2][3] = 40 & A:0x7ffc24853cb4
*p + colindex = 0x7ffc24853ca8 + 4 >> M[2][4] = 50 & A:0x7ffc24853cb8
*p + colindex = 0x7ffc24853cbc + 0 >> M[3][0] = 10 & A:0x7ffc24853cbc
*p + colindex = 0x7ffc24853cbc + 1 >> M[3][1] = 20 & A:0x7ffc24853cc0
*p + colindex = 0x7ffc24853cbc + 2 >> M[3][2] = 30 & A:0x7ffc24853cc4
*p + colindex = 0x7ffc24853cbc + 3 >> M[3][3] = 40 & A:0x7ffc24853cc8
*p + colindex = 0x7ffc24853cbc + 4 >> M[3][4] = 50 & A:0x7ffc24853ccc
*/
