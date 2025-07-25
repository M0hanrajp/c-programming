#include <stdio.h>

int main(void) {
    int num = 45;
    // find the ith bit (what is the ith bit inside decimal 45 i.e. 101101
    int bit = 4;
    printf("%d bit in %d is :: %d\n", bit, num, num & (1u << (bit - 1)));
    return 0;
}
