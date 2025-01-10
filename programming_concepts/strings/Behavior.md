### Program behaviors

- Scanf takes in tokens until "enter" key is used.
- If a space is encountered then it will print all the characters till that first space and rest all characters are included in input buffer.

## Error 1:
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

## Error 2:
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

## Error 3:
```bash
basics_main.c: In function ‘displayString’:
basics_main.c:37:68: warning: cast from pointer to integer of different size [-Wpointer-to-int-cast]
   37 |         printf("%c & address of element %2d is %u\n", input[i], i, (unsigned int)&input[i]);
      |                                                                    ^
```
- Here if I try casting the char* array to unsigned int in order to print address in decimal format it throws errors as, trying to cast a pointer (address) to a type (short unsigned int) that might be of a different size than the pointer itself. On many systems, pointers are typically 4 bytes (32 bits) or 8 bytes (64 bits), while a short unsigned int is usually 2 bytes (16 bits). This mismatch triggers the warning.
- So either use %p to print in hexa decimal format or, use long unsigned int (8 bytes == pointer size) which removes the error. Here it only works because unsigned long int is able to hold the is large enough to hold the value of a pointer on most modern systems (e.g., 64-bit pointers).

## Error 4:
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

## Error 4: While using strcat
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

### Logical error while using strcat

- strcat is used to appened a string (That is null terminated) from destination to source.
- it is not used to concat individual characters.
- use assignment for individual characters instead of strcat.
- it will start copying from the position of character till the strings end i.e. '\0'.
```bash
(gdb) p strings
$1 = (const char * const *) 0x7fffffffdc30
(gdb) p strings[0]
$2 = 0x555555556004 "yoda"
(gdb) p strings[1]
$3 = 0x555555556009 "best"
(gdb) p strings[2]
$4 = 0x55555555600e "has"
(gdb) p strings[0][0]
$5 = 121 'y'
(gdb) p strings[1][1]
$6 = 101 'e'
(gdb) p strings[2][2]
$7 = 115 's'
(gdb) n
6         for(size_t i = 0; i < length; i++)
(gdb) info locals
i = 0
str_out = 0x5555555592a0 "yoda" // entire string is copied instead of individual character
(gdb) n
7           strcat(&str_out[i], &strings[i][i]);
(gdb) n
6         for(size_t i = 0; i < length; i++)
(gdb) info locals
i = 1
str_out = 0x5555555592a0 "yodaest" // For i = 1, &strings[1][1] points to 'e'. strcat appends "est" from position &str_out[1], overwriting part of the existing content ("yoda").
```
## Error 5: Corssing out of bound and reading strings from adjacent memory locations
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
## Error 6: Difference between ||, && conditions

- While traversing through a string, your requirement is to stop at a point if you encounter NULL, space or hiphen.
- In such condition, my mistake was using `||` condition saying if meets any NULL, space or hiphen.
- But this is where I was wrong because, in `for (int i = position - 1; string[i] != '\0' || string[i] != ' ' || string[i] != '-'; i++)`
    - When combined with ||, the loop continues if any one of these conditions is true. However, this logic is flawed:
    - At least one condition will always be true because, for example, even if the character is ' ', it is not '\0', so the loop won't stop when it should.At least one condition will always be true because, for example, even if the character is ' ', it is not '\0', so the loop won't stop when it should.
- This is why && correctly controls the loop to extract until one of the stop conditions is met.
- if not program results in segementation fault.

## Error 7: attempting to use increment operator over static variable.
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

## Error 8: For segemenatation fault in string programs
```bash
(gdb) n

Program received signal SIGSEGV, Segmentation fault.
__strcpy_evex () at ../sysdeps/x86_64/multiarch/strcpy-evex.S:553
553     ../sysdeps/x86_64/multiarch/strcpy-evex.S: No such file or directory.
(gdb) q
A debugging session is active.

        Inferior 1 [process 52043] will be killed.
```
- Check if memory allocated to a string is enough to handle operations during strcat, strcpy etc..

## Error 9: strcpy(str[0], f0);  // is Invalid

No, this line is **not valid** in C:

```c
strcpy(str[0], f0);  // Invalid
```
Here's why:

#### Problem Breakdown:
1. **`str[0]`:**  
   `str` is declared as a **character array** (`char str[20];`), so `str[0]` refers to the **first element** of this array. Since each element of the array is a single `char`, `str[0]` is of type `char`, not `char *` (a pointer to a character string).  
   
   Therefore, `str[0]` is just a **single character** (like `'A'`), not a place to hold an entire string.

2. **`strcpy` Function:**  
   The `strcpy` function is used to **copy a string** from one location to another. Its signature is:
   ```c
   char *strcpy(char *destination, const char *source);
   ```
   Both `destination` and `source` need to be **pointers to character arrays** (or strings).

#### Correct Usage:
If you want to copy the string `f0` into the `str` array, you should provide the **address** of the starting element (`str` itself):

```c
strcpy(str, f0);  // Valid
```

### Explanation:
- **`str`:** When you use the name of the array (`str`) without an index, it decays to a **pointer to the first element** (`&str[0]`).
- **`f0`:** This is assumed to be a `const char *`, representing a string.

How can we avoid this problem ? >> need to explore it using 2D arrays.

## Error 10: char *tempf1 = 0 is not a good idea because it does not point to any valid memory location.
```bash
14          char *tempf1 = 0;
(gdb) n
15          char *tempf0 = 0;
```
- tempf0 doesn't point to any valid memory location. When you call strcpy(tempf0, f0);, the function attempts to write to the location pointed to by tempf0, which is null, causing a segmentation fault.
- Either use malloc to dynamically allocate the memory, or declare it as array of some x size.
    - Uninitialized pointers or null pointers cannot be used with functions like strcpy.
    - Always ensure that pointers point to valid, allocated memory before writing to them.

## Error 11: argumemt mismatch bound (warning)
```bash
mpunix@LIN-5CG3350MRD:~/c-programming/programming_concepts/strings/ypk_problems$ gcc -g -Wall -o e problem_e.c
problem_e.c:12:26: warning: argument 1 of type ‘char[10]’ with mismatched bound [-Warray-parameter=]
   12 | void printFibonacci(char f0[10], char f1[10], int order) {
      |                     ~~~~~^~~~~~
problem_e.c:5:21: note: previously declared as ‘char *’
    5 | void printFibonacci(char *, char *, int);
      |                     ^~~~~~
problem_e.c:12:39: warning: argument 2 of type ‘char[10]’ with mismatched bound [-Warray-parameter=]
   12 | void printFibonacci(char f0[10], char f1[10], int order) {
      |                                  ~~~~~^~~~~~
problem_e.c:5:29: note: previously declared as ‘char *’
    5 | void printFibonacci(char *, char *, int);
      |                             ^~~~~~
```
- Compiler warning when function prototype is declared as char * (argument).
- In C, when you declare a function parameter like char f0[10], it's actually interpreted as char *f0. This is because arrays decay into pointers when passed to functions.
- However, the compiler warning is triggered because the declared size [10] doesn’t match the implicit pointer behavior.
- The compiler warns that the declared size (10) is ignored in the parameter list, which might lead to confusion or incorrect assumptions about the array bounds.
    - Here when I was writing the program I wanted, f0 and f1 to have 10 bytes initially which is not possible to declare it this way.

## Error 12: Do not use Malloc/calloc for the arguments of function because function arguments get input prior to function call.
```bash
Breakpoint 1, main () at problem_e.c:9
9           printFibonacci("a", "b", 5);
(gdb) s
# here function arguments already have inputs a & b
printFibonacci (f0=0x555555556006 "a", f1=0x555555556004 "b", order=5) at problem_e.c:13
13      void printFibonacci(char *f0, char *f1, int order) {
(gdb) n
14          int term = 0;
(gdb) n

# I used malloc to allocate size
15          f0 = (char *)malloc(10 * sizeof(char));
(gdb) n
16          f1 = (char *)malloc(10 * sizeof(char));
(gdb) n
18          if (f0 == NULL || f1 == NULL) {

# here we can see the allocated memory points to different location causing the 
# data to be lost
(gdb) p f0
# 
$1 = 0x5555555592a0 ""
(gdb) q
A debugging session is active.

        Inferior 1 [process 52778] will be killed.

Quit anyway? (y or n) t
Please answer y or n.
A debugging session is active.

        Inferior 1 [process 52778] will be killed.
```

## Error 13: function accessing 10 bytes in a reigon of size 2
```bash
mpunix@LIN-5CG3350MRD:~/c-programming/programming_concepts/strings/ypk_problems$ gcc -g -Wall -o e problem_e.c
problem_e.c: In function ‘main’:
problem_e.c:8:5: warning: ‘printFibonacci’ accessing 10 bytes in a region of size 2 [-Wstringop-overflow=]
    8 |     printFibonacci("a", "b", 5);
      |     ^~~~~~~~~~~~~~~~~~~~~~~~~~~
problem_e.c:8:5: note: referencing argument 1 of type ‘char *’
problem_e.c:8:5: warning: ‘printFibonacci’ accessing 10 bytes in a region of size 2 [-Wstringop-overflow=]
problem_e.c:8:5: note: referencing argument 2 of type ‘char *’
problem_e.c:12:6: note: in a call to function ‘printFibonacci’
   12 | void printFibonacci(char f0[10], char f1[10], int order) {
      |      ^~~~~~~~~~~~~~
```
#### **Understanding the Warning in Detail:**

This warning relates to how **string literals** and **arrays** interact in C, especially in terms of **memory access and safety**.

---

#### **The Key Issue:**

1. **String Literals and Memory Size:**
   - When you pass `"a"` and `"b"` to `printFibonacci`, these are **string literals**:
     - `"a"` is **2 bytes**: one for `'a'` and one for the **null terminator** (`'\0'`).
     - `"b"` is also **2 bytes**.

2. **Function Parameter Declaration:**
   ```c
   void printFibonacci(char f0[10], char f1[10], int order);
   ```
   - Although `f0` and `f1` are declared as `char f0[10]` and `char f1[10]`, when passed to the function, they **decay** to pointers (`char *`).
   - The function has **no information** about the actual size of the memory being passed (only the address of the first character).

3. **Why the Warning?**
   - Inside the function, if you attempt to copy or access up to **10 bytes** (as suggested by the `char f0[10]` declaration), you’ll exceed the memory allocated for the string literals (`"a"` and `"b"`)—which only have **2 bytes**.
   - This results in **undefined behavior** and potential **buffer overflow**.

---

#### **Memory Layout Example:**

- `"a"` is stored in memory like this:
  ```
  | 'a' | '\0' |
  ```
  - Total size: **2 bytes**
- If you attempt to copy **10 bytes** from `"a"`, you'll read past the `'\0'` into **unallocated memory**.

---

#### **Why Does This Matter?**

- **Buffer Overflow Risk:** Accessing memory beyond what’s allocated can:
  - **Corrupt data** in nearby memory.
  - Cause **segmentation faults**.
  - Lead to **security vulnerabilities**.

- **Size Mismatch:** The compiler is warning you because it detects that the function expects larger data (`10 bytes`), but only a small region (`2 bytes`) is being provided.
- The warning is about trying to access **more memory** than is available.
- **Solution:** Allocate sufficient memory for the strings and handle them carefully within the function.

## Error 14: Allocation of memeory to a char array (string)
```bash
~/c-programming/programming_concepts/strings$ gcc -g -Wall -o debug rough.c -lm
rough.c: In function ‘main’:
rough.c:6:5: warning: ‘str’ is used uninitialized [-Wuninitialized]
    6 |     printf("Length of string %lu\n", strlen(str));
      |     ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
In file included from rough.c:3:
/usr/include/string.h:407:15: note: by argument 1 of type ‘const char *’ to ‘strlen’ declared here
  407 | extern size_t strlen (const char *__s)
      |               ^~~~~~

## The program
~/c-programming/programming_concepts/strings$ cat rough.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    char *str = (char *)malloc(20 * sizeof(char));
    printf("Length of string %lu\n", strlen(str));

    return 0;
}
```
The warning you're encountering:

```
‘str’ is used uninitialized [-Wuninitialized]
```
indicates that you are trying to use the variable `str` without initializing the memory it points to.

### **Understanding the Issue:**
- **`malloc()` allocates memory**: It reserves space in the heap but does **not initialize** the memory. This means the contents of the allocated memory are **undefined**.
- **`strlen(str)`**: This function calculates the length of a string by counting characters until it encounters a null terminator (`'\0'`). If `str` is not initialized, `strlen` will access **garbage values**, which can cause undefined behavior or even segmentation faults.

### **Solution:**
You need to **initialize** the allocated memory or assign a valid string to `str` before using `strlen`.

### **Explanation:**
1. **Check for `NULL`**: Always check if `malloc` returns `NULL` to handle memory allocation failures gracefully.
2. **Initialize the string**: Use functions like `strcpy()` or `memset()` to set the contents of the allocated memory.
3. **Avoid using uninitialized values**: Accessing uninitialized memory leads to unpredictable results, which is why you received the warning.

### **Alternative Initialization Methods:**
If you want to initialize the memory to all zeros (null characters):
```c
memset(str, 0, 20);  // Set all 20 bytes to '\0'
```
### **Why This Matters:**
- **Undefined behavior**: Reading from uninitialized memory can cause your program to behave unpredictably or crash.
- **Security risk**: Uninitialized memory might contain sensitive data, leading to potential leaks or vulnerabilities.
Great question! Let's break down the behavior of **`malloc`** and **`calloc`** in C, how they work, and why `calloc` might seem to behave differently when it comes to storage and initialization.

---

#### **`malloc()` vs. `calloc()`**

### **Key Differences:**

| Aspect                | `malloc()`                            | `calloc()`                             |
|-----------------------|---------------------------------------|----------------------------------------|
| **Initialization**     | Does **not initialize** the memory. Contains **garbage values**. | Initializes memory to **zero**.        |
| **Syntax**             | `malloc(size_in_bytes)`               | `calloc(number_of_elements, size_of_each_element)`  |
| **Use Case**           | Use when you don’t need zero-initialized memory. | Use when you need zero-initialized memory (e.g., arrays). |
| **Performance**        | Faster because it doesn’t initialize memory. | Slightly slower because it initializes memory to zero. |

---

### **How Storage Works Internally:**

#### **Heap Memory:**
- Both `malloc()` and `calloc()` allocate memory from the **heap**.
- The heap is a **region of memory** used for dynamic allocation, separate from the stack (used for local variables).
- **When you allocate memory**:
  - The system reserves space in the heap.
  - The **pointer** returned by `malloc()` or `calloc()` points to the first byte of this allocated block.

### **`calloc` and String Length:**
If you use `calloc()` and check the length of the allocated block with functions like `strlen()`, it might return `0` because the block is initialized with **null characters (`'\0'`)**:
```c
char *str = (char *)calloc(20, sizeof(char));  // All 20 bytes are set to '\0'
printf("%lu\n", strlen(str));  // Output: 0
```
- **`strlen` stops at the first `'\0'` character**, so it sees the string as empty.

## Error 15: Segementation fault - during allocation of dynamic memory and string literal
```bash
# Error:
Breakpoint 1, main () at rough.c:5
5           char *str = (char *)malloc(40 * sizeof(char));
(gdb) n
6           str = "found the needle at position";
(gdb) p str
$1 = 0x5555555592a0 ""
(gdb) n
7           printf("Length of string %lu & value of string : %s\n", strlen(str), str);
(gdb) n
Length of string 28 & value of string : found the needle at position
8           strcat(str, " 5");
(gdb) s

Program received signal SIGSEGV, Segmentation fault.
0x00005555555551e7 in main () at rough.c:8
8           strcat(str, " 5");
(gdb) qy
Undefined command: "qy".  Try "help".
(gdb) q
A debugging session is active.

        Inferior 1 [process 21959] will be killed.

Quit anyway? (y or n) y
mpunix@LIN-5CG3350MRD:~/c-programming/programming_concepts/strings$ cat rough.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    char *str = (char *)malloc(40 * sizeof(char));
    str = "found the needle at position";
    printf("Length of string %lu & value of string : %s\n", strlen(str), str);
    strcat(str, " 5");
    printf("Length of string %lu & value of string : %s\n", strlen(str), str);
    str[31] = '\0';
    return 0;
}
```
#### Understanding the Segmentation Fault

In this code, the segmentation fault occurs because you're trying to modify a **string literal**, which is read-only. Let's analyze this step by step:

1. **Memory Allocation:**
   ```c
   char *str = (char *)malloc(40 * sizeof(char));
   ```
   - This allocates 40 bytes of memory on the heap, but the pointer `str` is **reassigned** later, causing a **memory leak** and losing the reference to this allocated memory.

2. **String Assignment:**
   ```c
   str = "found the needle at position";
   ```
   - Here, `str` no longer points to the allocated heap memory. Instead, it points to a **string literal** stored in a read-only section of memory.
   - String literals like `"found the needle at position"` are immutable in C. Attempting to modify them leads to **undefined behavior**.

3. **Segmentation Fault with `strcat`:**
   ```c
   strcat(str, " 5");
   ```
   - `strcat` tries to append `" 5"` to the string pointed to by `str`.
   - However, since `str` now points to a **read-only string literal**, attempting to write to this memory causes a **segmentation fault**.

To avoid this issue, you should copy the string literal into the allocated memory instead of reassigning the pointer:

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char *str = (char *)malloc(40 * sizeof(char));  // Allocate 40 bytes
    if (str == NULL) {  // Always check if malloc succeeded
        perror("Memory allocation failed");
        return 1;
    }
    
    strcpy(str, "found the needle at position");  // Copy string into allocated memory

    printf("Length of string %lu & value of string : %s\n", strlen(str), str);

    strcat(str, " 5");  // Safe to append now because we have allocated enough space
    printf("Length of string %lu & value of string : %s\n", strlen(str), str);

    free(str);  // Free the allocated memory
    return 0;
}
```
#### **Summary:**
- **String literals are read-only:** Modifying them results in a segmentation fault.
- **Always allocate and initialize writable memory** when dealing with strings that need to be modified.
- **Reassigning pointers loses allocated memory references:** Be careful to avoid memory leaks.

## Error 16: Do not compare const char pointers to string literals :
```bash
solution.c:2:15: warning: result of comparison against a string literal is unspecified (use strncmp instead) [-Wstring-compare]
  if(operator == "add")
              ^  ~~~~~
```
The warning you're seeing occurs because you're trying to compare a string pointer with a string literal directly. In C, string literals are arrays of characters, and when used in expressions, they decay to pointers. Comparing pointers like this doesn't check the content of the strings; instead, it checks if they point to the same memory address, which is not what you usually want.

### Problematic code:
```c
char *operator = "add";

if (operator == "add") {  // This compares pointers, not content
    // ...
}
```

### Solution: Use `strcmp()` or `strncmp()`
To compare the **contents** of strings in C, you need to use the `strcmp()` or `strncmp()` functions from the `<string.h>` library. Here's how to correct your code:

```c
#include <stdio.h>
#include <string.h>

int main() {
    char *operator = "add";

    if (strcmp(operator, "add") == 0) {  // Compare string content
        printf("Addition operation selected.\n");
    } else if (strcmp(operator, "subtract") == 0) {
        printf("Subtraction operation selected.\n");
    } else {
        printf("Unknown operation.\n");
    }

    return 0;
}
```

### Explanation:
- **`strcmp()`**: Compares two strings lexicographically. It returns:
  - `0` if the strings are equal.
  - A positive value if the first string is lexicographically greater.
  - A negative value if the first string is lexicographically smaller.
  
- **`strncmp()`**: Similar to `strcmp()`, but only compares the first `n` characters of each string. This is useful when you want to limit the comparison length to avoid potential buffer overflows or handle fixed-length strings.

```c
if (strncmp(operator, "add", 3) == 0) {
    // Matches "add"
}
```

### Why pointer comparison doesn't work:
When you write `operator == "add"`, you're comparing the **memory addresses** of the `operator` pointer and the `"add"` literal. Since these are typically stored in different locations in memory, the comparison usually fails even if the contents are the same.

## Error 17: Incorrect usage of pointer arithmetic in strings

- During string manipulation in C, do not return the incremented string.
- Be aware of when and what the target and source string are being assigned and manipulated.
```bash
char *copy_string(const char *str_in, char *ns) {
    while (*str_in) {
        *ns = *str_in;  // Copy character
        str_in++;
        ns++;           // Increment pointer
    }
    return ns; #### ERROR >>>>> Returning an incremented pointer! this will point to NULL
}
```
- assign the start address of ns to `char *start` which will hold the start address.
