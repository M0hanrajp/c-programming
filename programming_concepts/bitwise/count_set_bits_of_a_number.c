#include <stdio.h>

int main(void) {
    unsigned long n = 0;
    printf("Enter the number to check number of set bits: ");
    scanf("%lu", &n);
    int setBits = 0;
    for(int i = 63; i >= 0; i--)
        if((n & (1ul << i)))
            setBits++;
    printf("The total number of set bits in %lu is %d\n", n, setBits);
    return 0;
}

/* Kernighan's algorithm

   while (n) {
    n &= (n - 1);  // clear the lowest set bit
    setBits++;
   }

*/
