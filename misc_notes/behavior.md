### Notes & Observations on program behavior

- [Usage of Address sanitizer for identifying buffer overflow](https://github.com/M0hanrajp/c-programming/blob/3f9dfff9e48001f90862218aa9ce74961c014bf9/compilation_process/quiz.md?plain=1#L55)
- [Identifying linker errors with gcc commands](https://github.com/M0hanrajp/c-programming/blob/3f9dfff9e48001f90862218aa9ce74961c014bf9/compilation_process/quiz.md?plain=1#L178)
- [How to extract digits (individually) from an integer](https://github.com/M0hanrajp/c-programming/blob/master/misc_notes/How%20to%20dervice%20digits%20from%20a%20int%20number.md#extract-digits-from-right-to-left).

### Errors
- [Computation error during bit manipulation of 64 bit integer](https://github.com/M0hanrajp/c-programming/blob/3f9dfff9e48001f90862218aa9ce74961c014bf9/ai_generated_questions/number_properties_analyzer_main.c#L54)
  - How compiler behaves and consideres integer during 64 & 32 bit compilation.
- use `<stdlib>` if you want to use `NULL` keyword.
- when you use a `return` statement inside a loop, the function will **terminate immediately**, and control will return to the caller. Any code after the `return` statement within the function will **not be executed**.
#### Example:
```c
#include <stdio.h>
bool checkCondition(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {  // If a negative number is found
            return false;  // Function ends here if the condition is true
        }
    }
    return true;  // Only reached if the loop completes without returning
}
int main() {
    int data[] = {1, 2, -3, 4, 5};
    int size = sizeof(data) / sizeof(data[0]);

    if (checkCondition(data, size)) {
        printf("All numbers are positive.\n");
    } else {
        printf("Found a negative number.\n");
    }
    return 0;
}
```
#### Explanation:
1. The loop iterates through the array.
2. If it finds a negative number (`arr[i] < 0`), it calls `return false;`.
3. **At that point, the function stops execution immediately**, and `false` is returned to the caller (`main()` in this case).
4. The code after the loop (like `return true;`) is **skipped** if `return false;` is hit.
#### Key points:
- **Immediate exit**: `return` ends the function instantly.
- **Outer code ignored**: No further code inside the function is executed after `return`.
- **Loop termination**: The loop stops processing once `return` is called.

### Error - integer division
```bash
    int a = 10, b = 10, c = 13;
    float s1 = a + b + c / 2;      // Without parentheses
    # this is the way
    float s2 = a + b + c / 2.0;
```
- here s1 = 26.00 (a + b + c / 2), a b & c are integers and dividing by 2 gives integer division rather than floating point division, even though the result is assigned to float.
- s2 = 26.50 (a + b + c / 2.0), a b & c are integer but divisor is floating point number, the integers are promoted to floating numbers and operation is performed (the correct way).

### How to control precision of a number during calculation
```bash
double rounded = round(num * 100.0) / 100.0; // Round to 2 decimal places
```
Use the math.h library to use the round function.
