/* A c program to understand 3D array */
#include <stdio.h>
#define BLOCK 2
#define ROW 3
#define COLUMN 4

// Function declaration
void display(int three_dimension_array[BLOCK][ROW][COLUMN]);

// How to print a 3D array using pointer arithmetic only
void printArray(int (*p)[ROW][COLUMN]);

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
    printArray(matrix);
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
                printf("Matrix[%d][%d][%d] = %d at %p ", 
                        element_block, element_row, element_column, 
                        three_dimension_array[element_block][element_row][element_column],
                        (void *)&three_dimension_array[element_block][element_row][element_column]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

void printArray(int (*p)[ROW][COLUMN]) {
    for(int i = 0; i < BLOCK; i++) {
        p += i;
        /* p will move to the first block of 2D array
         * it will move by sizeof(*p) i.e. size of 1 2D array
         * now p points to the first block p[0][x][x]
         */
        for(int j = 0; j < ROW; j++) {
            int (*ptr)[COLUMN] = *p + j;
            /* in the first inner loop, 
             * here ptr is of type (*p)[COLUMN], so adding anything 
             * will move it by sizeof(1D array).
             *
             * now ptr points to p[0][0][x]
             */
            for(int k = 0; k < COLUMN; k++) {
                printf("Matrix[%d][%d][%d] = %d at %p ", 
                        i, j, k,*(*ptr + k), (void *)(*ptr + k));
                /* ptr is of type (*ptr)[COLUMN], pointer to the whole array.
                 * *ptr is of type (int *) address of the starting element in that array.
                 * any arithmetic on *ptr will move it by sizeof(int)
                 */
            }
            printf("\n");
        }
        printf("\n");
    }
}

// output
/* 
$ ./a.out
Matrix[0][0][0] = 1 at 0x7ffd01083b00 Matrix[0][0][1] = 1 at 0x7ffd01083b04 Matrix[0][0][2] = 1 at 0x7ffd01083b08 Matrix[0][0][3] = 1 at 0x7ffd01083b0c
Matrix[0][1][0] = 2 at 0x7ffd01083b10 Matrix[0][1][1] = 2 at 0x7ffd01083b14 Matrix[0][1][2] = 2 at 0x7ffd01083b18 Matrix[0][1][3] = 2 at 0x7ffd01083b1c
Matrix[0][2][0] = 3 at 0x7ffd01083b20 Matrix[0][2][1] = 3 at 0x7ffd01083b24 Matrix[0][2][2] = 3 at 0x7ffd01083b28 Matrix[0][2][3] = 3 at 0x7ffd01083b2c

Matrix[1][0][0] = 1 at 0x7ffd01083b30 Matrix[1][0][1] = 1 at 0x7ffd01083b34 Matrix[1][0][2] = 1 at 0x7ffd01083b38 Matrix[1][0][3] = 1 at 0x7ffd01083b3c
Matrix[1][1][0] = 2 at 0x7ffd01083b40 Matrix[1][1][1] = 2 at 0x7ffd01083b44 Matrix[1][1][2] = 2 at 0x7ffd01083b48 Matrix[1][1][3] = 2 at 0x7ffd01083b4c
Matrix[1][2][0] = 3 at 0x7ffd01083b50 Matrix[1][2][1] = 3 at 0x7ffd01083b54 Matrix[1][2][2] = 3 at 0x7ffd01083b58 Matrix[1][2][3] = 3 at 0x7ffd01083b5c

// using printArray
Matrix[0][0][0] = 1 at 0x7ffd01083b00 Matrix[0][0][1] = 1 at 0x7ffd01083b04 Matrix[0][0][2] = 1 at 0x7ffd01083b08 Matrix[0][0][3] = 1 at 0x7ffd01083b0c
Matrix[0][1][0] = 2 at 0x7ffd01083b10 Matrix[0][1][1] = 2 at 0x7ffd01083b14 Matrix[0][1][2] = 2 at 0x7ffd01083b18 Matrix[0][1][3] = 2 at 0x7ffd01083b1c
Matrix[0][2][0] = 3 at 0x7ffd01083b20 Matrix[0][2][1] = 3 at 0x7ffd01083b24 Matrix[0][2][2] = 3 at 0x7ffd01083b28 Matrix[0][2][3] = 3 at 0x7ffd01083b2c

Matrix[1][0][0] = 1 at 0x7ffd01083b30 Matrix[1][0][1] = 1 at 0x7ffd01083b34 Matrix[1][0][2] = 1 at 0x7ffd01083b38 Matrix[1][0][3] = 1 at 0x7ffd01083b3c
Matrix[1][1][0] = 2 at 0x7ffd01083b40 Matrix[1][1][1] = 2 at 0x7ffd01083b44 Matrix[1][1][2] = 2 at 0x7ffd01083b48 Matrix[1][1][3] = 2 at 0x7ffd01083b4c
Matrix[1][2][0] = 3 at 0x7ffd01083b50 Matrix[1][2][1] = 3 at 0x7ffd01083b54 Matrix[1][2][2] = 3 at 0x7ffd01083b58 Matrix[1][2][3] = 3 at 0x7ffd01083b5c
*/

