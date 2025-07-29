#include <stdio.h>

// my solution includes one for loop
void printPatternOne(int max) {
    if(max == 0)
        return;
    for(int i = 0; i < max; i++)
        printf("* ");
    printf("\n");
    printPatternOne(max - 1);
}

// without for loop
void printPatternOne2(int row, int col) {
    // recursion exit condition
    if(row == 0 && col == 0)
        return;
    // for each row exit condition
    if(row == col) {
        printf("\n");
        // start to print from start col, by decreasing row counter
        printPatternOne2(row - 1, 0);
    } else {
        printf("* ");
        // start to increment col counter to print the row pattern
        printPatternOne2(row, col + 1);
    }
}

// without for loop
void printPatternOne3(int row, int col) {
    // recursion exit condition
    if(row == 0 && col == 0)
        return;
    // for each row exit condition
    if(col < row) {
        printf("* ");
        // start to increment col counter to print the row pattern
        printPatternOne2(row, col + 1);
    } else {
        printf("\n");
        // start to print from start col, by decreasing row counter
        printPatternOne2(row - 1, 0);
    }
}

int main(void) {
    int n = 5;
    printPatternOne(n);
    printPatternOne2(n, 0);
    printPatternOne3(n, 0);
/*  Without recursion:
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n - i; j++) {
            printf("* ");
        }
    ;'    printf("\n");
    } */
    return 0;
}
