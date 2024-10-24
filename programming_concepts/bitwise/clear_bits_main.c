/* ### 6. **Clearing a Bit Using AND**
   - **Question**: Clear the 2nd bit of the number `45` (binary: `101101`) using a bitwise AND operation.
     - **Hint**: To clear a bit, AND the number with a mask where the bit to be cleared is `0`, and all other bits are `1`.
     - **Example**: `num = num & ~(1 << 1)`.
*/
#include <stdio.h>

int main(void) {
    printf("Clear 2nd bit of 47 i.e. 101111 is %d [should be equal to 45]\n", (47 & ~(1 << 1)));
    printf("Clear 6th bit of 47 i.e. 101111 is %d [should be equal to 15]\n", (47 & ~(1 << 5)));
    return 0;
}

/* Notes
 * The concept of clearing a bit involves using bitwise operations to set a specific bit in a binary
 * number to 0 while leaving all other bits unchanged. This is commonly done using the AND (&) 
 * operator in conjunction with a mask.
 */
