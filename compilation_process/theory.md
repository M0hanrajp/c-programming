## Compilation process

https://youtu.be/ksJ9bdSX5Yo?si=NObpF9RA53fnbfO4

![image](https://github.com/user-attachments/assets/8e1e7d49-bef0-4aa4-91a6-306895b86654)

A compiler converts a C program into an executable. There are four phases for a C program to become an executable: 

Here's a concise summary of the C compilation process:
- more in depth please refer process-compilation.md

- **Preprocessing**:
  - Removes comments.
  - Expands macros.
  - Includes header files.
  - Performs conditional compilation.
  - Outputs a preprocessed file (`filename.i`) with expanded code.

- **Compiling**:
  - Converts the preprocessed code (`filename.i`) to assembly code (`filename.s`).
  - Assembly code is human-readable by assembly-level standards.

- **Assembling**:
  - Transforms the assembly code (`filename.s`) into an object file (`filename.o`).
  - The object file contains machine code but lacks external references.

- **Linking**:
  - Resolves function calls (e.g., `printf`) by linking with libraries.
  - Adds extra setup and teardown code for execution.
  - Produces the final executable file (e.g., `filename`).

This series of transformations produces a runnable program from source code.

By executing the below command, we get all intermediate files in the current directory along with the executable.

```bash
$ gcc -Wall -save-temps filename.c –o filename 

mpunix@LIN-5CG3350MRD:~/c-programming/compilation_process$ ls -al
total 56
drwxr-xr-x 2 mpunix mpunix  4096 Nov  3 21:09 .
drwxr-xr-x 9 mpunix mpunix  4096 Nov  3 21:04 ..
-rw-r--r-- 1 mpunix mpunix   145 Nov  3 21:05 main.c
-rwxr-xr-x 1 mpunix mpunix 15960 Nov  3 21:09 steps
-rw-r--r-- 1 mpunix mpunix 18006 Nov  3 21:09 steps-main.i
-rw-r--r-- 1 mpunix mpunix  1544 Nov  3 21:09 steps-main.o
-rw-r--r-- 1 mpunix mpunix   785 Nov  3 21:09 steps-main.s
-rw-r--r-- 1 mpunix mpunix     0 Nov  3 21:06 theory.md
```

In C programming, errors can occur at various stages during the compilation and execution process. Here’s a breakdown of error types and stages:

### 1. **Preprocessing Errors**
   - **Syntax errors in preprocessor directives**: Errors in `#include`, `#define`, or other directives. For example, an incorrect `#include` path or malformed macro definitions.
   - **File not found**: When specified header files or macros cannot be located, an error will occur during preprocessing.

### 2. **Compilation Errors**
   - **Syntax errors**: Mistakes in code syntax, such as missing semicolons, unmatched braces, or incorrect variable declarations.
   - **Type errors**: Mismatches in data types, like assigning an `int` to a `char*` or incorrect function return types.
   - **Undeclared identifiers**: Variables or functions used without prior declaration, leading to "undeclared identifier" errors.
   - **Scope errors**: Variables used outside of their scope or redeclaration within the same scope.
   
### 3. **Assembly Errors**
   - Although rare, if assembly code generation fails (due to incorrect assembly directives), it could cause errors at this stage. Usually, these indicate deeper issues within the compiler or architecture mismatches.

### 4. **Linking Errors**
   - **Undefined references**: Occurs when the linker cannot find the definition for a referenced function or variable (e.g., missing function implementations or external library symbols).
   - **Duplicate symbols**: When multiple definitions of the same function or variable exist (often due to multiple inclusions or incorrect linking).
   - **Library not found**: When required libraries are missing during linking, resulting in unresolved external references.

### 5. **Runtime Errors**
   - **Segmentation faults**: Accessing memory out of bounds or using an uninitialized pointer leads to segmentation faults or access violations.
   - **Memory leaks**: Allocated memory is not freed, leading to memory exhaustion in long-running programs.
   - **Divide-by-zero**: Division by zero results in an undefined or crash state.
   - **Logic errors**: Mistakes in the program's logic that do not cause crashes but produce incorrect results.
   - **Buffer overflows**: Writing outside the bounds of allocated memory, potentially leading to crashes or vulnerabilities.

Each error stage is specific to the development phase and helps identify issues at different levels of code generation and execution. Proper error handling and debugging practices are essential to catch these errors effectively.

## Terms

Let me explain compile time in C programming comprehensively.

Compile time refers to the period/phase when your source code is being converted into machine code (executable) by the compiler. This is distinct from runtime, which is when your program is actually executing.

Here are the key aspects of compile time:

1. Compile Time Phases:
```
Source Code (.c) → Preprocessor → Compiler → Assembler → Linker → Executable
```

2. Detailed Steps:
   - Preprocessing:
     ```c
     #include <stdio.h>    // Header files are included
     #define MAX 100       // Macros are expanded
     ```

   - Compilation:
     ```c
     // Syntax checking
     int main() {
         int x = 10;     // Checked for syntax errors
         prntf("Hi");    // Error caught: undefined function
     }
     ```

   - Linking:
     ```c
     // Links library functions
     printf();    // Linked from stdio.h
     malloc();    // Linked from stdlib.h
     ```

3. Compile Time vs Runtime Examples:

```c
// Compile Time Operations
#define SIZE 100          // Macro expansion
const int MAX = 1000;     // Constant initialization
int array[50];           // Static array size declaration

// Runtime Operations
scanf("%d", &num);       // User input
int* ptr = malloc(size); // Dynamic memory allocation
printf("Result: %d", x); // Output display
```

4. Compile Time Errors:
```c
// Syntax Errors
int main() {
    int x = 10          // Missing semicolon - caught at compile time
    return 0;
}

// Type Errors
int func() {
    return "hello";     // Type mismatch - caught at compile time
}

// Undefined Reference
void test();           // Declaration without definition
```

5. Compile Time Checking:
```c
// Array bounds checking for static arrays
int arr[5];
arr[10] = 5;    // Might not catch at compile time in C

// Type checking
int x = "hello";  // Caught at compile time

// Function argument checking
void func(int x) {}
func("hello");    // Caught at compile time
```

6. Examples of Compile Time vs Runtime Operations:

```c
// Compile Time
#include <stdio.h>
#define SQUARE(x) (x * x)            // Macro expansion at compile time
const int MAX_SIZE = 100;            // Constant at compile time
enum Days {MON, TUE, WED};          // Enum at compile time

// Runtime
int main() {
    int input;
    scanf("%d", &input);             // Runtime operation
    int result = SQUARE(input);      // Calculation at runtime
    int arr[input];                  // VLA - size determined at runtime
    
    return 0;
}
```

7. Resource Allocation:
```c
// Compile Time Allocation
int staticArray[100];              // Memory allocated at compile time
static int globalVar = 10;         // Memory allocated at compile time

// Runtime Allocation
int* dynamicArray = malloc(size);  // Memory allocated at runtime
```

Key Points to Remember:
1. Compile time operations include:
   - Macro expansion
   - Syntax checking
   - Type checking
   - Static memory allocation
   - Constant evaluation

2. Compile time errors are caught before the program runs:
   - Syntax errors
   - Type mismatches
   - Undeclared variables
   - Linking errors

3. Benefits of compile time checking:
   - Early error detection
   - Better performance (optimizations)
   - Type safety
   - Resource management

### References
- https://cs.brown.edu/courses/csci1310/2020/assign/labs/lab2.html
