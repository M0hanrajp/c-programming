### contains output of the programs in the folder

Use [`whatis <variable>` in gdb to get to know the type](https://github.com/M0hanrajp/c-programming/blob/188035dbc5b7d9b6857aef5314238186831238b1/programming_concepts/function_pointers/notes.md?plain=1#L19)
- [How size is determined for declaration of type `word[] = "string"` ?](https://github.com/M0hanrajp/c-programming/blob/master/programming_concepts/strings/notes.md#how-size-is-determined-for-declaration-of-type-word--string-)

>### 1D array basics
```bash
mpunix@LIN-5CG3350MRD:~/c-programming/programming_concepts/strings/two_dimensional_strings$ ./basics
sizeof(strO) :: 21
address of strO (&strO):: 0x7ffc881b4b40 (pointer to whole array) i.e. of type char (*)[20]
sizeof address (&StrO) :: 8
str0 decays to a pointer to the first element with address strO:: 0x7ffc881b4b40 && value *strO:: I
Element[ 0] = I & address :: 0x7ffc881b4b40
Element[ 1] =   & address :: 0x7ffc881b4b41
Element[ 2] = u & address :: 0x7ffc881b4b42
Element[ 3] = s & address :: 0x7ffc881b4b43
Element[ 4] = e & address :: 0x7ffc881b4b44
Element[ 5] =   & address :: 0x7ffc881b4b45
Element[ 6] = A & address :: 0x7ffc881b4b46
Element[ 7] = r & address :: 0x7ffc881b4b47
Element[ 8] = c & address :: 0x7ffc881b4b48
Element[ 9] = h & address :: 0x7ffc881b4b49
Element[10] =   & address :: 0x7ffc881b4b4a
Element[11] = l & address :: 0x7ffc881b4b4b
Element[12] = i & address :: 0x7ffc881b4b4c
Element[13] = n & address :: 0x7ffc881b4b4d
Element[14] = u & address :: 0x7ffc881b4b4e
Element[15] = x & address :: 0x7ffc881b4b4f
Element[16] =   & address :: 0x7ffc881b4b50
Element[17] = B & address :: 0x7ffc881b4b51
Element[18] = T & address :: 0x7ffc881b4b52
Element[19] = W & address :: 0x7ffc881b4b53
Using print function :: I use Arch linux BTW
```
Yes, `&strO` points to the **entire array**, whereas `strO` is a pointer to the **first element** of the array. Let's dive deeper into their differences and how to use `&strO`.
![Image](https://github.com/user-attachments/assets/57636f13-8148-443e-a627-d8645d8af462)

### **Difference Between `strO` and `&strO`:**

#### 1. **`strO`:**
   - When used, it **decays** into a pointer to the first element of the array (`char*`).
   - Its type is `char*`.
   - It can be used for element access, pointer arithmetic, and passing to functions expecting a pointer.

#### 2. **`&strO`:**
   - It is the address of the **entire array**.
   - Its type is `char (*)[20]` (a pointer to an array of 20 `char`s).
   - It cannot be directly used for pointer arithmetic or element access because it refers to the whole array as a single unit.
      - It can be used but with more complexity. (Calculations are shown below).

Here: (the below two points are only if you are passing to a function argument that expects char (*)[x]
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
- here `&strO` is of type `char (*)[20]`, `strO` is a pointer to first element.
```bash
(gdb) printf"%p\n", *&strO
0x7fffffffdfb0
(gdb) printf"%p\n", strO
0x7fffffffdfb0
```
For example:
```bash
// dereferencing a char (*)[20], 
(gdb) p (*&strO)[0]
$2 = 73 'I'
```
- Calculation first element: `(*&strO)[0] --> (0x7fffffffdfb0)[0] --> *(0x7fffffffdfb0 + 0) --> 'I'`
```bash
(gdb) p (*&strO)[1]
$4 = 32 ' '
```
- Calculation second element: `(*&strO)[1] --> (0x7fffffffdfb0)[1] --> *(0x7fffffffdfb0 + 1) --> ' '`
```bash
1	#include <stdio.h>
2	
3	void_display(char (*arr)[4]) {
4	  for(int i = 0; (*arr)[i] != '\0'; i++)
5	    printf("%c", (*arr)[i]);
6	  printf("\n");
7	}
8	
9	int main() {
10	  char arr[4] = "Bit";
11	  void_display(&arr);
12	  return 0;
13	}
```
![Image](https://github.com/user-attachments/assets/9b0e53a2-9a3a-4441-b10c-7c9b843a7ac0)

---

### **Key Differences in Practical Use**:

| Aspect                  | `strO` (decays into `char*`)        | `&strO` (decays into `char (*)[20]`) |
|-------------------------|-------------------------------------|--------------------------------------|
| **Type**                | Pointer to `char` (`char*`)         | Pointer to array (`char (*)[20]`) |
| **Represents**          | Address of the first element        | Address of the whole array      |
| **Pointer Arithmetic**  | Moves by `sizeof(char)` (1 byte)    | Moves by `sizeof(strO)` (20 bytes) |
| **Accessing Elements**  | Direct access (e.g., `strO[i]`)     | Need dereference (`(*&strO)[i]`) |
| **Function Passing**    | Passes as `char*`                   | Passes as `char (*)[20]`       |

### 1D array calculations:

- when passing a string to function it decays as pointer to first element.
- since char arr[x] is declared, arr is of type char so arr++ moves arr by 1 byte.
- for accessing any element *(arr + i) which is same as arr[i].
```bash
displayOneDimensionalString (size=20, string=0x7fffffffe030 "I use Arch linux BTW") at basics.c:27
27          for(int i = 0; string[i] != '\0'; i++) {
# the following prints till it encounters the NULL char
(gdb) p string
$1 = 0x7fffffffe030 "I use Arch linux BTW"
(gdb) p string[i]
$3 = 73 'I'
# The whole 1D array can be traversed with the array.
(gdb) p *(string + i)
$4 = 73 'I'
```
- Note that when you pass a char arr[x] to a function argument that expects char *.
- the function receives the base address of the passed string, char * behaves as a single char.
- by performing &x inside the function do not expect (*)[x] type it will be `char**` type.

### Understanding 2D array pointer arithmetic, passing to function etc.

- the size of 2D array is calculated by number of elements i.e.
   - arr[2][4], two strings of 4 bytes each that's total 8 bytes in memory. (regardless of the string occupies the full space).
   - for type *arr[5], here arr is array of pointers, meaning, each subscript position is going to hold base address of strings.
   - each of these will be 8 bytes (size of pointer in 64 bit machines), so total 5 * 8 = 40 bytes.
```bash
arr[0] arr[1] arr[2]
  10     11     12
 x656   x657   x658
```
Few more basics on 2D arrays
```bash
    char str[2][4] = {"Bit", "Git"};
```
- Here str decays to `char (*)[4]` (pointer to the first row) in the main if it's being passed to a function. 
- note `&str` gives  `char (*)[2][4]` which is different, this is pointer to whole array.
- [x] so in order to pass the str to a function, the function argument might be written in two different ways.
```bash
// Type 1, simple declaration, basically it decays to char (*)[4]
return_type  <function_name>(char input[size][size])

// Type 2, decyed form of declaration.
return_type <function_name>(char (*input)[size])
```
### Type 1
```c
1	#include <stdio.h>
2	
3	void display(char arr[2][4]) {
4	  for(int i = 0; i < 2; i++) {
5	    for(int j = 0; arr[i][j] != '\0'; j++) {
6	      printf("%c", arr[i][j]);
7	    }
8	    printf("\n");
9	  }
10	}
11	
12	int main() {
13	  char arr[2][4] = {"Bit", "Git"};
```
- In main, arr/&arr & *arr both point to the first row, arr[1] gives your pointer to the second row.
![Image](https://github.com/user-attachments/assets/3f422ea2-ac5f-4da5-a65e-480b101b8d67)

- In display, &arr gives the address of arr variable in display function.
   - arr is the pointer that holds the address of char array that was sent from main.
   - *arr, when dereferenced it points to the first row (so same address as arr).
   - arr[1], or *(arr + 1) points to second row.
   - observe arr is pointer to char[4] i.e. char (*)[4] written beside arr in the below image.
![Image](https://github.com/user-attachments/assets/84ea24ec-ef0f-4156-8a73-fa2e9d399e96)

- The major difference is:
   - arr in main decays to char (*)[4] with address 0xfff000bd8, (pointer to first row).
   - arr in display decays to char (*)[4] as well but with address 0xfff000ba8, as it is local to the function.
   - The display function takes arr as a parameter, and this parameter is a local variable within the function. 
     When main calls display, the function creates its own local copy of the pointer to the array.
   - This means &arr (the address of the pointer variable in display) is different from &arr in main because 
     these are two separate variables, even though they point to the same memory location.
   - In main: &arr: Address of the 2D array in memory.
   - In display: &arr: Address of the local pointer variable in the function's stack frame.
![Image](https://github.com/user-attachments/assets/a03ef831-80e5-4f3b-8244-04e857d4383c)

### Calculation of 2D array elements, function argument is char (*)[size] type

Calculation would be valid for both type 1 and type 2 discussed in [x] above (search [x] to find)
The following is declared in main:
```c
    char strT[2][4] = {"Bit", "Git"};
```
The following is the output of GDB
```bash
sizeof 2D char array :: 8 # 2 rows * 4 columns
address of 2D char array :: 0x7fffffffdef8 without & operator # strT
address of variable &strT :: 0x7fffffffdef8 (pointer to whole array) char (*)[2][4]
size of &StrO :: 8
Value :: Bit address of string 1 :: 0x7fffffffdef8 # strT[0] outputs using %s and %p
Value :: Git address of string 2 :: 0x7fffffffdefc # strT[1] outputs using %s and %p

Breakpoint 1, main () at basics.c:56
warning: Source file is more recent than executable.
56          displayTwoDimensionalString(2, 4, strT);
(gdb) s
# inside the function
# input is the local variable to function displayTwoDimensionalString
# input acts as a pointer to char[4] i.e. char (*)[4]
# input points to 0x7fffffffdef8 which is pointer to the first row of strT[2][4]
displayTwoDimensionalString (rows=2, cols=4, input=0x7fffffffdef8) at basics.c:6
6       void displayTwoDimensionalString(size_t rows, size_t cols, char (*input)[cols]) {
```
What is the type of input here ? how pointer arithmetic works ?
```bash
# Input is of type char (*)[4]
# i.e. incrementing input will move ahead by 4 bytes i.e. next row
# Incrementing input moves it by 4 bytes, because it points to arrays of 4 chars (a row).
(gdb) p input
$1 = (char (*)[variable length]) 0x7fffffffdef8
(gdb) whatis input
type = char (*)[variable length]
```
- discovering the type of input
- input is a pointer to an array (char (*)[4]), the address of input must be a pointer to a pointer to an array.
```bash
# Displays the address of the pointer input itself.
# The value 0x7fffffffde98 is the location where the pointer input is stored.
(gdb) p &input
$2 = (char (**)[variable length]) 0x7fffffffde98
# It is a pointer to a pointer to an array of 4 characters (char[4]).
# means &input is (**)[4] type that holds input char (*)[4] type.
(gdb) whatis &input
type = char (**)[variable length]
```
![Image](https://github.com/user-attachments/assets/0b99a9ed-e6ef-498d-bd63-6d4334be3cdf)

Continuing the calculation,
```bash
(gdb) info locals
j = 0
i = 0
(gdb) p input
$3 = (char (*)[variable length]) 0x7fffffffdef8
# the below expression will not work as size of input is not known at compile time
# that is why "variable length" is reported while printing out p input
(gdb) p input[0]
Cannot perform pointer math on incomplete types, try casting to a known type, or void *.

# we can opt to use the type of input in order to print it.
(gdb) p ((char (*)[4])input)[0]
$4 = "Bit"
# checking the address, it points to the first row.
(gdb) p &((char (*)[4])input)[0]
$5 = (char (*)[4]) 0x7fffffffdef8
# why does it points to first row ?
# Remember that input is of type char (*)[4] type.
# if you increment input by 1 it will move by 4 bytes 
# # but why ?
# # for type char (*)[4] it means pointer to whole array if you consider in 1D array types.
# # so incrementing input by 1 moves it by 4 bytes.
# # Meaning char [2][4] is an array that holds 2 ~ 1D char arrays of size 4 bytes.
# # Why 4 bytes only ?
# it's because size of char is 1 byte.
# char (*)[4] means a pointer to whole 1D array of 4 elements i.e. 1 byte * 4 elements = 4 bytes.
```
For the command `p ((char (*)[4])input)[0]`
- it can be written as follows:
```bash
# input moves by 0 as 0 does not adds value to the address
(gdb) p *(((char (*)[4])input) + 0)
$6 = "Bit"
# we can observe clearly incrementing the input increased address from "def8" to "defc"
(gdb) p &((char (*)[4])input)[1]
$7 = (char (*)[4]) 0x7fffffffdefc
(gdb) p ((char (*)[4])input)[1]
$8 = "Git"
(gdb) p *(((char (*)[4])input) + 1)
$9 = "Git"
```
How can we access the 2D array elements ?
```bash
# how does the calculation for input[i][j] works ?
13 printf("Row[%lu]Col[%lu] :: %c & address :: %p\n", i, j, input[i][j], &input[i][j]);
(gdb) n
Row[0]Col[0] :: B & address :: 0x7fffffffdef8
# Remember that input is char (*)[4] type, incrementing it will move it by 4 bytes.
# input is 0x7fffffffdef8 base address of char [2][4] from main function.
# when i = 0 & j = 0
# input[0]0] can be written as *(*(input + 0) + 0)
#                                ------------
#                                <  step 1  > calculate *(input + 0) --> X
#                              -------------------
#                              <    step 2       > calculate *(X + 0), insert X from step 1
# # Step 1 # #
# *(input + 0) means add 0 to the base address 0x7fffffffdef8
# input + 0 --> 0x7fffffffdef8 + 0  --> 0x7fffffffdef8
# # Important: next is the dereference operator *(input + 0)
#                                               ^
#                                               usage of * after input + 0
# *(0x7fffffffdef8) will give you "Bit" because this address is a pointer to first row.
# So now you have reached till "Bit" which is pointed by 0x7fffffffdef8.
# # Step 2 # # 
# In order to calculate the individual bits
# *(0x7fffffffdef8 + 0) needs to be performed.
# Remeber in step 1 0x7fffffffdef8 is already dereferenced that gives you "Bit"
# This can also be written as ((char (*)[4])input)[0]
(gdb) p *(((char (*)[4])input) + 0)
$1 = "Bit"
# Dereferencing second time
# This can also be written as ((char (*)[4])input)[0][0]
(gdb) p *(*(((char (*)[4])input) + 0) + 0)
$2 = 66 'B'
# When you dereference the second time 
# you are accessing char elements because you went from char [4] to char
# Below is the address that gives you char
(gdb) whatis *(*(((char (*)[4])input) + 0) + 0)
type = char
# Below is the pointer address that gives you the first row
(gdb) whatis *(((char (*)[4])input) + 0)
type = char [4]
```
An example where I'm accessing 2nd Row's 2nd element.
```bash
(gdb) p input
$4 = (char (*)[variable length]) 0x7fffffffdef8
(gdb)  p *(((char (*)[4])input) + 0)
$5 = "Bit"
(gdb)  p *(((char (*)[4])input) + 1)
$6 = "Git"
(gdb)  p *(*(((char (*)[4])input) + 1) + 1)
$7 = 105 'i'
(gdb) x/8c input
0x7fffffffdef8: 66 'B'  105 'i' 116 't' 0 '\000'        71 'G'  105 'i' 116 't' 0 '\000'
```
- How pointer arithmetic works here ?
   - The amount by which a pointer increments (input++) depends on the type of object the pointer points to.
   - If a pointer `points to char`, it increments by sizeof(char) = 1 byte.
   - If a pointer `points to int`, it increments by sizeof(int) (commonly 4 bytes).
   - If a pointer `points to an array of size number of characters`, it increments by the size of the whole array.
      - Meaning: input++ moves by `size * sizeof(char)` bytes.

>Review needed from below:
### Printing 2D array of type char [x][y] from main to function argument of type char (*)[x] type
Why this format ? why function argument format is different is answered below.
- When passing from main function it is passed as char (*)[4] type (decays to pointer to first element i.e. that is char[4]) more discussed below.
- inside the function it behaves like array of pointers inside the function and it will move by x * sizeof(char) * subscript
```bash
sizeof 2D char array :: 8
address of 2D char array :: 0x7fffffffe008 without & operator
address of variable &strT :: 0x7fffffffe008 (pointer to whole array), size of &StrO :: 8
Main function base address string :: one address of string row 0 :: 0x7fffffffe008
Row[0] :: Element[0] - o & address :: 0x7fffffffe008
Row[0] :: Element[1] - n & address :: 0x7fffffffe009
Row[0] :: Element[2] - e & address :: 0x7fffffffe00a
Row[1] :: Element[0] - t & address :: 0x7fffffffe00c
Row[1] :: Element[1] - w & address :: 0x7fffffffe00d
Row[1] :: Element[2] - o & address :: 0x7fffffffe00e
```
#### Calculation of char (*)[x] type.
```bash
(gdb) p strT
$6 = {"one", "two"}
(gdb) p *strT
$7 = "one"
(gdb) p *((*strT) + 0)
$8 = 111 'o'
```
- when array is passed.
```bash
# The input has the same base address as main function's string
displayTwoDimensionalString (rows=2, size=4, input=0x7fffffffe008) at basics.c:4
4       void displayTwoDimensionalString(size_t rows, size_t size, char (*input)[size]) {
(gdb) n
# Now input becomes following format
(gdb) p input
$9 = (char (*)[variable length]) 0x7fffffffe008
# By dereferecning input i get the first string which is stored at base address.
(gdb) p *input
$11 = "one"
# In order to access each element we need to derefence the base address + the element subscript
(gdb) p (*input)[0]
$12 = 111 'o'
(gdb) p *(*input + 0)
$13 = 111 'o'
```
#### Calculation of type char (*)[x] which gets us the whole row.
```bash
(gdb) p input[0]
Cannot perform pointer math on incomplete types, try casting to a known type, or void *.
# base address 008
(gdb) p *((char (*)[4])input + 0)
$21 = "one"
# base address 008 + 1 * 4 (because of type (*)[4]) = 00c
(gdb) p *((char (*)[4])input + 1)
$22 = "two"
(gdb) p &*((char (*)[4])input + 1)
$25 = (char (*)[4]) 0x7fffffffe00c
# Array terminated previously so below string is null
(gdb) p *((char (*)[4])input + 2)
$23 = "\000\000\000"
```
#### Calculation of type char (*)[x] for element access
```bash
# base address
(gdb) p &*((char (*)[4])input + 0)
$34 = (char (*)[4]) 0x7fffffffe008
# defrefence the base address & add  1 
# after dereference it becomes char[4] i.e. char *
(gdb) p *((char (*)[4])input + 0)
$39 = "one"
(gdb) p &*((char (*)[4])input + 0)
$40 = (char (*)[4]) 0x7fffffffe008
(gdb) p *(*((char (*)[4])input + 0) + 1)
$41 = 110 'n'
(gdb) p &*(*((char (*)[4])input + 0) + 1)
$42 = 0x7fffffffe009 "ne"
# This is the same way as writing input[i][j]
```
#### Here when derefrencing char (*)[4] it turns to char * allowing for easier element access
```bash
(gdb) p &*(*((char (*)[4])input + 0))
$45 = 0x7fffffffe008 "one"
(gdb) p &*(*((char (*)[4])input + 0) + 1)
$46 = 0x7fffffffe009 "ne"
(gdb) p &*(*((char (*)[4])input + 0) + 2)
$47 = 0x7fffffffe00a "e"
(gdb) p &*(*((char (*)[4])input + 0) + 3)
$48 = 0x7fffffffe00b ""
(gdb) p &*(*((char (*)[4])input + 0) + 4)
$49 = 0x7fffffffe00c "two"
(gdb) p &*(*((char (*)[4])input + 0) + 5)
$50 = 0x7fffffffe00d "wo"
(gdb) p &*(*((char (*)[4])input + 0) + 6)
$51 = 0x7fffffffe00e "o"
(gdb) p &*(*((char (*)[4])input + 0) + 7)
$52 = 0x7fffffffe00f ""
```
#### Checking what is the type of arr[x][y] when passing to a function.
- strT is declared to be `char strT[2][4] = {"one", "two"};`.
- Compiler says strT is of Type `char (*)[4]`, when passing to a function that takes in argument of type `char**`
```bash
basics.c: In function ‘main’:
basics.c:50:37: warning: passing argument 2 of ‘displayTwo_DimensionalString’ from incompatible pointer type [-Wincompatible-pointer-types]
   50 |     displayTwo_DimensionalString(2, strT);
      |                                     ^~~~
      |                                     |
      |                                     char (*)[4]
basics.c:15:55: note: expected ‘char **’ but argument is of type ‘char (*)[4]’
   15 | void displayTwo_DimensionalString(size_t size, char **input) {
      |
```
> **Why is strT of type char (*)[4] ? where did the [2] go ?**
- In main function, the first element of strT is the first row: char[4] (an array of 4 char).
- Therefore, the type of the decayed strT is a pointer to an array of 4 characters, or char (*)[4].
- The number of rows can be passed as a separate element to the function.

More on how array decays is performed here : [Link](https://github.com/M0hanrajp/c-programming/blob/master/misc_notes/oneDimensional_twoDimensional_array_decay.md#what-is-array-decay)

**Inspecting strT Type in GDB**
```bash
(gdb) whatis strT
type = char [2][4]
```
This shows that strT is indeed an array of 2 elements, where each element is an array of 4 char.

#### Printing out the memory layout

Memory layout will be as same as :

**Main function, Memory layout of `char arr[2][4] = {"one", "two"}`**
![image](https://github.com/user-attachments/assets/9c4fa8d6-29ba-49bc-9246-2aa7105c42ff)

When we are passing the array in the function, input acts as (*)[4] hence we see the below layot.
```bash
# b8 is address of input element 0
address input :: 0x7ffe08ede0b8
# input element 0 at address b8 holds address base address :: 0x7ffe08ede118
# 118 is of char[4] format, using this we can print out the whole string.
Row[0] :: Element[0] - o & address :: 0x7ffe08ede118
Row[0] :: Element[1] - n & address :: 0x7ffe08ede119
Row[0] :: Element[2] - e & address :: 0x7ffe08ede11a
address input :: 0x7ffe08ede0c0
Row[1] :: Element[0] - t & address :: 0x7ffe08ede11c
Row[1] :: Element[1] - w & address :: 0x7ffe08ede11d
Row[1] :: Element[2] - o & address :: 0x7ffe08ede11e
```
**Main function, Memory layout of `char *arr[4] = {"Hello", "programmer!!"}` (array of string pointers)**
![image](https://github.com/user-attachments/assets/e239f6a2-67f1-4827-93fa-3aebd1b7e821)

### Printing 2D array of type `char (*)[y]` from main to function argument of type `char**` type
