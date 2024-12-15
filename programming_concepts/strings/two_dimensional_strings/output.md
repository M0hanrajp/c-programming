### contains output of the programs in the folder

```bash
mpunix@LIN-5CG3350MRD:~/c-programming/programming_concepts/strings/two_dimensional_strings$ ./basics
size of 1D strO :: 20
// &strO: Pointer to the entire array (char (*)[20]
address of variable strO :: 0x7ffe08b41620
// strO or &strO[0]: Pointer to the first element of the array (char*)
address of variable strO :: 0x7fff5f53a570 (pointer to whole array)
size of &StrO :: 8
# The function accepts char* so we can use pointer arithmetic to print out string.
Element[ 0] = I & address :: 0x7ffe08b41620 # this is entire arrays address
Element[ 1] =   & address :: 0x7ffe08b41621
Element[ 2] = u & address :: 0x7ffe08b41622
Element[ 3] = s & address :: 0x7ffe08b41623
Element[ 4] = e & address :: 0x7ffe08b41624
Element[ 5] =   & address :: 0x7ffe08b41625
Element[ 6] = A & address :: 0x7ffe08b41626
Element[ 7] = r & address :: 0x7ffe08b41627
Element[ 8] = c & address :: 0x7ffe08b41628
Element[ 9] = h & address :: 0x7ffe08b41629
Element[10] =   & address :: 0x7ffe08b4162a
Element[11] = l & address :: 0x7ffe08b4162b
Element[12] = i & address :: 0x7ffe08b4162c
Element[13] = n & address :: 0x7ffe08b4162d
Element[14] = u & address :: 0x7ffe08b4162e
Element[15] = x & address :: 0x7ffe08b4162f
Element[16] =   & address :: 0x7ffe08b41630
Element[17] = B & address :: 0x7ffe08b41631
Element[18] = T & address :: 0x7ffe08b41632
Element[19] = W & address :: 0x7ffe08b41633
Using print function :: I use Arch linux BTW
```
Yes, `&strO` points to the **entire array**, whereas `strO` is a pointer to the **first element** of the array. Let's dive deeper into their differences and how to use `&strO`.

### **Difference Between `strO` and `&strO`:**

#### 1. **`strO`:**
   - When used, it **decays** into a pointer to the first element of the array (`char*`).
   - Its type is `char*`.
   - It can be used for element access, pointer arithmetic, and passing to functions expecting a pointer.

#### 2. **`&strO`:**
   - It is the address of the **entire array**.
   - Its type is `char (*)[20]` (a pointer to an array of 20 `char`s).
   - It cannot be directly used for pointer arithmetic or element access because it refers to the whole array as a single unit.

Here:
- `(*arrayPointer)` dereferences the pointer to the entire array.
- `(*arrayPointer)[0]` accesses the first element.

#### **Passing `&strO` to Functions**:
If you pass `&strO` to a function, the parameter must be declared to accept a pointer to an array:
```c
void displayArrayPointer(char (*array)[20]) {
    printf("First element: %c\n", (*array)[0]);
    printf("Second element: %c\n", (*array)[1]);
}
```
---

### **Key Differences in Practical Use**:

| Aspect                  | `strO` (decays into `char*`)        | `&strO` (decays into `char (*)[20]`) |
|-------------------------|-------------------------------------|--------------------------------------|
| **Type**                | Pointer to `char` (`char*`)         | Pointer to array (`char (*)[20]`) |
| **Represents**          | Address of the first element        | Address of the whole array      |
| **Pointer Arithmetic**  | Moves by `sizeof(char)` (1 byte)    | Moves by `sizeof(strO)` (20 bytes) |
| **Accessing Elements**  | Direct access (e.g., `strO[i]`)     | Need dereference (`(*&strO)[i]`) |
| **Function Passing**    | Passes as `char*`                   | Passes as `char (*)[20]`       |


### Understanding 2D array pointer arithmetic, passing to function etc.

#### Below is the incorrect method that was used to access.
#### can be used to understand pointer to arrays.

>Summary of the problem

The problem here was logical, using number of rows to print the 2D string, instead the function argument should
be of type char (*)[size] where size is the total length of string in the array.
Since 2 was passed (mistake) - the pointer arithmetic turned out to be wrong.

>Detailed summary

```bash
mpunix@LIN-5CG3350MRD:~/c-programming/programming_concepts/strings/two_dimensional_strings$ ./basics
sizeof 2D char array :: 8
address of 2D char array :: 0x7fff8714cea8 without & operator
address of variable &strT :: 0x7fff8714cea8 (pointer to whole array)
size of &StrO :: 8
Value :: one address of string 1 :: 0x7fff8714cea8
Value :: two address of string 2 :: 0x7fff8714ceac
Row 0 :: one & address :: 0x7fff8714cea8
Row 1 :: e & address :: 0x7fff8714ceaa # here only e character is printed.
mpunix@LIN-5CG3350MRD:~/c-programming/programming_concepts/strings/two_dimensional_strings$ cat basics.c
#include <stdio.h>
#include <stddef.h>
void displayTwoDimensionalString(size_t size, char (*input)[size]) {
    for(size_t i = 0; i < size; i++) {
        printf("Row %lu :: %s & address :: %p\n", i, input[i], input[i]);
    }
}
int main() {
    // Two dimensional array with basics
    char strT[2][4] = {"one", "two"};
    printf("sizeof 2D char array :: %lu\n", sizeof(strT));
    printf("address of 2D char array :: %p without & operator\n", strT);
    printf("address of variable &strT :: %p (pointer to whole array) \nsize of &StrO :: %lu\n", &strT, sizeof(&strT));

    // call the function ::
    printf("Value :: %s address of string 1 :: %p\n", strT[0], strT[0]);
    printf("Value :: %s address of string 2 :: %p\n", strT[1], strT[1]);

    # Here is the mistake, passing 2 instead of 4 which is the total length of each row
    # char strT[2][4] = {"one", "two"};
    #              ^- this number should be passed but 2 was passed.
    displayTwoDimensionalString(2, strT);
    return 0;
}
```
>Q:why Row 1 :: e & address :: 0x7fff8714ceaa pointer arithmetic is wrong here ?

Ans: strT refers to the base address of the 2D array (the address of strT[0]).
- the logic was to print strT[x] where x would be row.
   - meaning *(strT + x) will print the whole row at once.(because of how it's calculated)
   - why ? because since each row is x characters wide.
   - it moves `x * size * sizeof(char)` bytes because input is pointer to array of type char (*)[size].
   - whenever you increment or decrement it will move by `x * size * sizeof(char)` bytes. (move by each string)

But what went wrong ?

- what does the declaration `char (*input)[size])` mean ?
- the function argument `char (*input)[size])` means input is a pointer to an array of `size` characters.
   - here input is a pointer to array.
   - `[size]` specifies that the array has size number of elements of type char.
   - input points to the whole array of type char.

- How pointer arithmetic works here ?
   - The amount by which a pointer increments (input++) depends on the type of object the pointer points to.
   - If a pointer `points to char`, it increments by sizeof(char) = 1 byte.
   - If a pointer `points to int`, it increments by sizeof(int) (commonly 4 bytes).
   - If a pointer `points to an array of size number of characters`, it increments by the size of the whole array.
      - Meaning: input++ moves by `size * sizeof(char)` bytes.

calculation of pointer arithmetic of pointer to an array & debugging the mistake.
```bash
# base address ::
address of 2D char array :: 0x7fffffffe028 without & operator
address of variable &strT :: 0x7fffffffe028 (pointer to whole array)
# Row one and Row two
Value :: one address of string 1 :: 0x7fffffffe028
# there is a total difference of 4 bytes because 
# char strT[2][4] = {"one", "two"};, size of each row is 4 bytes.
Value :: two address of string 2 :: 0x7fffffffe02c
```
Entering function and debugging through GDB:
```bash
# Enter the funciton, input points to the base address 028 as seen above
(gdb) s
displayTwoDimensionalString (size=2, input=0x7fffffffe028) at basics.c:4
4       void displayTwoDimensionalString(size_t size, char (*input)[size]) {

(gdb) n
5           for(size_t i = 0; i < size; i++) {
(gdb) n
6               printf("Row %lu :: %s & address :: %p\n", i, input[i], input[i]);
(gdb) info locals
i = 0
(gdb) p input
$3 = (char (*)[variable length]) 0x7fffffffe028
# size is 2
(gdb) p size
$4 = 2
# when i is 0 the calculation will be 
# *(input + (0 * size * sizeof(char))) because it is input is of type (*)[size]
# since i is 0, *input will be resolved to base address it self i.e. 0x7fffffffe028
# hence it prints the following::
(gdb) n
Row 0 :: one & address :: 0x7fffffffe028
# next when i is 1
# *(input + (1 * size * sizeof(char)))
(gdb) info locals
i = 1
(gdb) p input 
(gdb) $7 = (char (*)[variable length]) 0x7fffffffe028
(gdb) p size
$4 = 2
# calculation will be *(028 + 2) (for understanding
# address will be 02a, because i = 1 & input is of type char (*)[2]
# Hence + 1 increment to the variable will move 2 bytes ahead.
# as seen below it matches the address hence only e is printed ::
(gdb) info locals
i = 1
(gdb) p input
$19 = (char (*)[variable length]) 0x7fffffffe028
(gdb) n
Row 1 :: e & address :: 0x7fffffffe02a
```
Expanded form: important
```bash
# Because input is of type char (*)[2] it points to address 2a
(gdb) p &*((char (*)[2])input + 1)
$22 = (char (*)[2]) 0x7fffffffe02a
```
>### The correct way of displaying 2D strings in char (*)[size] format.

- make sure size conveys the overall size allocated for each string inside the two dimensional array.
```bash
void displayTwoDimensionalString(size_t size, char (*input)[size]) {
if     char strT[2][4] = {"one", "two"};, 
# then size should be 4 so arithmetic will be *(input + (size * sizeof(char) * i))
```
**Calculating again::**
```bash
Value :: one address of string 1 :: 0x7fffffffe028
Value :: two address of string 2 :: 0x7fffffffe02c
# for i = 0, it prints base address 28
(gdb) p input
$1 = (char (*)[variable length]) 0x7fffffffe028
(gdb) n
6           for(size_t i = 0; i < 2; i++) {
i = 0
(gdb) n
Row 0 :: one & address :: 0x7fffffffe028
```
Proper calculation >
```bash
# for i = 1,
(gdb) p input
$2 = (char (*)[variable length]) 0x7fffffffe028
(gdb) p *((char (*)[4])input + i)
$3 = "two"
# base address 028, pointer of type char (*)[4] hence when + 1 is done it moves by 4
# 028 + 4 = 02c & prints the whole second string.
(gdb) p &*((char (*)[4])input + i)
$4 = (char (*)[4]) 0x7fffffffe02c
(gdb) n
Row 1 :: two & address :: 0x7fffffffe02c
```
