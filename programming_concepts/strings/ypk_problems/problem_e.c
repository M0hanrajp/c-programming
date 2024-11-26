// Program to print a fibonacci series using character
#include <stdio.h>
#include <string.h>

void printFibonacci(char f0[10], char f1[10], int);

int main(void) {
    printFibonacci("a", "b", 10);
    return 0;
}

void printFibonacci(char f0[10], char f1[10], int order) {
    int term = 0;
    // increase the size of tempf1 & tempf2 if you need to print more than order 10
    char tempf1[100];
    char tempf0[100];
    char tempHold[100];
    strcpy(tempf0, f0);
    strcpy(tempf1, f1);
    while (term < order) {
        if(term == 0) {
            printf("Order %d :: %s\n", term, tempf0);
            term++;
            continue;
        }
        if(term == 1) {
            printf("Order %d :: %s\n", term, tempf1);
            term++;
            continue;
        }
        if(term >= 2 ) {
            strcpy(tempHold, tempf1);
            strcat(tempf1, tempf0);
            printf("Order %d :: %s\n", term, tempf1);
            strcpy(tempf0, tempHold);
            term++;
        }
    }
}
