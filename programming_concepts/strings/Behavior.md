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
    - he base address of an array (e.g., word) cannot be changed after declaration. Reassigning the array’s base address like word = "computer"; is invalid in C.
- Pointers can be reassigned to point to another string.
- Pointers can be reassigned to point to the same memory location of the desired variable.
