#include <stdio.h>

int cz = 0;
int countNumZeros(int num) {
    if(num == 0)
        return 0;
    int rem = num % 10;
    /* if rem = 0, it means the digit was 0
     * increment cz only if the digit is 0 else do nonthing
     */
    cz += (rem ? 0 : 1);
    countNumZeros(num / 10);
    return cz;
}

int main(void) {
    int num = 10030980;
    printf("The number of zeros present in %d are :: %d\n", num, countNumZeros(num));
    return 0;
}
