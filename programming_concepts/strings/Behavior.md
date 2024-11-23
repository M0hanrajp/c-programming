### Program behaviors

- Scanf takes in tokens until "enter" key is used.
- If a space is encountered then it will print all the characters till that first space and rest all characters are included in input buffer.
Error 1:
```bash
basics_main.c: In function ‘main’:
basics_main.c:20:13: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[100]’ [-Wformat=]
   20 |     scanf("%s", &userInput);
      |            ~^   ~~~~~~~~~~
      |             |   |
      |             |   char (*)[100]
      |             char *
```
- &userInput is the address of the array itself, which is a different type (char (*)[100]), not a char *.:w
- How to make scanf take multi word input: [Code snippet here](https://github.com/M0hanrajp/c-programming/blob/1362843e7acf7d6e356f4251bb26b67e8409a068/programming_concepts/strings/basics_main.c#L28)
- when scanf with `%[^\n\s` is used then we need to make sure the input buffer is clear, meaning there should not be any characters left, following is a demonstartion:
```bash
# Full string entered (nromal scanf prints till first space character 
Enter a string:: Coding is tough
Coding
Coding
# Modified scanf that takes multi word string, (it prints here "is tough" from previous string as it was discarded previously by normal scanf
Enter a string::  is tough
 is tough
# need to check from process memory layout POV
```
- learn how scanf reads input and the difference in input buffer.

Error 2:
```bash
basics_main.c: In function ‘displayString’:
basics_main.c:37:49: warning: format ‘%u’ expects argument of type ‘unsigned int’, but argument 4 has type ‘char *’ [-Wformat=]
   37 |         printf("%c & address of element %2d is %u\n", input[i], i, &input[i]);
      |                                                ~^                  ~~~~~~~~~
      |                                                 |                  |
      |                                                 unsigned int       char *
      |                                                %s
```
- To print the address of each element we need argument to be of type (void *)&array[i] cast which is used to ensure type safety and proper formatting when printing pointer addresses with the %p(print address in hexadecimal format) format specifier ( also works with %u & %d, compiler throws warnings here).

Error 3:
```bash
basics_main.c: In function ‘displayString’:
basics_main.c:37:68: warning: cast from pointer to integer of different size [-Wpointer-to-int-cast]
   37 |         printf("%c & address of element %2d is %u\n", input[i], i, (unsigned int)&input[i]);
      |                                                                    ^
```
- Here if I try casting the char* array to unsigned int in order to print address in decimal format it throws errors as, trying to cast a pointer (address) to a type (short unsigned int) that might be of a different size than the pointer itself. On many systems, pointers are typically 4 bytes (32 bits) or 8 bytes (64 bits), while a short unsigned int is usually 2 bytes (16 bits). This mismatch triggers the warning.
- So either use %p to print in hexa decimal format or, use long unsigned int (8 bytes == pointer size) which removes the error. Here it only works because unsigned long int is able to hold the is large enough to hold the value of a pointer on most modern systems (e.g., 64-bit pointers).

Error 4:
```bash
intermediate_basics_main.c: In function ‘main’:
intermediate_basics_main.c:10:10: error: assignment to expression with array type
   10 |     copy = word;
      |          ^
intermediate_basics_main.c:13:10: error: assignment to expression with array type
   13 |     word = "computer";
      |          ^
```
- From intermediate_basics_main.c, we cannot directly assign arrays.

### What is the meaning of string literal
No, `char word[] = "something";` is **not** called a **string literal**. It's a **character array** initialized with a string literal.

Here’s the distinction:

1. **String Literal:**
A **string literal** is a constant sequence of characters enclosed in double quotes. For example:
```c
"something"
```
This is a string literal. It's a read-only sequence of characters stored in a static area of memory.

2. **Character Array:**
When you write:
```c
char word[] = "something";
```
This is a **character array** named `word`, which is being initialized with the string literal `"something"`. The compiler automatically calculates the size of the array based on the string length, including the null terminator `'\0'`.

So, the string literal `"something"` is stored in memory, and the array `word` will hold a **copy** of that string, including the null terminator. It is important to note that `word` is a **modifiable array**, whereas the string literal itself is typically stored in a read-only section of memory.

1. **String Literal (`"something"`):**
   - Constant value.
   - Usually stored in read-only memory (depending on the compiler).
   - Cannot be modified directly.

2. **Character Array (`char word[] = "something";`):**
   - An array of characters.
   - Can be modified (e.g., changing `word[0]` to `'a'`).
   - It copies the string literal into the array at initialization.

- Error: copy = word;
    - copy is a character array (of size 20), and word is also a character array.
    - In C, arrays are not assignable. You cannot assign one array to another directly like this because arrays in C are not pointers (even though they behave like pointers in certain contexts). Why This Fails:
    - Arrays are fixed memory locations, and their address is immutable. The compiler doesn't allow you to reassign the base address of copy to the base address of word.
    - The base address of an array (e.g., word) cannot be changed after declaration. Reassigning the array’s base address like word = "computer"; is invalid in C.
- Pointers can be reassigned to point to another string.
- Pointers can be reassigned to point to the same memory location of the desired variable.

Error 4: While using strcat
- The size of target string should be greater than total amount of characters combined in target string and source string.
```bash
# the reason
~/c-programming/programming_concepts/strings$ gcc -g -Wall -o stringfunc string_functions_main.c
string_functions_main.c: In function ‘main’:
string_functions_main.c:17:5: warning: ‘__builtin_memcpy’ writing 4 bytes into a region of size 2 overflows the destination [-Wstringop-overflow=]
   17 |     printf("After string concatenation: %s\n", strcat("A", "T&T"));
      |     ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
```
- If you increase the size of the input string as shown below, then program exits as segmetation fault.
```bash
// This program uses built in string functions to check their behavior
#include <stdio.h>
#include <string.h>

int main(void) {
    char str[500] = "Happy Coding!", tar[500];

    // How to find length of a string
    printf("Length of a string :: %s is :: %ld\n", str, strlen(str));

    // How to copy a string
    printf("Source string: %s & target string: %s\n", str, strcpy(tar, str));
    /* format of strcpy(char *, const char *)
     * the soruce string is to be treated as constant so that there is no modification when the program is running */

    // Using string concatenation
    printf("After string concatenation: %s\n", strcat("ABCDE", "T&T"));
    return 0;
}
# Below is the result:::
~/c-programming/programming_concepts/strings$ ./stringfunc
Length of a string :: Happy Coding! is :: 13
Source string: Happy Coding! & target string: Happy Coding!
Segmentation fault (core dumped)
```
**Why the Segmentation Fault?**
- When you pass `"ABCDE"` as the first argument to `strcat()`, it tries to append `"T&T"` to `"A"`. This operation attempts to modify the read-only memory, leading to a segmentation fault.
- The segmentation fault occurs because `strcat()` expects the destination string (the first argument) to be modifiable and have enough space to accommodate the concatenated result. However, `"A"` is a string literal, which is stored in read-only memory, and modifying it is undefined behavior.
- Function prototype of strcat `strcat(char *restrict dest, const char *restrict src)`
    - Here dest must be a writable array of characters.
    - dest must have enough space to hold the combined string (original dest plus src).

**Learning:**
- In C, string literals (like "A") are typically stored in read-only memory, so attempting to modify them leads to a segmentation fault.

Error 5: Corssing out of bound and reading strings from adjacent memory locations
- While writing custom strcat function encountered the following behavior
```bash
~/c-programming/programming_concepts/strings$ ./customfunc
Size of string : 41
Input string: Happy Coding, something else, playground. & copied string: Happy Coding, something else, playground.
[DEBUG]:: Silicon Happy Coding, something else, playground.
[DEBUG]:: Silicon cappy Coding, something else, playground.
[DEBUG]:: Silicon chppy Coding, something else, playground.
[DEBUG]:: Silicon chipy Coding, something else, playground.
[DEBUG]:: Silicon chipy Coding, something else, playground.
After string concat: Silicon chip
# notice how the " Chip" is being concatenated, but few other strings are also being read simultaneously
```
- Why this happened ?
The issue arises because of how memory is being handled in the `customStrcat` function. Specifically:
```c
// main function
    // String concatenation
    char a[] = "Silicon";
    char b[] = " chip";
    printf("After string concat: %s\n", customStrcat(a, b));
// the custom funciton
char *customStrcat(char *srcString, char *tarString) {
    int srcStringEndIndex = customStrlen(srcString);
    while (*tarString != '\0') {
        *(srcString + srcStringEndIndex) = *tarString;
        printf("[DEBUG]:: %s\n", srcString);
        srcStringEndIndex++;
        tarString++;
    }
    srcString[srcStringEndIndex] = '\0';
    return srcString;
}
```
1. **Memory Overlap in `customStrcat`:**
   - In the `main()` function, the array `a` has been declared as:
     ```c
     char a[] = "Silicon";
     ```
     The array `a` has just enough space for the characters `"Silicon"` plus the null terminator (`'\0'`), totaling 8 bytes. There’s no extra space allocated in the array to hold the concatenated result.

   - When you attempt to concatenate `" chip"` (which has 6 characters including the space) to `"Silicon"`, the function writes beyond the allocated memory of `a`. This causes **undefined behavior** because it overwrites adjacent memory that may contain other data.

2. **Memory Layout:**
   - Variables like `a`, `b`, and others in the `main` function are often stored contiguously in memory. So, when `customStrcat` writes beyond the bounds of `a`, it’s inadvertently writing into memory that belongs to other variables, such as `str` or `copy`.

3. **Debug Print Output:**
   - This is why, during the concatenation process, the `[DEBUG]` output shows remnants of `"Happy Coding, something else, playground."` appearing after `"Silicon chip"`. The overwritten memory affects other variables’ data, which is then displayed in the debug print.
```bash
# See how the address overalps
mpunix@LIN-5CG3350MRD:~/c-programming/programming_concepts/strings$ ./customfunc
Size of string : 41 & base address: 931343920 # here the string starts at 20 and ends at 61
Input string: Happy Coding, something else, playground. & copied string: Happy Coding, something else, playground.
# Observe srcString starts from 12 and is stored till 19, from 19 to 23 is where strcat starts storing target string
# something like
# a: S   I  L  I  C  O  N '\0'
#    12 13 14 15 16 17 18  19
# b:                       ' '  C   H   I   P
#                          19  20  21  22  23
# thats why after strcat completed till address 23, we can see "Silicon chipy Coding, something else, playground"
# Where chip-24(y) is the start of overalpping
Base address of *srcString = 931343912 & base address of tarString = 931343906
[DEBUG]:: Silicon Happy Coding, something else, playground. & 931343919
[DEBUG]:: Silicon cappy Coding, something else, playground. & 931343920
[DEBUG]:: Silicon chppy Coding, something else, playground. & 931343921
[DEBUG]:: Silicon chipy Coding, something else, playground. & 931343922
[DEBUG]:: Silicon chipy Coding, something else, playground. & 931343923
After string concat: Silicon chip
```
#### Solution:
To fix this issue, you need to allocate enough memory in `a` to hold both `"Silicon"` and `" chip"` concatenated, plus the null terminator. For example:

```c
char a[20] = "Silicon";  // Allocate enough space for the concatenated result
```
So now we can see that there is no address overlap
```bash
# b starts at 654 and ends at 664
# a starts at 664 and ends at 684
# str starts at 696 and ends at 737 >> there is no overlap
Size of string : 41 & base address: 2768403696
Input string: Happy Coding, something else, playground. & copied string: Happy Coding, something else, playground.
Base address of *srcString = 2768403664 & base address of tarString = 2768403654
[DEBUG]:: Silicon  & 2768403671
[DEBUG]:: Silicon c & 2768403672
[DEBUG]:: Silicon ch & 2768403673
[DEBUG]:: Silicon chi & 2768403674
[DEBUG]:: Silicon chip & 2768403675
After string concat: Silicon chip
```
Error 6: Difference between ||, && conditions

- While traversing through a string, your requirement is to stop at a point if you encounter NULL, space or hiphen.
- In such condition, my mistake was using `||` condition saying if meets any NULL, space or hiphen.
- But this is where I was wrong because, in `for (int i = position - 1; string[i] != '\0' || string[i] != ' ' || string[i] != '-'; i++)`
    - When combined with ||, the loop continues if any one of these conditions is true. However, this logic is flawed:
    - At least one condition will always be true because, for example, even if the character is ' ', it is not '\0', so the loop won't stop when it should.At least one condition will always be true because, for example, even if the character is ' ', it is not '\0', so the loop won't stop when it should.
- This is why && correctly controls the loop to extract until one of the stop conditions is met.
- if not program results in segementation fault.

Error 7: attempting to use increment operator over static variable.
```bash
char *extractFromPosition(int position, const char *string) {
    static char userOutput[SIZE];
    for (int i = position - 1; string[i] != '\0' || string[i] != ' ' || string[i] != '-'; i++) {
        *userOutput = string[i];
        userOutput++; # Error point
    }
    return userOutput;
} I want problem_c.c: In function ‘extractFromPosition’:
problem_c.c:18:19: error: lvalue required as increment operand
   18 |         userOutput++;
      |
```
- The error you're encountering (lvalue required as increment operand) is due to attempting to increment the userOutput pointer, which points to a statically declared array. Since userOutput is statically allocated, modifying the pointer itself doesn't affect the static array correctly, and this causes undefined behavior.
- Learn the difference of why you cannot incerment here ?
