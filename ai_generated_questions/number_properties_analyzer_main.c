/*
Problem: Number Properties Analyzer

Write a program that takes an integer N and performs the following operations:
1. Check if N is even or odd using bitwise operator
2. Count the number of set bits (1s) in N
3. Check if N is a power of 2
4. Find the position of rightmost set bit
5. Print the binary representation of N

Input: An integer N
Output: Results of all above operations
*/
#include <stdio.h>

// function declaration 
int checkIsEven(int inputInteger);
int countSetBits(unsigned long inputInteger);
int checkIsPowerOfTwo(int inputInteger);
int rightmostSetbit(int inputInteger);
void displayBinary(int inputInteger);

int main() {

    // user input can be modified but now is kept static
    printf("The number 5 is ");checkIsEven(5) ? printf("even\n") : printf("odd\n");
    printf("Total number of bits set in 4095 is %d\n", countSetBits(4095));
    printf("Given number 4096 is ");checkIsPowerOfTwo(4096) ? printf("Not a power of 2\n") : printf("Is a power of 2\n");
    printf("the rightmost set bit in 40 is %d\n", rightmostSetbit(40));
    printf("10 in 64 bit binary format :: ");displayBinary(10);
    return 0;
}

// function definitions
int checkIsEven(int inputInteger) {
    int result = (inputInteger >> 1) << 1;
    if(result == inputInteger)
        return 1;
    else
        return 0;
}

int countSetBits(unsigned long inputInteger) {
    int count = 0, setResult = 0;
    for(int bits = 63; bits >= 0; bits--) {
        setResult = inputInteger & ((unsigned long)1 << bits);
        if(setResult)
            count++;
    }
    return count;
    /* In this function there are a few important things
     * 1 without a suffix defaults to an int type, which is typically 32 bits on most systems.
     * suffix meaning 1ul - unsigned long 1 (64 bits as long is 8 byte long)
     * why 1 << 32 does not work ?
     * When you shift 1 left by more than 31 bits, the result wraps around or becomes undefined due to the limits of a 32-bit integer.
     * To correctly perform a shift on a 64-bit integer, you need to explicitly indicate that 1 is a 64-bit integer by using 1UL (unsigned long), which ensures it can be shifted within the 64-bit range.
     */
}

int checkIsPowerOfTwo(int inputInteger) {
    return (inputInteger & (inputInteger - 1));
    /* n & (n - 1): This expression clears the lowest set bit of n. If n is a power of 2, this operation will result in 0 because only one bit is set in n.
     * The numbers with power of 2 will only have 1 bit set */
}

int rightmostSetbit(int inputInteger) {
    int bitPosition = 0, findSetBit = 0, count = 0;
    for(bitPosition = 0; bitPosition <= 7; bitPosition++) {
        findSetBit = inputInteger & (1 << bitPosition);
        if(findSetBit){break;}
        count++;
    }
    return count;
}

void displayBinary(int inputInteger) {
    int setResult = 0;
    for(int bits = 63; bits >= 0; bits--) {
        setResult = inputInteger & ((unsigned long)1 << bits);
        setResult ? printf("1") : printf("0");
    }
    printf("\n");
}
