#include <stdio.h>

int main(void) {
    int a = 0, b = 0;
    printf("Enter the value of A: ");
    scanf("%d", &a);
    printf("Enter the value of B: ");
    scanf("%d", &b);
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    printf("After swap A: %d & B: %d\n", a, b);
    return 0;
}
