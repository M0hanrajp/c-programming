#include <stdio.h>

// Print to 1 from a given number
int printSequenceDescending(int num) {
    if(num == 0) {
        printf("\n");
        return 0;
    }
    printf("%d ", num);
    return printSequenceDescending(num - 1);
}

// From 1 print to a given max value
int a = 1;
int printSequenceAscending(int num) {
    if(a > num) {
        printf("\n");
        return 0;
    }
    printf("%d ", a++);
    return printSequenceAscending(num);
}

// doing ascending without a global variable
int printSeqAscending(int num) {
    if(num == 0) {
        return 0;
    }
    printSeqAscending(num - 1);
    printf("%d ", num);
    return 0;
}

// Doing ascending descending at the same time
int printBoth(int num) {
    if(num == 0) {
        return 0;
    }
    printf("%d ", num);
    printBoth(num - 1);
    printf("%d ", num);
    return 0;
}

int sumNToOne(int num) {
    if(num == 1) {
        return 1;
    }
    return num + sumNToOne(num - 1);
}

int main(void) {
    int num = 0;
    printSequenceDescending(5);
    printSequenceAscending(5);
    printSeqAscending(5); printf("\n");
    printBoth(3); printf("\n");
    printf("Sum of n to 1 :: %d\n", sumNToOne(5));
    return 0;
}
