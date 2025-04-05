// A calculator program for console.
#include <stdio.h>
#include <stdlib.h>

void calculator(int integerA, char arithemticOperator, int integerB) {
    switch (arithemticOperator) {
        case '+' : printf("%d\n", integerA + integerB); break;
        case '-' : printf("%d\n", integerA - integerB); break;
        case '/' : printf("%d\n", integerA / integerB); break;
        case 'x' : printf("%d\n", integerA * integerB); break;
        default  : break;
    }
}

int main(int argc, char *argv[]) {
    // check for arguments
    if(argc != 4)
        perror("");
    
    // calculate
    calculator(atoi(argv[1]), *argv[2], atoi(argv[3]));

    return 0;
}
