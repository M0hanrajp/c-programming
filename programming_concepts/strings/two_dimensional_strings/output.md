### contains output of the programs in the folder

Use [`whatis <variable>` in gdb to get to know the type](https://github.com/M0hanrajp/c-programming/blob/188035dbc5b7d9b6857aef5314238186831238b1/programming_concepts/function_pointers/notes.md?plain=1#L19)
- [How size is determined for declaration of type `word[] = "string"` ?](https://github.com/M0hanrajp/c-programming/blob/master/programming_concepts/strings/notes.md#how-size-is-determined-for-declaration-of-type-word--string-)

>## One dimensional array
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

## Two dimensional arrays

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
- If `str` is passed to a function it decays to `char (*)[4]` (pointer to the first row). 
- note `&str` decays to  `char (*)[2][4]` which is different, this is pointer to whole array.
- (x) so in order to pass the str to a function, the function argument might be written in two different ways.
```bash
// Type 1, simple declaration, basically it decays to char (*)[4]
return_type  <function_name>(char input[size][size])

// Type 2, decayed form of declaration.
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

Calculation would be valid for both type 1 and type 2 discussed in (x) above (search (x) to find)
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

### Memory layout of a 2D string array

Memory layout will be as same as :

**Main function, Memory layout of `char arr[2][4] = {"one", "two"}`**
![image](https://github.com/user-attachments/assets/9c4fa8d6-29ba-49bc-9246-2aa7105c42ff)

When we are passing the array in the function, input acts as (*)[4] hence we see the below layot.
```bash
# b8 is base address of input which is a variable to a local function.
address input :: 0x7ffe08ede0b8
# input base address 0x7ffe08ede0b8 holds address :: 0x7ffe08ede118 which is pointer to a char.
# 10x7ffe08ede118 is pointer to char (*)[4] using this we can print out the whole string.
Row[0] :: Element[0] - o & address :: 0x7ffe08ede118
Row[0] :: Element[1] - n & address :: 0x7ffe08ede119 ##  *(*(0x7ffe08ede118 + 0) + 1) # for in detail calculations check above calculations
Row[0] :: Element[2] - e & address :: 0x7ffe08ede11a
address input :: 0x7ffe08ede0c0
Row[1] :: Element[0] - t & address :: 0x7ffe08ede11c
Row[1] :: Element[1] - w & address :: 0x7ffe08ede11d
Row[1] :: Element[2] - o & address :: 0x7ffe08ede11e
```
**Main function, Memory layout of `char *arr[4] = {"Hello", "programmer!!"}` (array of string pointers)**
![image](https://github.com/user-attachments/assets/e239f6a2-67f1-4827-93fa-3aebd1b7e821)

### Array of pointers.

How can array of pointers save memory for storing strings.

#### Basic memory layout of two dimensional arrays
![Image](https://github.com/user-attachments/assets/31858d24-49b3-4613-8b42-39831ce38b82)
- Note, green line: are of type `char *[3]` (do not confuse with `char (*)[3]` because both are different.
- Note, purple line: are of type `char *` which store a string.
```bash
# # # Basics of array of pointers
# str is of type char *[3] even when size is not mentioned in main.
# compiler automatically deduces the size based on the number of elements (which is 3 here).
# char *[3] would mean array of 3 pointer elements.
# The address 0x555555556008 holds the string "Welcome" which is of type char *.
(gdb) p str
$1 = {0x555555556008 "Welcome", 0x555555556010 "to", 0x555555556013 "jumanji"}
(gdb) whatis str
type = char *[3]
# We can observe below that str's address is 0x7fffffffdf20
# When we type "whatis str" in gdb it says it's of type char *[3]
# as it points to the first element of the array
# so 0x7fffffffdf20 is of type char *[3], but when it is used in an
# expression it converts to "char **" per C spec 6.3.2.1
# and 0x7fffffffdf20 holds 0x555555556008 "Welcome" see further below.
(gdb) printf"%p\n", str
0x7fffffffdf20
# below &str gives the type pointer to a array of 3 pointer elements or 3 char * elements.
(gdb) whatis &str
type = char *(*)[3]
# `&str` remains `char *(*)[3]`, which is a pointer to the entire array
(gdb) printf"%p\n", &str
0x7fffffffdf20
(gdb) p &str
$2 = (char *(*)[3]) 0x7fffffffdf20
```
#### Accessing array elements ( string as a whole )
```bash
# One of the main advantages of array of pointers is the ease of accessing a string. (as a whole)
# str is an array of pointers to char, meaning each element str[i] is a pointer to a string literal.
(gdb) whatis str
type = char *[3]
# decays to char ** when used in an expression
(gdb) whatis str + 0
type = char **
(gdb) whatis str + 1
type = char **
(gdb) whatis str + 2
type = char **
(gdb) p str + 0
# Following are the address of the pointers that hold char *
$3 = (char **) 0x7fffffffdf20
(gdb) p str + 1
$4 = (char **) 0x7fffffffdf28 # ---> f20 + 8 = f28
(gdb) p str + 2
$5 = (char **) 0x7fffffffdf30 # ---> f28 + 8 = f30 
# (28 in hex -> 2 * 16 ^ 1 + 8 * 16 ^ 0. -> 48 in dec -> 30 in hex
(gdb) p str
$6 = {0x555555556008 "Welcome", 0x555555556010 "to", 0x555555556013 "jumanji"}
# # # Calculations
# Array of pointers contain different memory locations that point to string.
# since variables hold address which are of size 8 bytes on a 64 bit machine.
# when *(str + x) is performed (x = 1, 2..), total expression moves by 8 bytes.
# Which help to access each array elements.
# these addresses 0x7fffffffdf20 0x7fffffffdf28 & 0x7fffffffdf30 hold pointer to char
# We are dereferencing 0x7fffffffdf20, this is equal to *str which holds 0x555555556008
# sizeof(char *) = 8 bytes

# Formula == (base address of str) + (1 * size of (char *))
(gdb) p *(str + 0) # in other words str[0]
$7 = 0x555555556008 "Welcome"
#  str + 1 = str + (0 * 8) = 0x7fffffffdf20 +  0 = 0x7fffffffdf20 ---> *0x7fffffffdf20 ---> 0x555555556008

(gdb) p *(str + 1) # in other words str[1]
$11 = 0x555555556010 "to"
# str + 1 = str + (1 * 8) = 0x7fffffffdf20 +  8 = 0x7fffffffdf28 ---> *0x7fffffffdf28 ---> 0x555555556010

(gdb) p *(str + 2) # in other words str[2]
$12 = 0x555555556013 "jumanji"
# str + 2 = str + (2 * 8) = 0x7fffffffdf20 + 16 = 0x7fffffffdf30 ---> *0x7fffffffdf30 ---> 0x555555556013
# Note
# 0x7fffffffdf28 or 0x7fffffffdf30 are NOT a char *[3], because arrays do not decay at non-zero indices.
```
✅ str (by itself) is an array (char *[3]).
✅ str (when used in an expression) decays into char **.
✅ str + 1 is just a pointer to str[1], not an array anymore.
✅ Arrays only decay once, at str, not at str + 1 or further.

- For reference:0x400584, 0x40058C, 0x40058F are all `char *` elements. 
- They can be accessed from 0xFFF000BC0, 0xFFF000BC8 & 0xFFF000BD0 which are `char **` type.
![Image](https://github.com/user-attachments/assets/31858d24-49b3-4613-8b42-39831ce38b82)

#### Accessing individual elements of a string in array of pointers.
```bash
# str is an array of pointers to char, meaning each element str[i] is a pointer to a string literal.
(gdb) info locals
str = {0x555555556008 "Welcome", 0x555555556010 "to", 0x555555556013 "jumanji"}
(gdb) p *(str + 0)
$16 = 0x555555556008 "Welcome"
# Since "Welcome" is a string literal, *(str + 0) is of type char *.
# Accessing individual elements
(gdb) p *(*(str + 0) + 0)
$18 = 87 'W'
# # # calculation.
# *(*(str + 0) + 0)
#    ---------
#    <step 1>
# ----------------
#    <step 2>
# <step 1> This step is to move by 8 bytes to pointer to char * (char **) in an array
# -----------------------------------------------------------------------------------
# *(str + 0)
# Formula == (base address of str) + (1 * size of (char *))
# str + 1 = str + (1 * 8) = 0x7fffffffdf20 + 0 = 0x7fffffffdf20
# 
# <step 2> after getting pointer to char ** address in the array.
# ---------------------------------------------------------------
# we use this address to dereference to a char * address and then access individual elements from it.
# so the expression now 
# *(*(0x7fffffffdf20) + 0)
# 1. *0x7fffffffdf20 --> 0x555555556008 "Welcome"
(gdb) whatis *(str + 0)
type = char *
# 2. *(0x555555556008) ---> 'W' (because *(0x7fffffffdf20) + 0 = 0x7fffffffdf20)"
(gdb) p *(*(str + 0) + 0)
$18 = 87 'W'
# The type is char as we are accessing individual elements
(gdb) whatis *(*(str + 0) + 0)
type = char
### rest of the elements.
(gdb) p *(*(str + 0) + 1)
$19 = 101 'e'
(gdb) p *(*(str + 0) + 2)
$20 = 108 'l'
(gdb) p *(*(str + 0) + 3)
$21 =  99 'c'
(gdb) p *(*(str + 0) + 4)
$22 = 111 'o'
(gdb) p *(*(str + 0) + 5)
$23 = 109 'm'
(gdb) p *(*(str + 0) + 6)
$24 = 101 'e'
# Proof with their character address
# Note here there is no 2nd * operator in order to print address.
# if we dereference it again it decays to char literal not char *
(gdb) printf"%p\n", (*(str + 0) + 0)
0x555555556008
(gdb) printf"%p\n", (*(str + 0) + 1)
0x555555556009
(gdb) printf"%p\n", (*(str + 0) + 2)
0x55555555600a
(gdb) printf"%p\n", (*(str + 0) + 3)
0x55555555600b
(gdb) printf"%p\n", (*(str + 0) + 4)
0x55555555600c
(gdb) printf"%p\n", (*(str + 0) + 5)
0x55555555600d
(gdb) printf"%p\n", (*(str + 0) + 6)
0x55555555600e
```
#### Output of the program at phase 1
```bash
size of str using sizeof :: 24
String[0] ::  Welcome at address :: 0x56381814f008 stored in 0x7ffd6cb23020
Element[0] :: W at address :: 0x56381814f008 stored in 0x7ffd6cb23020
# 0x56381814f008 is the first element address, ignore the stored in x statement it's just for mapping purpose
Element[1] :: e at address :: 0x56381814f009 stored in 0x7ffd6cb23020
Element[2] :: l at address :: 0x56381814f00a stored in 0x7ffd6cb23020
Element[3] :: c at address :: 0x56381814f00b stored in 0x7ffd6cb23020
Element[4] :: o at address :: 0x56381814f00c stored in 0x7ffd6cb23020
Element[5] :: m at address :: 0x56381814f00d stored in 0x7ffd6cb23020
Element[6] :: e at address :: 0x56381814f00e stored in 0x7ffd6cb23020
String[1] ::       to at address :: 0x56381814f010 stored in 0x7ffd6cb23028
Element[0] :: t at address :: 0x56381814f010 stored in 0x7ffd6cb23028
Element[1] :: o at address :: 0x56381814f011 stored in 0x7ffd6cb23028
String[2] ::  jumanji at address :: 0x56381814f013 stored in 0x7ffd6cb23030
Element[0] :: j at address :: 0x56381814f013 stored in 0x7ffd6cb23030
Element[1] :: u at address :: 0x56381814f014 stored in 0x7ffd6cb23030
Element[2] :: m at address :: 0x56381814f015 stored in 0x7ffd6cb23030
Element[3] :: a at address :: 0x56381814f016 stored in 0x7ffd6cb23030
Element[4] :: n at address :: 0x56381814f017 stored in 0x7ffd6cb23030
Element[5] :: j at address :: 0x56381814f018 stored in 0x7ffd6cb23030
Element[6] :: i at address :: 0x56381814f019 stored in 0x7ffd6cb23030
```
you can match the above output to the below snippet for more clarification
![Image](https://github.com/user-attachments/assets/31858d24-49b3-4613-8b42-39831ce38b82)

#### What is the difference between `char *[3]` and `char (*)[3]`
- Naming convention `char *[3]` Array of 3 pointers to char & `char (*)[3]` pointer to an array of 3 char elements.
- `char *[3]` 
   - This is an array of 3 pointers to char, Each element of the array is a pointer to a char.
   - Each element in the array points to a different memory location (a char or a string).
   - For any `char *str[3]` variable:
      - #### Cannot perform str++ 
      - str is not a pointer variable; it's an array name, which acts as a constant pointer to str[0].
      - Trying to increment str (str++) is like trying to modify a constant pointer, which is not allowed.
      ```bash
      array_of_pointers_to_strings.c: In function ‘main’:
      array_of_pointers_to_strings.c:6:6: error: lvalue required as increment operand
          6 |   str++;
            |      ^~
      ```
      - Note: str + 1 is allowed because it computes a new address without modifying str.
      - str++ is not allowed because str is an array name, which acts as a constant pointer and cannot be changed.

      - #### But could perform (*str)++
      - For the declaration:
      ```bash
        char *str[] = {"Welcome", "to", "jumanji"};
      ```
      - The elements of the array (str[0], str[1], etc.) are modifiable pointers, and you can change what they point to
        (e.g., by using (*str)++).
      - Meaning if you look at the above memory map, str is of type `char *[3]`, we cannot modify it since it's a constant pointer.
      - When you dereference str, *str gives you the pointer to a constant string, this pointer is mutable. hence (*str)++ is valid.
      - For the declaration:
      ```bash
        char *str[] = {"Welcome", "to", "jumanji"};
        char a[4] = "asd";
        char q[3] = "er";
        char v[2] = "1";
        str[0] = a;
        str[1] = q;
        str[2] = v;
        ```
      - Here I have assigned a, q, v to str, My thinking is since a is a constant pointer to "asd" can we still do (*str)++ ?
      - Yes, we can, Array names like `a` decay into pointers when passed or assigned. So, when you do str[0] = a;, you are 
        assigning the pointer to the first element of a (&a[0]) to str[0].
      - Based on the C spec, 6.3.2.1 Whenever an array appears in most expressions, it is implicitly converted to a pointer to its first element.
- `char (*)[3]`
   - This is a pointer to an array of 3 char, ptr is a pointer to the entire array arr, not just an element.
   - Points to a contiguous block of memory containing 3 char elements.(Remeber it points to the location where 3 char elements are present).

#### When an array is used in an expression it decays into a pointer to it's first element.
#### C spec 6.3.2.1
- this question came to my mind when using gdb, the output for `whatis str` and `whatis str + 0` type was different.
- when I expected it to be same, as I was thinking from arithmetic POV, that the address remains the same regardless of the expression.
- This behavior is defined in C spec 6.3.2.1, refer above for more details.
![Image](https://github.com/user-attachments/assets/8a6c0f4d-fc1c-47a2-9add-47d92472efeb)
```bash
# Str is of type char *[3]
(gdb) p str
$1 = {0x555555556008 "Welcome", 0x555555556010 "to", 0x555555556013 "jumanji"}
(gdb) whatis str
type = char *[3]
# str becomes char ** when str + 0 is performed
(gdb) whatis str + 0
type = char **
# str address remains the same for all the types.
(gdb) printf"%p\n", str
0x7fffffffdf10
(gdb) printf"%p\n", &str
0x7fffffffdf10
(gdb) printf"%p\n", str + 0
0x7fffffffdf10
```
- In C, when an array name is used in an expression (except with sizeof or &), it decays into a pointer to its first element.
- str is an array of pointers (char *[3]), so it decays into a pointer to its first element (char **).

#### Passing array of pointers to a function
- When passing an array of pointers i.e. `char *[3]` from main.
- They decay into `char **` pointer to the first element.
```bash
array_of_pointers_to_strings.c: In function ‘main’:
array_of_pointers_to_strings.c:43:11: warning: passing argument 1 of ‘display’ from incompatible pointer type [-Wincompatible-pointer-types]
   43 |   display(str, 3);
      |           ^~~
      |           |
      |           char **
```
- Hence the function argument is going to be `(char **)`, `char *[]` is also acceptable.
```bash
# code
void display(char **input, unsigned size) { // this can be written as *input[]
  printf("Input is local to the function display hence it's address will be different\naddress of input :: %p\n", &input);
  for(unsigned i = 0; i < size; i++) {
      printf("<< String[%u]  >> :: %8s at address :: %p stored in %p\n", i, input[i], input[i], input + i);
      for(unsigned j = 0; input[i][j] != '\0'; j++) {
          printf("Element[%u] :: %c at address :: %p stored in %p\n", j, input[i][j], (*(input + i) + j), input + i);
      }
  }
  // for(unsigned i = 0; input[i] != NULL; i++) 
  // the above statement works only if input[i] is NULL.
  // so char *str[] = {"Welcome", "to", "jumanji", NULL}; will work but if not declared then it will cause a segfault
}
```
The calculation remains the same.
```bash
$ ./twod
total memory occupied by elements of str :: 24
prints the size of the array of pointers, not the total memory occupied by the strings.
Input is local to the function display hence address will be different
address of input :: 0x7ffe87323578
<< String[0]  >> ::  Welcome at address :: 0x5614f689c0d9 stored in 0x7ffe873235a0
Element[0] :: W at address :: 0x5614f689c0d9 stored in 0x7ffe873235a0
Element[1] :: e at address :: 0x5614f689c0da stored in 0x7ffe873235a0
Element[2] :: l at address :: 0x5614f689c0db stored in 0x7ffe873235a0
Element[3] :: c at address :: 0x5614f689c0dc stored in 0x7ffe873235a0
Element[4] :: o at address :: 0x5614f689c0dd stored in 0x7ffe873235a0
Element[5] :: m at address :: 0x5614f689c0de stored in 0x7ffe873235a0
Element[6] :: e at address :: 0x5614f689c0df stored in 0x7ffe873235a0
<< String[1]  >> ::       to at address :: 0x5614f689c0e1 stored in 0x7ffe873235a8
Element[0] :: t at address :: 0x5614f689c0e1 stored in 0x7ffe873235a8
Element[1] :: o at address :: 0x5614f689c0e2 stored in 0x7ffe873235a8
<< String[2]  >> ::  jumanji at address :: 0x5614f689c0e4 stored in 0x7ffe873235b0
Element[0] :: j at address :: 0x5614f689c0e4 stored in 0x7ffe873235b0
Element[1] :: u at address :: 0x5614f689c0e5 stored in 0x7ffe873235b0
Element[2] :: m at address :: 0x5614f689c0e6 stored in 0x7ffe873235b0
Element[3] :: a at address :: 0x5614f689c0e7 stored in 0x7ffe873235b0
Element[4] :: n at address :: 0x5614f689c0e8 stored in 0x7ffe873235b0
Element[5] :: j at address :: 0x5614f689c0e9 stored in 0x7ffe873235b0
Element[6] :: i at address :: 0x5614f689c0ea stored in 0x7ffe873235b0
```
