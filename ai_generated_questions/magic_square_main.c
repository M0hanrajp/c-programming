/*
"Create a program that works with a magic square number pattern:
1. Create a 3x3 array of integers
2. Ask the user to input 9 numbers (between 1-9), one at a time
3. Your program should:
   - Validate each input is between 1-9
   - Check that no number is repeated
   - Store these in the 3x3 array
4. After input, check if it forms a magic square where:
   - Each row sum equals 15
   - Each column sum equals 15
   - Both diagonal sums equal 15
5. Finally display:
   - The array in a 3x3 grid format
   - Whether it's a magic square or not
   - If it's not a magic square, show which rows/columns/diagonals don't sum to 15"
*/
#include <stdio.h>
#define SIZE 9

void checkMagicSqaure(int array[SIZE]);

int main() {
    int userInputArray[SIZE] = {0};
    for(int i = 0; i < SIZE; i++) {
        printf("Please enter the element at index %d = ", i);
        scanf("%d", &userInputArray[i]);
        if(userInputArray[i] <= 9 && userInputArray[i] >= 1) {
            int count = 0;
            for (int elementCheck = 0; elementCheck < SIZE; elementCheck++) {
                if(userInputArray[elementCheck] == userInputArray[i]) {
                    count++;
                    if(userInputArray[elementCheck] == userInputArray[i] && count > 1) {
                        printf("Element already entered !, please enter a different element\n");
                        i--;
                        continue;
                    }
                }
            }
        }
        else {
            printf("Please enter number between 1 & 9\n");
            i--;
            continue;
        }
    }
    checkMagicSqaure(userInputArray);
    return 0;
}

void checkMagicSqaure(int array[SIZE]) {
    // check row sum
    int rowOne      = array[0] + array[1] + array[2];
    int rowTwo      = array[3] + array[4] + array[5];
    int rowThree    = array[6] + array[7] + array[8];
    // check column sum
    int columnOne   = array[0] + array[3] + array[6];
    int columnTwo   = array[1] + array[4] + array[7];
    int columnThree = array[2] + array[5] + array[8];
    // check diagonal sum
    int diagonalOne = array[0] + array[4] + array[8];
    int diagonalTwo = array[2] + array[4] + array[6];

    // display the array in 3x3 format
    printf("\nDisplaying the entered array in 3x3 format::\n");
    for(int i = 0; i < SIZE; i++) {
        printf("Index = %d & element = %d  ", i, array[i]);
        if(i == 2 || i == 5 || i == 8)
            printf("\n");
    }
    // check Magic square
    if(rowOne && rowTwo && rowThree == 15) {
        if(columnOne && columnTwo && columnThree == 15) {
            if(diagonalOne && diagonalTwo == 15) {
                printf("It's a Magic square!!\n");
            }
        }
    }
    // Below code will be executed if entered array is not a magic square
    // check diagonals
    if (diagonalOne != 15)
        printf("Index 0, 4 & 8 of array do not sum up to 15 hence it's not a magic square!\n");
    else if (diagonalTwo != 15)
        printf("Index 2, 4 & 6 of array do not sum up to 15 hence it's not a magic square!\n");
    // check columns
    if (columnOne != 15)
        printf("Index 0, 3 & 6 of array do not sum up to 15 hence it's not a magic square!\n");
    else if (columnTwo != 15)
        printf("Index 1, 4 & 7 of array do not sum up to 15 hence it's not a magic square!\n");
    else
        printf("Index 2, 5 & 8 of array do not sum up to 15 hence it's not a magic square!\n");
    // check rows
    if (rowOne != 15)
        printf("Index 0, 1 & 2 of array do not sum up to 15 hence it's not a magic square!\n");
    else if (rowTwo != 15)
        printf("Index 3, 4 & 5 of array do not sum up to 15 hence it's not a magic square!\n");
    else
        printf("Index 6, 7 & 8 of array do not sum up to 15 hence it's not a magic square!\n");
}
