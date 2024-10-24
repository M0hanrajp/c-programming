/* ### 11. **Find the Odd Occurring Element Using XOR**
   - **Question**: Given an array where all elements occur an even number of times except one, find the element that occurs an odd number of times using XOR.
     - **Example Array**: `{1, 2, 3, 2, 3, 1, 3}`
     - **Hint**: XOR all the elements; the result will be the element with odd occurrences.
*/
#include <stdio.h>

// function declaration 
int findOddOccurringElement(int array[], int size);

int main(void) {
    int array[7] = {1, 2, 3, 2, 3, 1, 1};
    printf("The odd occurring element : %d\n", findOddOccurringElement(array, 7));
    return 0;
}

int findOddOccurringElement(int array[], int size) {
    int element = 0;
    for(int i = 0; i < size; i++) {
        element = element ^ array[i];
    }
    return element;
}
