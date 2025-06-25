#include <stdio.h>

int calPowerOfN(int n, int k) {
    if(k == 0)
        return 1;
    if(k == 1)
        return n;
    return n * calPowerOfN(n, k - 1);
}

int main(void) {
    int num = 0;
    int exp = 0;
    printf("Enter the base and exponnent with space\nexample: 2^2 enter as 2 2: ");
    scanf("%d %d", &num, &exp);
    printf("The value of %d rasied to %d is:: %d\n", num, exp, calPowerOfN(num, exp));
    return 0;
}
