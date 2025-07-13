### C Terminologies

| Terminology                 | Definition                                                      | Example                                               | Notes / Usage                                                                        |
| --------------------------- | --------------------------------------------------------------- | ----------------------------------------------------- | ------------------------------------------------------------------------------------ |
| **Keyword**                 | A reserved word with special meaning to the compiler            | `int`, `return`, `if`                                 | Can’t be used as identifiers.                                                        |
| **Identifier**              | Programmer-defined name for functions, variables, etc.          | `total`, `_value`, `calculateArea`                    | Must start with a letter or underscore, followed by letters, digits, or underscores. |
| **Variable**                | Named storage location whose value can change at runtime        | `int count = 10;`                                     | Allocated at compile time (static storage duration if at file scope).                |
| **Constant**                | Immutable value (via `const`)                                   | `const float PI = 3.14f;`                             | Compiler enforces read-only access.                                                  |
| **Literal**                 | Notation for a fixed value in code                              | `42` (integer), `3.14` (float), `"hi"`                | Appear directly in source.                                                           |
| **Data type**               | Classification of data (size & operations)                      | `double`, `char`, `struct Point`                      | Determines how many bytes and what operations are valid.                             |
| **Type qualifier**          | Modifier that adds semantic rules to a type                     | `volatile int status;`                                | `volatile` prevents certain optimizations (e.g. for memory-mapped I/O).              |
| **Storage‐class specifier** | Determines lifetime & linkage                                   | `static int counter;`                                 | `static` at file scope → internal linkage; inside function → persists across calls.  |
| **Operator**                | Symbol that performs operations on data                         | `+`, `-`, `*`, `/`, `==`, `&&`, `&`                   | Arithmetic, logical, bitwise, address-of, etc.                                       |
| **Punctuator**              | Symbols that structure the code                                 | `;`, `,`, `(`, `)`, `{`, `}`                          | Separate tokens and group statements/blocks.                                         |
| **Expression**              | Combination of literals, variables & operators yielding a value | `a + b * 2`, `func(x++)`                              | Can be part of statements or used to compute values.                                 |
| **Statement**               | Complete instruction                                            | `printf("Hi\n");` or `while(i<10) i++;`               | Ends in `;` (expression stmt) or as a compound block `{ … }`.                        |
| **Function**                | Named block that performs a task, optionally returns a value    | `int sum(int a, int b) { return a+b; }`               | Declaration (prototype) vs. definition (body).                                       |
| **Function prototype**      | Declaration of a function’s interface                           | `void foo(double);`                                   | Lets compiler check calls even if definition appears later.                          |
| **Pointer**                 | Variable holding the address of another object                  | `int *p = &count;`                                    | Supports `*`, `&`, arithmetic (± integer), dereferencing.                            |
| **Array**                   | Contiguous sequence of same‐type elements                       | `char name[20];`                                      | Access via `name[i]`. Decays to pointer in many expressions.                         |
| **Structure**               | Composite type grouping multiple named members                  | `struct Point { int x,y; };`                          | Access with `.` or `->`.                                                             |
| **Union**                   | Variant type sharing memory among members                       | `union U { int i; float f; };`                        | Only one member holds a valid value at a time.                                       |
| **Enumeration** (`enum`)    | User-defined integer constants                                  | `enum Color { RED, GREEN, BLUE };`                    | Underlying type is `int`; constants start at 0 by default.                           |
| **Typedef**                 | Creates an alias for a type                                     | `typedef unsigned long u32;`                          | Simplifies complex types (e.g. function pointers).                                   |
| **Macro**                   | Preprocessor substitution                                       | `#define MAX(a,b) ((a)>(b)?(a):(b))`                  | Textually replaced before compilation.                                               |
| **Preprocessor directive**  | Instructions to the compiler’s preprocessor                     | `#include <stdio.h>`, `#ifdef DEBUG`                  | Controls inclusion, conditional compilation, macros, etc.                            |
| **Header guard**            | Prevents multiple inclusion of a header file                    | `#ifndef FOO_H`<br>`#define FOO_H`<br>`…`<br>`#endif` | Ensures declarations appear only once per translation unit.                          |
| **Comment**                 | Annotation ignored by the compiler                              | `/* block comment */`, `// line comment`              | Cannot be nested; good for documentation and disabling code.                         |

---

**Example snippet tying several together:**

```c
// math_utils.h
#ifndef MATH_UTILS_H
#define MATH_UTILS_H

#include <stdio.h>              // preprocessor directive

#define PI 3.14159             // macro

typedef struct {               // typedef + structure
    double x, y;
} Point;

enum ErrorCode {               // enum
    ERR_NONE,
    ERR_OVERFLOW,
    ERR_INVALID
};

extern int totalCount;         // storage‐class specifier + extern declaration

double areaCircle(double r);   // function prototype

#endif // MATH_UTILS_H
```

```c
// math_utils.c
#include "math_utils.h"

int totalCount = 0;            // definition + initialization

double areaCircle(double r) {  // function definition
    return PI * r * r;         // uses macro
}
```
