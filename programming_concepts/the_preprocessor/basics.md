## C preprocessor

- Converts source code to expanded source code, from `.c` to `.i` file.
```c
#define PI 3.14
   ^-------------------- Preprocessor directive
        ^--------------- macro template
            ^----------- macro expansion
```
- replace the occurrance of `PI` in a program with 3.14.

### Rules for defining preprocessor directive
- There should be no blankspace between macro template and it's argument.
- paranthesis for the macro expansion is necessary.
- define preprocessor directives as multiline using `\`.
- Usage of macro in a program expands the program size but execution of program is faster.
- Usage of functions reduces program size but execution of a program is slower.

### File inclusion
- if you are creating a large program that is being distributed to others:
   - a] Functions are defined in .c file, corresponding prototype declarations are included in .h files/
   - b] When the application is distributed the .c which contains the definitions are compiled to `.so` or `.a` files (library files).
   - c] so the user has access to .h files and `.so` or `.a` files that are used to run the application.

- Difference in using `#include <stdio.h>` & `#include "myfile.h"`

| Feature                         | `#include <file>`                                                                                                                                                    | `#include "file"`                                                                                                                                       |
| ------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Syntax Delimiters**           | Angle brackets (`<` `>`)                                                                                                                                             | Double quotes (`"` `"`).                                                                                                                                |
| **Primary Use**                 | System or third-party headers installed in global include paths.                                                                                                     | Project-local headers, private modules, or overrides.                                                                                                   |
| **Search Order**                | 1. Implementation-defined system include directories (e.g. `/usr/include`, plus any `-isystem` or default paths).<br>2. Any `-I` directories (unless marked system). | 1. Directory of the **including** file (your project folder).<br>2. Implementation-defined system include directories.<br>3. Any additional `-I` paths. |
| **Collision Avoidance**         | Won’t accidentally pick up a same-named header in your project directory.                                                                                            | Will pick up a same-named header in your project before the system one.                                                                                 |
| **Typical Examples**            | `c\n#include <stdio.h>\n#include <curl/curl.h>\n`                                                                                                                    | `c\n#include "myfile.h"\n#include "utils/math_helpers.h"\n`                                                                                             |
| **Behavior if Not Found**       | Error after searching all system/include paths and any specified `-I` paths.                                                                                         | Error after searching local directory first, then system/include paths and any `-I` paths.                                                              |
| **Use with `-I` Flags**         | `-I` adds to search list **after** system paths (unless `-isystem`).                                                                                                 | `-I` adds to search list **after** local directory, but before system paths (unless `-isystem`).                                                        |
| **Portability Considerations**  | Always picks up the installed library’s headers—good for portable code relying on standard or installed APIs.                                                        | Ensures you get your local version—useful when bundling or overriding headers.                                                                          |
| **Override Capability**         | Harder to override system headers (you’d need to adjust compiler flags).                                                                                             | Easy to override system headers by placing a file with the same name in your local directory.                                                           |
| **Visibility to Other Modules** | Intended for globally-available 

### Conditional compilaion

>check multiple_file_compilation/ to understand usecases

1. **Header Inclusions**

   * `<stdio.h>` brings in the declaration for `printf`.
   * `"conditional_compilation.h"` must declare (or define) the `print()` function that’s called later.

2. **Macro Definition**

   ```c
   #define MACRO_NAME
   ```

   This unconditionally defines `MACRO_NAME` before `main()` runs.

3. **`#ifdef` / `#else` / `#endif`**

   ```c
   #ifdef MACRO_NAME
       printf("Macro name is defined\n");
   #else
       printf("Macro is not defined\n");
   #endif
   ```

   * Checks “if `MACRO_NAME` exists.”
   * Since you’ve just done `#define MACRO_NAME`, the first branch (`"Macro name is defined"`) will always execute.

4. **`#ifndef` / `#else` / `#endif`**

   ```c
   #ifndef MACRO_CODE
       printf("Macro code is not defined\n");
   #else
       printf("Macro code and are defined\n");
   #endif
   ```

   * Checks “if `MACRO_CODE` is *not* defined.”
   * You haven’t defined it, so it prints `"Macro code is not defined"`.

5. **Function Call**

   ```c
   print();
   ```

   * This calls whatever `print()` you’ve provided in `conditional_compliation.h` (or its corresponding `.c` file).
   * It demonstrates how you pull in code from another translation unit via headers.

6. **Commented “Use Cases”**

   * Toggling chunks of code for different hardware or client needs by defining or undefining macros.
   * Quickly reverting experimental changes by commenting out a `#define`.
   * Avoiding multiple-definition errors across several `.c` files by wrapping headers in `#ifndef…#define…#endif` guards.

Putting a **non‑`static`, non‑`inline`** function body in a header works fine if you have only one source file, but it breaks as soon as you add *any* other `.c` that also `#include "myfile.h"`:

```bash
# Following is valid when
# foo.c and bar.c are calling a function that is decalred and defined in myfile.h
foo.c ──┐
         ├─ includes myfile.h → each .o gets its own print()
bar.c ──┘
# The following error is observed
$ gcc -Wall -g -save-temps conditional_compilation.c main.c
/usr/bin/ld: a-main.o: in function `print':
/home/mpunix/c-programming/programming_concepts/the_preprocessor/conditional_compliation.h:6: multiple definition of `print'; a-conditional_compilation.o:/home/mpunix/c-programming/programming_concepts/the_preprocessor/conditional_compliation.h:6: first defined here
collect2: error: ld returned 1 exit status
```
>The best practice is to define function declarations in .h file, define the definition in .c file and then compile.

#### `undef` directive

- use to un define any directive that was defined earlier

#### `pragma` directive
- `#pragma startup func()` executes lines of code before main().
- `#pragma exit func()` executes lines of code before exiting the program.
- `#pragma warn`, supress specific warnings, like `-rvl` return val, `-par` parameter not used, `-rch` uncreachable code.
