#include <stdio.h>

int sumOfDigits(int num) {
    if(num < 9) {
        return num;
    }
    return (num % 10) + sumOfDigits((num / 10));
}

int main(void) {
    printf("Sum of digits :: %d\n", sumOfDigits(125542));
    return 0;
}
