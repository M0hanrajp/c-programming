### Extract digits from right to left:
1. **Isolate each digit**: Use division (`/`) and modulo (`%`) operations.
2. **Process each digit**: Apply any mathematical computation inside the loop.

### Example Code:
```c
#include <stdio.h>

void processDigits(int num) {
    int digit;
    
    // Ensure the number is within the expected range
    // this works for any number of size, change the data type based on size.
    if (num < 0 || num > 9999) {
        printf("Number out of range.\n");
        return;
    }

    printf("Digits of %d are:\n", num);

    while (num > 0) {
        digit = num % 10;           // Extract the last digit
        num /= 10;                  // Remove the last digit
        
        // Perform mathematical computation (example: square the digit)
        int result = digit * digit;  
        printf("Digit: %d, Squared: %d\n", digit, result);
    }
}

int main() {
    int number;

    printf("Enter a number (0 - 9999): ");
    scanf("%d", &number);

    processDigits(number);

    return 0;
}
```

### Explanation:
- **Modulo operation (`num % 10`)**: Extracts the last digit.
- **Division (`num /= 10`)**: Removes the last digit, shifting the number to the right.
- **Loop**: Repeats until all digits are processed (i.e., `num` becomes zero).

### Example:
For input `1234`, the output will be:
```
Digit: 4, Squared: 16
Digit: 3, Squared: 9
Digit: 2, Squared: 4
Digit: 1, Squared: 1
```

You can replace the computation inside the loop with any mathematical operation you need.

To extract digits starting from the **leftmost** digit, you need to first determine the number of digits and then isolate each digit from left to right. Here's how you can do it:

### Steps:
1. **Find the total number of digits**: Use a loop to determine the highest place value.
2. **Extract each digit**: Divide the number by powers of 10 and use modulo operations to isolate each digit in sequence from left to right.

### Example Code:
```c
#include <stdio.h>

void processDigitsLeftToRight(int num) {
    int divisor = 1;

    // Ensure the number is within the expected range
    // this works for any number of size, change the data type based on size.
    if (num < 0 || num > 9999) {
        printf("Number out of range.\n");
        return;
    }

    // Find the highest divisor (10^n) to extract the leftmost digit
    while (num / divisor >= 10) {
        divisor *= 10;
    }

    printf("Processing digits from left to right:\n");

    while (divisor > 0) {
        int digit = (num / divisor) % 10;  // Extract the leftmost digit
        divisor /= 10;                     // Move to the next digit
        
        // Perform any mathematical operation here
        printf("Digit: %d\n", digit);
    }
}

int main() {
    int number;

    printf("Enter a number (0 - 9999): ");
    scanf("%d", &number);

    processDigitsLeftToRight(number);

    return 0;
}
```

### Explanation:
1. **Find the divisor**: The `divisor` starts at 1 and is multiplied by 10 until it's the highest power of 10 less than or equal to the number.
2. **Extract digits from left to right**:
   - `(num / divisor) % 10` isolates the current leftmost digit.
   - `divisor /= 10` moves to the next lower place value.
3. **Loop continues** until all digits are processed.

### Example Execution:
For an input of `9876`, the output will be:
```
Processing digits from left to right:
Digit: 9
Digit: 8
Digit: 7
Digit: 6
```
This method ensures that each digit is processed from the leftmost to the rightmost, preserving the order.
