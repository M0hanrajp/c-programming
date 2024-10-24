/*
### 5. **Toggle Bits Using XOR**
   - **Question**: Toggle the 3rd bit of the number `29` (binary: `11101`) using the XOR operation.  
     - **Hint**: You can toggle a bit by performing XOR with `1` at the specific bit's position.
     - **Example**: `num = num ^ (1 << 2)` (for toggling the 3rd bit).
*/
#include <stdio.h>

int main(void) {
    int num = 29; // 11101
    printf("toggle 3rd bit of 11101 is : %d\n", num ^ (1 << 2));
    printf("toggle 1st bit of 11101 is : %d\n", num ^ (1 << 4));
    return 0;
}
