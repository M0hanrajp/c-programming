### Snippet 1
```c
#include <stdio.h>

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", num);
    printf("You entered: %d\n", num);
    return 0;
}
```
Answer (me):
* scanf is a c library function, in order to store num, we need to store the variable at &num.
* This is a compile time error.

```bash
# Answer is correct, 
mpunix@LIN-5CG3350MRD:~/c-programming/compilation_process$ gcc -g -Wall rough.c
rough.c: In function ‘main’:
rough.c:6:13: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘int’ [-Wformat=]
    6 |     scanf("%d", num);
      |            ~^   ~~~
      |             |   |
      |             |   int
      |             int *
rough.c:6:5: warning: ‘num’ is used uninitialized [-Wuninitialized]
    6 |     scanf("%d", num);
      |     ^~~~~~~~~~~~~~~~
```
---

### Snippet 2
```c
#include <stdio.h>

int main() {
    int array[5];
    array[10] = 50;
    printf("Value: %d\n", array[10]);
    return 0;
}
```
Answer (me):
* array has been allocated value 50 at element 9, when initially size of array is declared to be 5.
* This leads to buffer overflow (Writing outside bounds of allocated memory).
* Error will be reported at runtime.

Corrections:
* Error is reported at runtime, error is segmentation fault that is caused by buffer overflow since we are accessing memory out of bounds.
```bash
mpunix@LIN-5CG3350MRD:~/c-programming/compilation_process$ gcc -g -Wall -fsanitize=address rough.c
mpunix@LIN-5CG3350MRD:~/c-programming/compilation_process$ ./a.out
=================================================================
==17561==ERROR: AddressSanitizer: stack-buffer-overflow on address 0x7fffa9462568 at pc 0x556045c982f6 bp 0x7fffa9462510 sp 0x7fffa9462500
WRITE of size 4 at 0x7fffa9462568 thread T0
    #0 0x556045c982f5 in main /home/mpunix/c-programming/compilation_process/rough.c:5
    #1 0x7f1028e9ed8f in __libc_start_call_main ../sysdeps/nptl/libc_start_call_main.h:58
    #2 0x7f1028e9ee3f in __libc_start_main_impl ../csu/libc-start.c:392
    #3 0x556045c98164 in _start (/home/mpunix/c-programming/compilation_process/a.out+0x1164)

Address 0x7fffa9462568 is located in stack of thread T0 at offset 72 in frame
    #0 0x556045c98238 in main /home/mpunix/c-programming/compilation_process/rough.c:3

  This frame has 1 object(s):
    [32, 52) 'array' (line 4) <== Memory access at offset 72 overflows this variable
HINT: this may be a false positive if your program uses some custom stack unwind mechanism, swapcontext or vfork
      (longjmp and C++ exceptions *are* supported)
SUMMARY: AddressSanitizer: stack-buffer-overflow /home/mpunix/c-programming/compilation_process/rough.c:5 in main
Shadow bytes around the buggy address:
  0x100075284450: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x100075284460: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x100075284470: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x100075284480: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x100075284490: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
=>0x1000752844a0: 00 00 00 00 f1 f1 f1 f1 00 00 04 f3 f3[f3]f3 f3
  0x1000752844b0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x1000752844c0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x1000752844d0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x1000752844e0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x1000752844f0: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
  Shadow gap:              cc
==17561==ABORTING
```
Theory part of address sanitizer

This AddressSanitizer output provides a detailed diagnosis of a **stack buffer overflow** in the program. Let’s break down each part of the output:

### Key Sections of the Output

1. **Error Summary**:
   ```
   ERROR: AddressSanitizer: stack-buffer-overflow on address 0x7fffa9462568
   ```
   - This line indicates that a **stack buffer overflow** occurred at a specific memory address (`0x7fffa9462568`).
   - "Stack buffer overflow" means data was written beyond the allocated bounds of a variable on the stack (in this case, `array[5]`).

2. **Error Location**:
   ```
   WRITE of size 4 at 0x7fffa9462568 thread T0
   ```
   - The error happened during a **write operation** of size 4 bytes (likely an `int`), which fits with trying to write `50` to `array[10]`.
   - The error occurred in **thread T0** (the main thread) and points to an invalid write beyond the array’s allocated space.

3. **Call Stack**:
   ```
   #0 0x556045c982f5 in main /home/mpunix/c-programming/compilation_process/rough.c:5
   ```
   - The issue originates from line 5 in `rough.c`, inside the `main` function.
   - This shows where the overflow occurred—`array[10] = 50;`.

4. **Address Analysis**:
   ```
   Address 0x7fffa9462568 is located in stack of thread T0 at offset 72 in frame
   ```
   - The faulty address `0x7fffa9462568` lies on the **stack**, 72 bytes from the base of the `main` frame.
   - **Memory Layout Info**: The line shows the layout of the `array` variable, making it clear that memory outside `array` has been overwritten.

5. **Explanation of Memory Issue**:
   ```
   This frame has 1 object(s):
       [32, 52) 'array' (line 4) <== Memory access at offset 72 overflows this variable
   ```
   - This line describes the memory range for `array`, which spans 20 bytes (from offset 32 to 52).
   - The attempted write happened at offset 72, well beyond `array`'s allocated space, confirming the **buffer overflow**.

### Shadow Byte Legend
   ```
   Shadow byte legend (one shadow byte represents 8 application bytes):
   ```
   - The shadow memory provides a map to help locate regions of memory:
      - `f3` in `[f3]f3 f3 f3` means **stack right redzone**, where access violations are flagged. The `f3` indicates the area was outside `array`'s bounds, causing a **segmentation fault**.

### Summary

In short, AddressSanitizer shows that:
- You’re accessing `array[10]`, which is outside its allocated bounds (`array[5]`).
- This causes a **stack buffer overflow**, writing into an area that triggers the segmentation fault.

This is a typical way AddressSanitizer helps identify buffer overflows, even when they don’t cause immediate errors without it.

---

### Snippet 3
```c
#include <stdio.h>

void greet();

int main() {
    greet();
    return 0;
}
```
Answer (me):
* No errors.

Corrections:
* The program gives, linker error due to `void greet();` This line is a declaration of the greet function, informing the compiler that a function named greet exists and will return void with no parameters.
* However, there’s no definition provided for greet (no body of the function with actual code). So, when main calls greet();, the linker looks for the function’s definition to generate the executable, but it can’t find one.
```bash
# The error 
mpunix@LIN-5CG3350MRD:~/c-programming/compilation_process$ gcc -g -Wall rough.c
/usr/bin/ld: /tmp/ccRGk9zl.o: in function `main':
/home/mpunix/c-programming/compilation_process/rough.c:6: undefined reference to `greet'
collect2: error: ld returned 1 exit status
```
Theory based on the error:

### Identifying a Linker Error from the Message

1. **Error Location**:
   - The message mentions `/usr/bin/ld`, which is the **linker** (often called `ld`). This program is responsible for resolving function references, combining object files, and generating the final executable.
   - Since the error originates from `ld`, it points to a **linking issue** rather than a compilation problem.

2. **"Undefined Reference" Phrase**:
   - Linker errors often use the term **"undefined reference"**. This means that the compiler has compiled code that references a function or variable (like `greet`) but cannot find its definition when trying to create the executable.

3. **Successful Compilation**:
   - If you don’t see syntax or type-related error messages from `gcc` before the linker error, it indicates that the **compilation phase was successful**.
   - The code compiled without errors, but the linker failed when it couldn’t find a definition for `greet`.

4. **Error Order**:
   - Linker errors generally appear **after** the compilation errors, as linking is the final step.

### Recap: Linker Error Characteristics
So, if you see:
- References to `ld` or "collect2" (a wrapper around `ld` for linking).
- Terms like "undefined reference" in a function or variable.
- The absence of compiler-specific syntax or semantic error messages before this.

The linker is called ld because it stands for "loader." Historically, the tool's job was not only to link various pieces of code together but also to load the final executable into memory. Over time, its primary purpose shifted to linking, but the name "ld" stuck.Today, ld exclusively handles the linking phase, combining object files and resolving references to create a complete executable.

Got it! Here are the code snippets with no hints. Let's see how you do:

---

### Snippet 4

```c
#include <stdio.h>

int main() {
    printf("Result: %d\n", 5 / 0);
    return 0;
}
```
Answer (me):
* Runtime error, divide by 0, might result in crash.

The error
```bash
mpunix@LIN-5CG3350MRD:~/c-programming/compilation_process$ gcc -g -Wall rough.c
rough.c: In function ‘main’:
rough.c:4:30: warning: division by zero [-Wdiv-by-zero]
    4 |     printf("Result: %d\n", 5 / 0);
      |
```
---

### Snippet 5

```c
#include <stdio.h>

int main() {
    int x = 5;
    if (x = 10) {
        printf("X is 10\n");
    } else {
        printf("X is not 10\n");
    }
    return 0;
}
```
Answer (me):
* Compile time error, assignment is not allowed in if statement `x = 10`.

Correction:
* My answer is only valid if program is compiled as gcc -g -Wall option enabled.
* Then compiler reports the following:
```bash
mpunix@LIN-5CG3350MRD:~/c-programming/compilation_process$ gcc -g -Wall rough.c
rough.c: In function ‘main’:
rough.c:5:9: warning: suggest parentheses around assignment used as truth value [-Wparentheses]
    5 |     if (x = 10) {
      |
```
* if not then no error is reported.
* if compiled normally, executable is generated, x will be assigned the value 10, and the condition will evaluate to true because the assignment returns the value of x, which is 10.
This will result in the output: "X is 10".

---

### Snippet 6

```c
#include <stdio.h>

#define SIZE 10;

int main() {
    int arr[SIZE] = {0};
    printf("Array size: %d\n", sizeof(arr) / sizeof(arr[0]));
    return 0;
}
```
Answer (me):
- Not sure about this, or nor error.

Correction:
- Compile time error, syntax error, there should not be any semicolon after macro SIZE is defined.
```bash
mpunix@LIN-5CG3350MRD:~/c-programming/compilation_process$ gcc -g -Wall rough.c
rough.c: In function ‘main’:
rough.c:3:16: error: expected ‘]’ before ‘;’ token
    3 | #define SIZE 10;
      |                ^
rough.c:6:13: note: in expansion of macro ‘SIZE’
    6 |     int arr[SIZE] = {0};
      |             ^~~~
rough.c:7:39: error: ‘arr’ undeclared (first use in this function)
    7 |     printf("Array size: %d\n", sizeof(arr) / sizeof(arr[0]));
      |                                       ^~~
rough.c:7:39: note: each undeclared identifier is reported only once for each function it appears in
```
---

### Snippet 7

```c
#include <stdio.h>

extern int externalVar;

int main() {
    printf("External variable: %d\n", externalVar);
    return 0;
}
```
