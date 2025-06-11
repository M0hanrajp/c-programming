#include <stdio.h>

int main(void) {
    unsigned int n = 0;
    printf("Enter the number to check if it's even or odd: ");
    scanf("%d", &n);
    printf("%d is %s\n", n, n & 1 ? "Odd" : "Even");
    return 0;
}
