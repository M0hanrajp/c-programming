### Proper Structure for multiple files:

1. **Header File (`.h`)**: Declare the function prototype.
2. **Source File (`.c`)**: Define the function implementation.

#### Example

#### 1. Header file (`myfunctions.h`):
```c
// macro names can be anything, it's called guard inclusion
#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H

// Function declaration (prototype)
int add(int a, int b);

#endif  // MYFUNCTIONS_H
```
### **Purpose of Include Guards:**
Include guards prevent a header file from being included multiple times in the same source file. This is crucial because multiple inclusions of the same declarations or definitions can cause compilation errors.

---

### **Explanation of Each Line:**

#### 1. **`#ifndef MYFUNCTIONS_H`**
- **Meaning:** "If `MYFUNCTIONS_H` is **not defined**, then continue with the code that follows."
- **Purpose:** Checks if this macro (`MYFUNCTIONS_H`) has already been defined. If not, the compiler proceeds; otherwise, it skips the content inside the include guard.

#### 2. **`#define MYFUNCTIONS_H`**
- **Meaning:** "Define the macro `MYFUNCTIONS_H`."
- **Purpose:** Prevents the header file from being included again. The next time this header is included, `MYFUNCTIONS_H` will already be defined, so the code inside the include guard will be skipped.

#### 3. **Function Declaration: `int add(int a, int b);`**
- **Meaning:** Declares the function prototype for `add()`.
- **Purpose:** This tells the compiler that there is a function `add` defined elsewhere, usually in a `.c` file. Other files including this header will know about this function.

#### 4. **`#endif  // MYFUNCTIONS_H`**
- **Meaning:** "End of the `#ifndef` block."
- **Purpose:** Closes the conditional directive started with `#ifndef`.

---

### **How It Works in Practice:**
When a source file includes this header, the preprocessor checks:
1. If `MYFUNCTIONS_H` has not been defined, it defines it and includes the content (function prototype).
2. If the header is included again in the same source file, `MYFUNCTIONS_H` is already defined, so the code inside the guard is skipped.

---

### **Example Flow:**

Imagine you have the following scenario:

#### **File 1 (`main.c`):**
```c
#include "myfunctions.h"  // First inclusion
#include "myfunctions.h"  // Second inclusion (accidentally repeated)

int main() {
    int result = add(2, 3);
    return 0;
}
```

#### **During Compilation:**
1. **First inclusion:** `MYFUNCTIONS_H` is not defined, so:
   - It defines `MYFUNCTIONS_H`.
   - Includes the function declaration.

2. **Second inclusion:** `MYFUNCTIONS_H` is already defined, so:
   - The preprocessor skips the entire block inside the guard.

---

### **Why Use Include Guards?**
Without them, multiple inclusions of the same header can lead to:
- **Redefinition errors:** Trying to redeclare functions, variables, or structures.
- **Longer compile times:** Unnecessary processing of the same code multiple times.

---

### **In Summary:**
```c
#ifndef MYFUNCTIONS_H    // Prevents multiple inclusions
#define MYFUNCTIONS_H    // Define the macro once

int add(int a, int b);   // Function prototype

#endif  // MYFUNCTIONS_H  // End of the guard
```
**Include guards ensure that the header's content is processed only once per source file, preventing redefinition errors.**

#### 2. Source file (`myfunctions.c`):
```c
#include "myfunctions.h"

// Function definition
int add(int a, int b) {
    return a + b;
}
```
- Here, we need not declare #include <stdlib-files> again as all can be included inside the .h file.
- the soruce file needs to contain the definiton for the declared function prototype in x header file.

#### 3. Main program (`main.c`):
```c
#include <stdio.h> // can be defined in the header file
#include "myfunctions.h"  // Include the header file

int main() {
    int result = add(3, 4);
    printf("Result: %d\n", result);
    return 0;
}
```
- We can compile the program as follows:
```bash
gcc -g -Wall -o f <soruce>.c <main>.c
```

### Why Avoid Definitions in Headers?
- **Multiple inclusions**: If you include the header in multiple `.c` files, each will have a copy of the function, causing linker errors (multiple definition errors).
- **Separation of concerns**: Keeps interface (function prototypes) separate from implementation (function bodies), improving code readability and maintainability.

### Exceptions
- **Inline functions**: You can define small functions in headers using the `inline` keyword. The compiler might optimize these to avoid multiple definitions.

  ```c
  inline int add_inline(int a, int b) {
      return a + b;
  }
  ```
