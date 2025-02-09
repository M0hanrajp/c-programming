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
$1 = 1 # strlen will always print the length of the string + NULL character.
       # Need to be alert when traversing array becuase arrays are 0 index based.
       # Because when reversing an array the strlen will return position of NULL character
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

`*c` is treated as integer, as *c dereferences to a char, char literal is treated as int in c.
![Image](https://github.com/user-attachments/assets/cee8c05e-dc68-417d-8701-d272b09f564a)

Notice `*c` still points to D, as it's present at address 0x4005e4. you can see the difference in the next picture.
![Image](https://github.com/user-attachments/assets/dd7dc3fa-68e6-42d2-89f9-4c729908d92d)

c is a mutable pointer, when c++ is performed it points to the next address.
![Image](https://github.com/user-attachments/assets/8c2afc01-751c-4fe0-bd14-b11ba7b91a08)

when c points to NULL. "Note: behavior is undefined when c points to out of bound address".
![Image](https://github.com/user-attachments/assets/1f47fe6f-694a-42ff-bfa6-ef51adde5e68)

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

```bash
    char strT[2][4] = {"Bit", "Git"};
```
![Image](https://github.com/user-attachments/assets/5ee11ab1-9ca0-48c3-ba61-7b2b205c853c)
- First subscript [2] gives the number of strings in the array.
- Second subscript [4] gives the length of each string in the array.
- size of the array can be caluclated by 2 * 4 = 8 bytes.
- What happens if you declare `char [2][6]` and initialize it to `{"Bit", "Git"}`.
- string `Bit` occupies 3 bytes only and rest memory locations left are initialized with `'\0'`;
- this leaves us wastage with 2 bytes for each string, 4 bytes of wastage in total.
  - Note: how to declare 2D strings in an efficient manner is discussed further below.
![Image](https://github.com/user-attachments/assets/525266bd-b062-42e6-b981-6e578669d1c5)
- Basic way of passing arr to a function that can access 2D char array.
  - Notice the void_display function indicates arr is of type pointer to char[4].
    - Most basic way to print out 2D char array is to declare function argument as `arr[size][size]` type.
![Image](https://github.com/user-attachments/assets/39dcd777-3820-4ef1-92b9-395693f94fed)
- Remember that `char [2][4]` when declared in main, it decays to `char (*)[4]` a pointer to first row when passing to a function.
[arr decays into a pointer to the first row (each row is an array of 4 characters).](https://github.com/M0hanrajp/c-programming/blob/9dc137f42ddd125c1378418e74411ec3a668c2e5/misc_notes/oneDimensional_twoDimensional_array_decay.md?plain=1#L93)
```bash
# 2D array, the arrays has decayed to char (*)[4] type 
 In function 'main':
14:11: warning: passing argument 1 of 'display' from incompatible pointer type [-Wincompatible-pointer-types]
   14 |   display(arr);
      |           ^~~
      |           |
      |           char (*)[4]
# The function argument is not proper
3:21: note: expected 'char **' but argument is of type 'char (*)[4]'
    3 | void display(char** arr) {
      |              ~~~~~~~^~~
 ```
- so in order to pass str to a function, the function argument must be of type `char (*)[size]` to accept array from main.
- [a] More detailed info is presented in (/two_dimensional_strings/output.md)
- A summary of [a], In main:
  - &arr: Address of the 2D array in memory.
  - arr: Pointer to the first row of the array (char (*)[4]).
  - *arr: Pointer to the first element of the first row (char *).
  - arr[1]: Pointer to the first element of the second row.
In display:
  - &arr: Address of the local pointer variable in the function's stack frame. (this address only will be different)
  - arr: Pointer to the first row of the 2D array (same as in main).
  - *arr: Pointer to the first element of the first row (same as in main).
  - arr[1]: Pointer to the first element of the second row (same as in main).
![Image](https://github.com/user-attachments/assets/a03ef831-80e5-4f3b-8244-04e857d4383c)
- Being aware that a 2D array decays to `char (*)[size]` type,
  - It's important to know that size should be the 2nd subscript of the declared array.
    - if `char [2][4]` is the array declared in main, then size should be 4, else pointer arithmetic could go wrong.
- After knowing the type of char and it's properties learn the calculation [here](https://github.com/M0hanrajp/c-programming/blob/master/programming_concepts/strings/two_dimensional_strings/output.md#understanding-2d-array-pointer-arithmetic-passing-to-function-etc)
- The following program is valid for receiving strings from `stdin`
```c
char strings[10][20];
// char strings[10][20] = {0}; // Sets all elements to '\0'
for(int i = 0; i < 10; i++) {
  printf("Enter the name:");
  scanf("%s", strings[i]);
}
```
- the program is valid because:
  - `strings[10][20]` reserves 200 bytes of space in memory.
  - the declaration states 10 strings can be stored of the size 20 bytes each.
  - Since strings is an uninitialized local array, it contains garbage values until explicitly assigned.
  - Only static/global arrays are zero-initialized (i.e., all elements set to \0).
  - the elements are mutable in the above declaration.
  - Based on the above method it does not workout for array of pointers check below.

### Array of pointers.
```bash
char *<array_name>[size] = { <element_1: pointer to char>, <element_2: pointer to char> };
     ^
     |---- should be written without brackets.
```
- Provided above is basic declaration of array of pointers.
  - Meaning the array we learnt before had elements of type char, int but now array has base address (pointer to a `type`) as it's elements.
  ```bash
  char *name[2] = {"Ram", "Sita"};
                     |-------|-----------> "Ram" at address 80
                             |-----------> "Sita" at address 88 # Pointer size is considered as 8 bytes.
  ```
- For example:
![Image](https://github.com/user-attachments/assets/31858d24-49b3-4613-8b42-39831ce38b82)
- In detailed memory layout is discussed in output.md 
- the type of <array_name> is `char *[3]` which is array of pointers.
- <array_name> when being passed to a function or used in the expression decays to type `char **`.
- using sizeof(<array_name>) gives the total size of pointers present in the array.
  - if you store 4 strings in an array then total size reported will be 4 elements * sizeof(pointer).
- `char *str[]`, str++ is not allowed, str is an array name, it is a constant pointer and cannot be modified.
  - str + 1 is allowed as it turns into an expression, you are not modifying str. more on this in output.md (difference between `char *[3]` and `char(*)[3]`)
- From the output.md, please note as per C spec 6.3.2.1, <array_name> is of type `char *[3]`. if it is used in expression then it decays to `char **`.
- `&<array_name>` will give `char *(*)[3]`, pointer to an array of pointers.
- <array_name> is an array of pointers to char, meaning each element str[i] is a pointer to a string literal.
- x. Use `<array_name> + 1` as an expression to move by 8 bytes i.e. the next address of type `char **` that contains `char *` element.
```bash
# For example <array_name> + 1 moves you to the next address
$3 = (char **) 0x7fffffffdf20
(gdb) p str + 1
$4 = (char **) 0x7fffffffdf28 # ---> f20 + 8 = f28
(gdb) p str + 2
$5 = (char **) 0x7fffffffdf30 # ---> f28 + 8 = f30 
# (28 in hex -> 2 * 16 ^ 1 + 8 * 16 ^ 0. -> 48 in dec -> 30 in hex
```
>arrays do not decay at non-zero indices.
- from above x, you are able to get address which are the elements of array of pointers.
- In order to get the pointers that are pointing to strings that are held by the addresses
  - `*(<array_name> + 1)` by doing this you get the address points to the string.
```bash
# Formula == (base address of str) + (1 * size of (char *))
(gdb) p *(str + 0) # in other words str[0]
$7 = 0x555555556008 "Welcome"
#  str + 1 = str + (0 * 8) = 0x7fffffffdf20 +  0 = 0x7fffffffdf20 ---> *0x7fffffffdf20 ---> 0x555555556008
```
- When you are able to access the strings how can we access individual elements ?
```bash
# Continuing from the above equations.
(gdb) whatis *(str + 0)
type = char *
# 2. *(0x555555556008) ---> 'W' (because *(0x7fffffffdf20) + 0 = 0x7fffffffdf20)"
(gdb) p *(*(str + 0) + 0)
$18 = 87 'W'
(gdb) printf"%p\n", (*(str + 0) + 0)
0x555555556008
```
- `char *[3]` is an array of pointers and `char (*)[3]` pointer to an array.
- str is not a pointer variable; it's an array name, which acts as a constant pointer to str[0].
- Trying to increment str (str++) is like trying to modify a constant pointer, which is not allowed.
- Note: str + 1 is allowed because it computes a new address without modifying str.
- `char *[3]` decays into `char **` while passing to a function.
  - The function argument might be written as:
```bash
void <func-name>(char **<var_name>);
# OR
void <func-name>(char *<var_name>[]);
```
- In order to get the number of pointers present in the array of pointers there are multiple ways:
  - a. declare the size in function argument and pass it. i.e. `void <func-name>(char **<var_name>, unsigned size)`;
    - where size will be passed a unsigned int from main.
  - b. When initializing array of pointers in main (can be anywhere based on situation).
    - declare it `char *str[] = {"Welcome", "to", "jumanji", NULL};`
    - Keep the function argument `void <func-name>(char **<var_name>)`
    - Inside the function, `str[i] != NULL` must be the condition so increments only till the last string.
    - The char elements in str are not mutable because element at str[0] is char *, the string is stored in read only memory.
    - If the char elements need to be modified if memory is allocated from heap or assigned address is constant pointer to a string. i.e. char[3] = "AAA";
      - More information on heap allocated strings that are modified [here](https://github.com/M0hanrajp/c-programming/blob/master/programming_concepts/strings/two_dimensional_strings/array_of_pointers_to_strings.c)
- In order to calculate the amount of bytes occupied by the strings, write a custom function that takes advantage of `strlen` input, and gives the total amount of memory occupied by strings.
- all arrays in C, 1D or 2D they decay as pointer to first element.
- Can we receive input from `stdin` for array of pointers ?
```c
  char *temp[20];
  for(int i = 0; i < 5; i++) {
    printf("Enter the name:");
    scanf("%s", temp[i]);
  }
```
- How does the program behave ?
  - temp is an array of pointers (elements are `char *` type), when we declare the statement.
    - there is no memory allocated, `char *temp[20]` means, temp is an array of pointers that can hold 20 char * elements.
    - but the elements have not been assigned a valid memory space when `temp` is declared.
    - Running the program takes is an undefined behavior, will declare segementation fault.
    ```bash
    $ ./a.out
    Enter the name:Ram
    Segmentation fault (core dumped)
    ```
- The current way to get input for array of pointers:
```c
  char *temp[20];
  for(int i = 0; i < 5; i++) {
    temp[i] = (char *)calloc(20, sizeof(char));
    printf("Enter the name:");
    scanf("%s", temp[i]);
  }
```
- Here for each element we are initialzing it with an address and memory of 20 bytes.
- this is capable of holiding strings of size 20 (with NULL character).
```bash
$ ./a.out
Enter the name:Ram
Enter the name:Ramesh
Enter the name:a
Enter the name:b
Enter the name:c
Ramesh
```

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
and all arrays with declaration arr[5], arr[], memory is allocated at compile time.

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

#### **2. Why Not Use Just the Null Terminator? (compiler POV)**
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
