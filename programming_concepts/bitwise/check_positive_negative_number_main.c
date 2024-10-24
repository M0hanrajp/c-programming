/* ### 12. **Sign Checking Using Right Shift**
   - **Question**: Use bitwise operators to check if a number is negative or positive by checking the sign bit (the leftmost bit).
     - **Hint**: Perform a right shift by `(sizeof(int) * 8 - 1)` and check if the result is `1` (for negative) or `0` (for positive).
*/
#include <stdio.h>

int checkSignOfNumber(int user_input);

int main(void) {
    checkSignOfNumber(-5) ? printf("Negative\n") : printf("Positive\n");
    return 0;
}

int checkSignOfNumber(int user_input) {
    int result = user_input >> (sizeof(int) * 8 - 1);
    return result;
}
