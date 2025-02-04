### Scenarios of strings 

#### 1D array, expanded form and string literal.

- In the below scenario, sentence is a constant pointer to a char array.
- the funciton display string takes input pointer to a char as an argument.
- base address of sentence is sent, here `string` is mutable, but sentence which is the array name is not mutable.
   - It acts as a constant pointer to a string.
```bash
void displayString(char *input) {
    printf("Address &input %p & value *input %c, value of input (which holds char array's address) %p\n", &input, *input, input);
    for(int i = 0; *input != '\0' ; i++) {
        *input = 'X';
        printf("element :: %c & address of element :: %2d is %p\n", *input, i, input);
        input++;
    }
    printf("\n");
}

int main() {
    char sentence[] = "I use arch linux BTW";
    printf("Address of sentence in main %p\n", sentence);
    displayString(sentence);
    return 0;
}
```
- the char array address itself is the first element's address :
- Observe the first char is 'I' as per sentence[0]. base address of sentence is present inside function.
![Image](https://github.com/user-attachments/assets/57636f13-8148-443e-a627-d8645d8af462)

- Note:
   - declare a pointer variable of type char that holds sentence's address.
   - Then pointer is mutable, string can be modified, you can mutate the pointer inside the function, not in the main function.
- [How size is determined for declaration of type `word[] = "string"` ?](https://github.com/M0hanrajp/c-programming/blob/master/programming_concepts/strings/notes.md#how-size-is-determined-for-declaration-of-type-word--string-)
```bash
Address of sentence in main 0x7ffe9d7d58e0
String in main :: I use arch linux BTW
Address &input 0x7ffe9d7d58a8 & value *input I, value of input # (which holds char array's address) 0x7ffe9d7d58e0
// all characters are modified because of *input = 'X';
element :: X & address of element ::  0 is 0x7ffe9d7d58e0
element :: X & address of element ::  1 is 0x7ffe9d7d58e1
element :: X & address of element ::  2 is 0x7ffe9d7d58e2
element :: X & address of element ::  3 is 0x7ffe9d7d58e3
element :: X & address of element ::  4 is 0x7ffe9d7d58e4
element :: X & address of element ::  5 is 0x7ffe9d7d58e5
element :: X & address of element ::  6 is 0x7ffe9d7d58e6
element :: X & address of element ::  7 is 0x7ffe9d7d58e7
element :: X & address of element ::  8 is 0x7ffe9d7d58e8
element :: X & address of element ::  9 is 0x7ffe9d7d58e9
element :: X & address of element :: 10 is 0x7ffe9d7d58ea
element :: X & address of element :: 11 is 0x7ffe9d7d58eb
element :: X & address of element :: 12 is 0x7ffe9d7d58ec
element :: X & address of element :: 13 is 0x7ffe9d7d58ed
element :: X & address of element :: 14 is 0x7ffe9d7d58ee
element :: X & address of element :: 15 is 0x7ffe9d7d58ef
element :: X & address of element :: 16 is 0x7ffe9d7d58f0
element :: X & address of element :: 17 is 0x7ffe9d7d58f1
element :: X & address of element :: 18 is 0x7ffe9d7d58f2
element :: X & address of element :: 19 is 0x7ffe9d7d58f3
```
> learn more on 1D arrays in detailed manner [here](https://github.com/M0hanrajp/c-programming/blob/master/programming_concepts/strings/two_dimensional_strings/output.md)
#### 1D array of pointers calculations.[here](https://github.com/M0hanrajp/c-programming/blob/master/programming_concepts/strings/two_dimensional_strings/output.md#passing-stro-to-functions)

### Attempting to modify array of pointers leads to seg faults.

The segmentation fault occurs because `str[0]` is a pointer to a string literal `"Welcome"`, which is stored in a read-only section of memory. Attempting to modify a string literal (i.e., `str[0][1] = 'x';`) leads to undefined behavior, typically resulting in a **segmentation fault (SIGSEGV)**.

#### **Breakdown of the Issue**
1. **Declaration of `str`**:
   ```c
   char *str[] = {"Welcome", "to", "jumanji"};
   ```
   - `str` is an array of pointers to string literals.
   - `str[0]`, `str[1]`, and `str[2]` point to string literals `"Welcome"`, `"to"`, and `"jumanji"`, respectively.
   - These string literals are stored in a read-only section of memory.

2. **Attempting to Modify Read-Only Memory**:
   ```c
   str[0][1] = 'x';
   ```
   - This attempts to change the second character of `"Welcome"` from `'e'` to `'x'`.
   - Since `"Welcome"` is a string literal stored in read-only memory, this causes a segmentation fault.

#### **Fix: Using a Modifiable Array**
If you want a modifiable string, declare `str` as an array of character arrays instead of an array of pointers:

```c
char str[][10] = {"Welcome", "to", "jumanji"};
str[0][1] = 'x';  // Now this is valid
```
Or, dynamically allocate memory:
>Note: you can try this in `two_dimensional_array/array_of_pointers_to_strings.c`
```c
char str1[] = "Welcome";  // Stored in writable memory
char str2[] = "to";
char str3[] = "jumanji";
char *str[] = {str1, str2, str3};  // Array of modifiable strings
str[0][1] = 'x';  // Now this works
```
#### gdb debugging of the issue in two_dimensional_array/array_of_pointers_to_strings.c

>Note Refer to `the two_dimensional_array/array_of_pointers_to_strings.c` file for debugging this issue.

```bash
Breakpoint 1, main () at array_of_pointers_to_strings.c:5
5         char *str[] = {"Welcome", "to", "jumanji"};
(gdb) n
8         printf("size of str using sizeof :: %lu\nprints the size of the array of pointers, not the total memory occupied by the strings.\n",
(gdb) n
size of str using sizeof :: 24
prints the size of the array of pointers, not the total memory occupied by the strings.
15         str[0][1] = 'x';
(gdb) n
## Program stops here
Program received signal SIGSEGV, Segmentation fault.
main () at array_of_pointers_to_strings.c:15
15         str[0][1] = 'x';
```
`Backtrace - bt`, sequence of function calls leading to the crash, helping you determine where exactly the issue occurs.
```bash
(gdb) bt
#0  main () at array_of_pointers_to_strings.c:15
```
`(gdb) info proc mappings` This lists memory regions and their permissions (r, w, x). If the segment containing "Welcome"
is read-only, modifying it will cause a segmentation fault.
```bash
(gdb) x/3s str[0]
# The below address is of type char *, holds the string in read only memory
0x555555556008: "Welcome"
0x555555556010: "to"
0x555555556013: "jumanji"
(gdb) info proc mappings
process 21593
Mapped address spaces:

          Start Addr           End Addr       Size     Offset  Perms  objfile
      0x555555554000     0x555555555000     0x1000        0x0  r--p   /home/mpunix/c-programming/programming_concepts/strings/two_dimensional_strings/twod
      0x555555555000     0x555555556000     0x1000     0x1000  r-xp   /home/mpunix/c-programming/programming_concepts/strings/two_dimensional_strings/twod
# 0x555555556008: "Welcome", is in the below range
      0x555555556000     0x555555557000     0x1000     0x2000  r--p   /home/mpunix/c-programming/programming_concepts/strings/two_dimensional_strings/twod
# we can clearly see it has r--p, read only permission, private
      0x555555557000     0x555555558000     0x1000     0x2000  r--p   /home/mpunix/c-programming/programming_concepts/strings/two_dimensional_strings/twod
      0x555555558000     0x555555559000     0x1000     0x3000  rw-p   /home/mpunix/c-programming/programming_concepts/strings/two_dimensional_strings/twod
      0x555555559000     0x55555557a000    0x21000        0x0  rw-p   [heap]
      0x7ffff7d87000     0x7ffff7d8a000     0x3000        0x0  rw-p
      0x7ffff7d8a000     0x7ffff7db2000    0x28000        0x0  r--p   /usr/lib/x86_64-linux-gnu/libc.so.6
      0x7ffff7db2000     0x7ffff7f47000   0x195000    0x28000  r-xp   /usr/lib/x86_64-linux-gnu/libc.so.6
      0x7ffff7f47000     0x7ffff7f9f000    0x58000   0x1bd000  r--p   /usr/lib/x86_64-linux-gnu/libc.so.6
      0x7ffff7f9f000     0x7ffff7fa0000     0x1000   0x215000  ---p   /usr/lib/x86_64-linux-gnu/libc.so.6
      0x7ffff7fa0000     0x7ffff7fa4000     0x4000   0x215000  r--p   /usr/lib/x86_64-linux-gnu/libc.so.6
      0x7ffff7fa4000     0x7ffff7fa6000     0x2000   0x219000  rw-p   /usr/lib/x86_64-linux-gnu/libc.so.6
      0x7ffff7fa6000     0x7ffff7fb3000     0xd000        0x0  rw-p
      0x7ffff7fbb000     0x7ffff7fbd000     0x2000        0x0  rw-p
      0x7ffff7fbd000     0x7ffff7fc1000     0x4000        0x0  r--p   [vvar]
      0x7ffff7fc1000     0x7ffff7fc3000     0x2000        0x0  r-xp   [vdso]
      0x7ffff7fc3000     0x7ffff7fc5000     0x2000        0x0  r--p   /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
      0x7ffff7fc5000     0x7ffff7fef000    0x2a000     0x2000  r-xp   /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
      0x7ffff7fef000     0x7ffff7ffa000     0xb000    0x2c000  r--p   /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
      0x7ffff7ffb000     0x7ffff7ffd000     0x2000    0x37000  r--p   /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
      0x7ffff7ffd000     0x7ffff7fff000     0x2000    0x39000  rw-p   /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
      0x7ffffffde000     0x7ffffffff000    0x21000        0x0  rw-p   [stack]
```
