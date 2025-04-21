#include <stdio.h>
#define ROW 2
#define COL 3
int main(void) {
    int arr[ROW][COL] = { {1, 3, 5}, {2, 4, 6}};
    int arrT[COL][ROW] = {0};
    printf("Normal array: \n");
    for (int i = 0; i < ROW; i++) {
        for(int j = 0; j < COL; j++) {
            printf("Element[%d][%d] = %d ", i, j, arr[i][j]);
        }
        printf("\n");
    }
    // Transpose
    // col will be rows & rows will become columns
    printf("Transpose of array :: \n");
    for(int i = 0; i < COL; i++) {
        for(int j = 0; j < ROW; j++) {
            arrT[i][j] = arr[j][i];
            printf("Element[%d][%d] = %d ", i, j, arrT[i][j]);
        }
        printf("\n");
    }
    return 0;
}

// output
/*
$ ./a.out
Normal array:
Element[0][0] = 1 Element[0][1] = 3 Element[0][2] = 5
Element[1][0] = 2 Element[1][1] = 4 Element[1][2] = 6
Transpose of array ::
Element[0][0] = 1 Element[0][1] = 2
Element[1][0] = 3 Element[1][1] = 4
Element[2][0] = 5 Element[2][1] = 6
*/
