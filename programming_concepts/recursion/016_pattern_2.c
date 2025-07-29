#include <stdio.h>

// without for loop
void printPatternTwo(int row, int col) {
    // recursion exit condition
    if(row == 0 && col == 0)
        return;
    // for each row exit condition
    if(col < row) {
        // start to increment col counter to print the row pattern
        printPatternTwo(row, col + 1);
        printf("* ");
    } else {
        // start to print from start col, by decreasing row counter
        printPatternTwo(row - 1, 0);
        printf("\n");
    }
}

// my solution
void printPattern(int max, int row, int col) {
    if(row > max)
        return;
    if(col < row) {
        printf("* ");
        printPattern(max, row, col + 1);
    } else {
        printf("\n");
        printPattern(max, row + 1, 0);
    }
}


int main(void) {
    int n = 4;
    //printPatternTwo(n, 0);
    // caution does not print new line at the last row
    // prints newline at the begining
    printPattern(n, 1, 0);
    return 0;
}
