/* A c program to understand 3D array */
#include <stdio.h>
#define BLOCK 2
#define ROW 3
#define COLUMN 4

// Function declaration
void display(int three_dimension_array[BLOCK][ROW][COLUMN]);
// main function
int main(void)
{
    int matrix[BLOCK][ROW][COLUMN] = {0};

    // Populating all the required data into the array
    for(int element_block = 0; element_block < BLOCK; element_block++)
    {
        for(int element_row = 0; element_row < ROW; element_row++)
        {
            for(int element_column = 0; element_column < COLUMN; element_column++)
            {
                if(element_row == 0)
                    matrix[element_block][element_row][element_column] = 1;
                if(element_row == 1)
                    matrix[element_block][element_row][element_column] = 2;
                if(element_row == 2)
                    matrix[element_block][element_row][element_column] = 3;
            }
        }
    }

    // calling the function to display the program
    display(matrix);
    return 0;
}
// Funciton definition
void display(int three_dimension_array[BLOCK][ROW][COLUMN])
{
     for(int element_block = 0; element_block < BLOCK; element_block++)
    {   
        for(int element_row = 0; element_row < ROW; element_row++)
        {
            for(int element_column = 0; element_column < COLUMN; element_column++)
            {
                printf("Matrix[%d][%d][%d] = %d ", element_block, element_row, element_column, three_dimension_array[element_block][element_row][element_column]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
// output
/* 
$ ./a.out
Matrix[0][0][0] = 1 Matrix[0][0][1] = 1 Matrix[0][0][2] = 1 Matrix[0][0][3] = 1
Matrix[0][1][0] = 2 Matrix[0][1][1] = 2 Matrix[0][1][2] = 2 Matrix[0][1][3] = 2
Matrix[0][2][0] = 3 Matrix[0][2][1] = 3 Matrix[0][2][2] = 3 Matrix[0][2][3] = 3

Matrix[1][0][0] = 1 Matrix[1][0][1] = 1 Matrix[1][0][2] = 1 Matrix[1][0][3] = 1
Matrix[1][1][0] = 2 Matrix[1][1][1] = 2 Matrix[1][1][2] = 2 Matrix[1][1][3] = 2
Matrix[1][2][0] = 3 Matrix[1][2][1] = 3 Matrix[1][2][2] = 3 Matrix[1][2][3] = 3
*/
