/* ### 8. **Checking if a Bit is Set**
   - **Question**: Write a program to check if the 5th bit of a number `n` is set or not.
     - **Example**: Use the expression `n & (1 << 4)` to check if the 5th bit is `1`.
*/
#include <stdio.h>

// function declaration
int checkBitSetOrNotSet(int user_input, int bitPosition);

int countSetNumberOfBits(int user_input);

int main(void) {
    checkBitSetOrNotSet(10, 1) ? printf("Bit is Set\n") : printf("Bit is not Set\n");
    printf("The total number of bit set in 15 are: %d\n", countSetNumberOfBits(15));
    return 0;
}

// function definition
int checkBitSetOrNotSet(int user_input, int bitPosition) {
    // consider highest number is 15 hence there would be only 4 bits
    int result = 0;
    if (user_input & (1 << bitPosition))
        return result = 1;
    else
        return result = 0;
}

int countSetNumberOfBits(int user_input) {
    int count = 0;
    for(int bitPosition = 0; bitPosition < 4; bitPosition++) {
        if(user_input & (1 << bitPosition))
            count++;
    }
    return count;
}

/* Notes
 * The concept of setting a bit involves using bitwise operations to ensure 
 * a specific bit in a binary number is set to 1, while leaving all other bits 
 * unchanged. This is commonly done using the OR (|) operator in conjunction with a mask.
 */
