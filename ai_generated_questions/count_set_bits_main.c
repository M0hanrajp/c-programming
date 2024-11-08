/* Implement a function that counts the number of set bits (bits with value 1) in a 32-bit 
 * unsigned integer efficiently. The function should have the following signature:

```c
uint32_t count_set_bits(uint32_t n);
```

Requirements:
1. The function should use only bitwise operations, no loops or conditional statements.
2. The function should be as efficient as possible in terms of time complexity.
3. Provide test cases to verify the correctness of your implementation. */
#include <stdio.h>

unsigned int countSetBits(unsigned int n);

int main() {
    printf("::%u::\n", countSetBits(255));
    return 0;
}

unsigned int countSetBits(unsigned int n) {
    n = n - ((n >> 1) & 0x55555555);               // count bits in pairs
    n = (n & 0x33333333) + ((n >> 2) & 0x33333333); // count bits in nibbles
    n = (n + (n >> 4)) & 0x0F0F0F0F;               // count bits in bytes
    n = n + (n >> 8);                              // count bits in 2-byte groups
    n = n + (n >> 16);                             // count bits in 4-byte groups
    return n & 0x3F;                               // mask to get result in range
}
