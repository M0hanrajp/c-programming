/* A c program to understand 2D array */
#include <stdio.h>
#define ROW 3
#define COLUMN 4

int main(void)
{
    int matrix[ROW][COLUMN] = {0};
    
    // Populating all the required data into the array
    for(int element_row = 0; element_row < ROW; element_row++)
    {
        for(int element_column = 0; element_column < COLUMN; element_column++)
        {
            if(element_row == 0)
                matrix[element_row][element_column] = 1;
            if(element_row == 1)
                matrix[element_row][element_column] = 2;
            if(element_row == 2)
                matrix[element_row][element_column] = 3;
        }
    }
    for(int element_row = 0; element_row < ROW; element_row++)
    {
        for(int element_column = 0; element_column < COLUMN; element_column++)
        {
            printf("Matrix[%2d][%2d] = %d ", element_row, element_column, matrix[element_row][element_column]);
        }
        printf("\n");
    }
    return 0;
}
