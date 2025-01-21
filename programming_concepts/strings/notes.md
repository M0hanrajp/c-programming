### Strings

### Mini index
- This file has short notes, questions and answers.
- [scenarios.md](https://github.com/M0hanrajp/c-programming/blob/master/programming_concepts/strings/scenarios.md) has notes on string basics, pointers and passing values to a function.
- [Basics on 1D string pointers](https://github.com/M0hanrajp/c-programming/blob/master/programming_concepts/strings/notes.md#basics-of-declaration) how char pointers and char arrays differ.
- [Behavior.md](https://github.com/M0hanrajp/c-programming/blob/master/programming_concepts/strings/Behavior.md) contains all the errors for string programs.
- [Constant pointer vs pointer to a constant](https://github.com/M0hanrajp/c-programming/blob/master/programming_concepts/strings/two_dimensional_strings/constant_pointers_%26_Pointer_to_constant.c) explanation of a concepts.

### Observations & notes:
- Basics on string declarations can be found [here](https://github.com/M0hanrajp/c-programming/blob/master/programming_concepts/strings/notes.md#basics-of-declaration).
- strings are character arrays, a character literal in c behaves like an int.
- char a[4] variable behaves as pointer to the first element `(char *)`, &a gives of type `char (*)[4]` which is a pointer to whole array.
- In order to print a string (manually by iterating through each character)
    - Use '\0' character as the exit expression.
    - when iterating with i as an integer from 0 till `\0` make sure expression checks the character not the integer.
        - i.e. check `variable[iteration n] != '\0'` not `iteration n' != '\0'` inside the loop.
        - in ascii `\0` (The null terminator) character value is 0.

**Key Differences**

| **Aspect**             | **`input[i] != '\0'`**                           | **`i != '\0'`**                     |
|-------------------------|--------------------------------------------------|--------------------------------------|
| **Context**            | Character array/string traversal                 | Numeric comparison                  |
| **Checks**             | If the current character is not the null terminator (`'\0'`) | If the integer `i` is not zero       |
| **Use Case**           | Iterating or processing strings                  | General numeric conditions           |
| **Outcome**            | Relates to the data in `input`                   | Relates to the value of `i`          |

- While using strcat, size of target string should be the total amount of characters in both soruce and target strings.
- You can pass a char * to a function that expects a const char *, const char * means that the function promises not to modify the data that the pointer points to, When you pass a char * to such a function, the function treats the data as read-only, ensuring it won't change the content.
    - You cannot pass a const char * to a function expecting a char * without a cast. This is because it could lead to attempts to modify read-only data, which would violate the const promise.
- In GDB you can use `p strlen(variable) to check the size of the variable.
```bash
Breakpoint 1, main () at problem_e.c:8
warning: Source file is more recent than executable.
8           printFibonacci("a", "b", 5);
(gdb) s
printFibonacci (f0=0x555555556006 "a", f1=0x555555556004 "b", order=5) at problem_e.c:12
12      void printFibonacci(const char *f0, char *f1, int order) {
(gdb) p strlen(f1)
$1 = 1
(gdb) p strlen(f0)
$2 = 1
```
#### Basics of declaration:
- `char b[2] = "A"` vs `char *c = "A"` difference.
```bash
3	  char *c = "A"; // this act as a pointer to a constant string, Read only memory
4	  char b[2] = "A"; // this act as a constant pointer to string
```
![Image](https://github.com/user-attachments/assets/09a253f0-36bf-40c8-acde-458f6e769973)

- Printing a string that is not null terminated, printf is used to print b, it outputs "BAC".
- It's important to print a string with null terminated or behavior is undefined.
```bash
3	  char c[3] = "AC";
4	  char b[1] = "B"; # not a null terminated string
```
![Image](https://github.com/user-attachments/assets/51244874-45a8-4212-a9f9-ae4fd24ae945)

- Printing a string (non null terminated) and a string with overflowing characters:
```bash
3	  char c[3] = "ACDE";
4	  char b[1] = "B";
5	  printf("%s\n", b);
```
- Note the 'E' character in c[3] is not printed as it's out of bound, only "BACD" is printed.
- B is not null terminated hence next in the memory address we can see the character is A.
- Hence since size of c is 3 bytes printf prints till D.
![Image](https://github.com/user-attachments/assets/401aac3f-a3e9-4832-bc00-588365c2cab3)

- Declaring a pointer and not initializing it will result in `seg faults`.examples in [file](https://github.com/M0hanrajp/c-programming/blob/9dd2438e7e52471e7c525dcffc1f5e3a6f0b6ae5/misc_notes/dynamic_memory_allocation.md?plain=1#L33), [file](https://github.com/M0hanrajp/c-programming/blob/9dd2438e7e52471e7c525dcffc1f5e3a6f0b6ae5/programming_concepts/strings/Behavior.md?plain=1#L352), [file](https://github.com/M0hanrajp/c-programming/blob/9dd2438e7e52471e7c525dcffc1f5e3a6f0b6ae5/compilation_process/theory.md?plain=1#L71)
```bash
programming_concepts/strings/snippets/d.c has the program
```
- Calculation of pointer to an array in 1D array `VIMP` [Calculation of pointer to an array in 1D i.e. `char a[21]` used as `char (*)[21]`](https://github.com/M0hanrajp/c-programming/blob/master/programming_concepts/strings/two_dimensional_strings/output.md#passing-stro-to-functions)

### 2D array Notes


### Questions

- [a] char words[] = {'A', 'B', 'C', 'D', '\0'};, when printed by calling the function mentioned in basics_main.c prints ABCD.
    - when the same words[] is used without '\0' it prints ABCD, what is the behavior here ? does compiler add the '\0' terminator ?
- [b] Working of `printf()` function ?
- [Q & Ans](https://github.com/M0hanrajp/c-programming/blob/master/programming_concepts/strings/notes.md#ans-c)[c] When a char[20] is declared and is initialized with string length less than 25 bytes, what is the value in the left out memory locations ?
- [How does `*t++ and *++t` works](https://github.com/M0hanrajp/c-programming/blob/master/programming_concepts/strings/snippets/d.c)
- [Proof that character literal is of type int in C](https://github.com/M0hanrajp/c-programming/blob/master/programming_concepts/strings/snippets/h.c)
- [How size is determined for declaration of type `word[] = "string"` ?](https://github.com/M0hanrajp/c-programming/blob/master/programming_concepts/strings/notes.md#how-size-is-determined-for-declaration-of-type-word--string-)
- [Calculation of pointer to an array in 1D i.e. `char a[21]` used as `char (*)[21]`](https://github.com/M0hanrajp/c-programming/blob/master/programming_concepts/strings/two_dimensional_strings/output.md#passing-stro-to-functions)

### Answers:

### ans-c
- prints out garbage value and nulls.
- Accessing out-of-bound indices results in undefined behavior. 
- The program reads whatever data happens to be in the memory addresses following the str array.
```bash
  char str[19] = "the_stealth_warrior";
  for(int i = 0; i < 30; i++) {
    printf("Char[%2d] = %2c & address :: %p\n", i, str[i], &str[i]);
  }
########## Output::
Char[ 0] =  t & address :: 0x7ffc4a8cea30
Char[ 1] =  h & address :: 0x7ffc4a8cea31
Char[ 2] =  e & address :: 0x7ffc4a8cea32
Char[ 3] =  _ & address :: 0x7ffc4a8cea33
Char[ 4] =  s & address :: 0x7ffc4a8cea34
Char[ 5] =  t & address :: 0x7ffc4a8cea35
Char[ 6] =  e & address :: 0x7ffc4a8cea36
Char[ 7] =  a & address :: 0x7ffc4a8cea37
Char[ 8] =  l & address :: 0x7ffc4a8cea38
Char[ 9] =  t & address :: 0x7ffc4a8cea39
Char[10] =  h & address :: 0x7ffc4a8cea3a
Char[11] =  _ & address :: 0x7ffc4a8cea3b
Char[12] =  w & address :: 0x7ffc4a8cea3c
Char[13] =  a & address :: 0x7ffc4a8cea3d
Char[14] =  r & address :: 0x7ffc4a8cea3e
Char[15] =  r & address :: 0x7ffc4a8cea3f
Char[16] =  i & address :: 0x7ffc4a8cea40
Char[17] =  o & address :: 0x7ffc4a8cea41
Char[18] =  r & address :: 0x7ffc4a8cea42
Char[19] =    & address :: 0x7ffc4a8cea43 # NULL, size ends here
Char[20] =    & address :: 0x7ffc4a8cea44
Char[21] =    & address :: 0x7ffc4a8cea45
Char[22] =    & address :: 0x7ffc4a8cea46
Char[23] =    & address :: 0x7ffc4a8cea47
Char[24] =    & address :: 0x7ffc4a8cea48
Char[25] =    & address :: 0x7ffc4a8cea49
Char[26] =  ] & address :: 0x7ffc4a8cea4a # Random characters
Char[27] =  � & address :: 0x7ffc4a8cea4b
Char[28] =  � & address :: 0x7ffc4a8cea4c
Char[29] =  � & address :: 0x7ffc4a8cea4d
```

### How size is determined for declaration of type `word[] = "string"` ?

When we say that `word[]` is a **statically allocated array** in C, it means that its memory is allocated at **compile time** in a fixed location. Let's break this down step by step:
#### **1. Statically Allocated Memory**
- **Definition**: Statically allocated memory is memory whose size is determined at compile time and cannot be changed during the program's execution.
- **Characteristics**:
  - The memory for the array is reserved in the stack (or data segment, for global/static variables).
  - The size of the array must be known at compile time.
  - The memory is automatically managed and is freed when the variable goes out of scope (or the program terminates for global/static arrays).

For example:
```c
char word[] = "something";
```
Size of `word[]` is determined **at compile time**, and the initializer is used to calculate its size. Here's why and how it works:
- During compile time, the compiler counts the characters in the string literal using a simple string parsing process.
- The total size is calculated as the number of characters encountered between the quotes plus one for the null terminator `(\0)`.
Here:
- Memory for `word` is statically allocated to hold 10 bytes (`'s'`, `'o'`, ..., `'g'`, `\0`).
- This memory is allocated on the stack if `word` is a local variable or in the data segment if it’s global.

#### **2. Behavior of Statically Allocated Arrays**
- The array `word[]` is **fixed in size**:
  - The size is determined by the initializer (`"something"`), or explicitly if you specify it.
  - You cannot resize it or reassign it to point to another block of memory.
  ```c
  word = "another";  // Error: Assignment to expression with array type
  ```
- However, you can modify the contents of the array:
  ```c
  word[0] = 'S';  // This is valid
  ```
#### **3. Difference from Dynamic Memory Allocation**
- **Static Allocation (`word[]`)**:
  - Memory size is determined at compile time.
  - The size cannot change.
  - Automatically deallocated when the variable goes out of scope.

- **Dynamic Allocation (`malloc`)**:
  - Memory is allocated at runtime.
  - The size can be specified dynamically and changed (e.g., using `realloc`).
  - The programmer is responsible for managing the memory (`free` it after use).

#### **5. Advantages of Static Allocation**
- **Fast**: The memory is allocated on the stack or data segment, which is faster to access than dynamically allocated memory (heap).
- **Simple**: The compiler manages the memory lifecycle.
- **Safer**: No need to worry about memory leaks or dangling pointers.

#### **6. Disadvantages of Static Allocation**
- **Fixed Size**: You cannot resize the array once it is allocated.
- **Memory Waste**: If you over-allocate space, the unused memory is wasted.
- **Scope Limited**: Local arrays are destroyed when the function they belong to exits.

#### **1. Why Does the Compiler Need to Know the Size?**
In C, when you declare an array, the compiler needs to reserve enough memory for it. Without explicitly specifying the size, the compiler uses the initializer to determine how much memory to allocate. This allocation happens at **compile time**.

Example:
```c
char word[] = "something";
```
- The string `"something"` has 9 characters, including the null terminator (`\0`).
- The compiler calculates the size of `word[]` as `9` and allocates exactly `9 bytes` of memory.

#### **Why Size Calculation is Necessary:**
1. **Memory Reservation**:
   - The compiler must know the exact amount of memory to allocate for the array.
   - Without this information, the program wouldn't know how much space to reserve on the stack (for local arrays) or in the data segment (for global arrays).

2. **Array Indexing**:
   - Arrays in C rely on their size for bounds checking (informally, since C doesn't enforce bounds at runtime). Knowing the size at compile time ensures the program can handle the array properly.

#### **2. Why Not Use Just the Null Terminator?**
The null terminator (`\0`) is not sufficient to determine the size of the array because:
- The null terminator is **part of the string** and does not give the total size of the array.
- C treats arrays as fixed-size blocks of memory, so the compiler needs to know the full size in advance to manage memory and perform operations like indexing.

if you are declaring `char[]` without any initialization.
```bash
rough.c:4:8: error: array size missing in ‘word’
    4 |   char word[];
      |        ^~~~
```
The compiler needs to know the size of an array to:
- Allocate the correct amount of memory for it.
- Enable safe and valid indexing of the array elements.
- Prevent memory corruption and undefined behavior.
- Optimize memory and runtime performance.
