/* ### 7. **Set a Bit Using OR**
   - **Question**: Set the 4th bit of the number `18` (binary: `10010`) using the OR operation.
     - **Hint**: You can set a bit by OR-ing with `1` at the specific position.
     - **Example**: `num = num | (1 << 3)`.
*/
#include <stdio.h>

int main(void) {
    printf("set 5th bit of 47 i.e. 101111 is %d [should be equal to 63]\n", (47 | (1 << 4)));
    printf("set 3rd bit of 11 i.e. 1011 is %d [should be equal to 15]\n", (11 | (1 << 2)));
    return 0;
}

/* Notes
 * The concept of setting a bit involves using bitwise operations to ensure 
 * a specific bit in a binary number is set to 1, while leaving all other bits 
 * unchanged. This is commonly done using the OR (|) operator in conjunction with a mask.
 */
