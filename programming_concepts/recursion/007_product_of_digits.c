#include <stdio.h>

int productOfDigits(int num) {
    if(num < 9) {
        return num;
    }
    return (num % 10) * productOfDigits((num / 10));
}

int main(void) {
    printf("Product of digits :: %d\n", productOfDigits(125));
    return 0;
}
