## Compilation process

![Image](https://github.com/user-attachments/assets/5c8866c3-3187-461d-ba3c-15cf9aecbfec)

Following most information was taken from [here](https://stackoverflow.com/questions/77108297/breaking-down-the-c-compilation-process-into-preprocessing-compilation-assembl)

Also helpful [from a medium article](https://medium.com/@ganga.jaiswal/understanding-the-compilation-process-from-source-code-to-executable-ce9385b240f9)

### Preprocessor
```bash
# Who does it ?
- cpp (C preprocessor) is the program when gcc is invoked to compile a file.(Normally)
- Based on the log file, there is an internal preprocessor included inside cc1.

# What it does ?
- Remove comments, line splicing.
- Include header files, expands the macro.
- resolve conditional compilation directives.
- line control.

# What is the file type for this stage ?
- .c(input) file is converted to .i(output) file

# What are the commands to get the file type, or compile the program for this stage
- "gcc -E main.c -o main.i" option -E Stop after the preprocessing stage
- "cpp main.c -o main2.i" directly invoke the c preprocessor
```
- The input file for this stage is `*.c` file.
- It performs the following tasks:
  - **Removing comments :** It removes all the comments.
  - **Line Splicing** (`\`): The backslash `\` is used for line splicing, allowing you to break long lines of code into multiple lines for readability, are concatenated to form a single line.
  - **Header files inclusion:** For example, if the directive `#include <stdio.h>` is available in the program, then the preprocessor interprets the directive and replaces this directive with the content of the `/usr/include/stdio.h` file.
  - **Macro** expansion: A macro is a preprocessor directive that allows you to define a symbolic name or identifier for a sequence of code. They are used to create code snippets that can be easily reused and to introduce simple text substitutions. The most common use of macros in C is through the `#define` directive, which defines a macro. They can be constant macros, e.g., `#define BUFFER_SIZE 1024`, or function-like macros, e.g., `#define MAX(a, b) ((a) > (b) ? (a) : (b))`.
  - Resolve the **conditional compilation directives**: Using special preprocessing directives, you can include or exclude parts of the program according to various conditions. For example, `#ifdef DEBUG printf("Debugging is enabled.\n"); #endif`. Other conditional compilations are `#ifndef`, `#if`, `#elif`, `#else`. The preprocessor evaluates these conditions and determines whether the enclosed code should be included in the preprocessed output file.
  - **Line Control**: The `C` preprocessor informs the `C` compiler of the location in your source code where each token came from. A token in C can be defined as the smallest individual element of the C programming language that is meaningful to the compiler. It is the basic component of a C program. They can be Keywords (`double`, `if`, `while`, `return`, ...); Identifiers (variable and function names); Constants (`const int c_var = 20;`); Strings;  Special Symbols (`[]`, `()`, `{}`, `,`, `#`, ...); Operators (unary, binary, and ternary operators);
- In nutshell, the preprocessor expands the code.
- The output file is `*.i` or preprocessed file. This preprocessed file is the so-called [translation unit][22] (or more casually a compilation unit) and is the ultimate input to a `C` or `C++` compiler from which an object file is generated. Our static functions are visible only within this file.

### What type of errors are identified at this stage (Preprocessing errors)

| Category                    | Typical messages                                             |
|-----------------------------|--------------------------------------------------------------|
| **User diagnostics**        | `#error …`, `#warning …`                                     |
| **Lexical**                 | Unterminated comment/string/character literal                |
| **Directive syntax**        | Invalid/unrecognized directive, unterminated `#if`/`#endif`  |
| **Include errors**          | `No such file or directory`                                  |
| **Macro errors**            | Argument count mismatches, redefinition, token-paste errors  |

### Compiler
```bash
# Who does it ?
- gcc performs the compilation, but based on logs "cc1" program is invoked.

# What it does ?
- Front end, cc1 program
    - Takes the expanded source code and performs lexical analysis (groups characters into tokens).
    - tokens are organized into a parse tree (AST) for detecting errors.
    - generate IR (in SSA (static single assignment) form).
- Middle end,
    - Constant Folding & Propagation, Dead Code Elimination, Loop Transformations (unrolling, invariant motion)
    - Function Inlining, Common Subexpression Elimination.
- Back end,
    - Instruction selection, register allocation, instruction scheduling, output assembly code.

# What is the file type for this stage ?
- .i(input) file is converted to .s(output) file

# What are the commands to get the file type, or compile the program for this stage
- "gcc -S main.i -o main.s" -S: Stop after the stage of compilation proper.
```
In the **front end**, The compiler front end (invoked as cc1 in GCC) transforms the preprocessed code into an Intermediate Representation (IR)

- The input file for this stage is `*.i` file.
- **Lexical Analysis:** Scans the character stream and groups sequences into tokens (keywords, identifiers, constants, operators, and punctuators)
- **Syntax Analysis (Parsing)** Organizes tokens into a parse tree (or Abstract Syntax Tree, AST) based on the grammar of C, detecting syntax errors such as missing semicolons or unbalanced braces
- **Semantic Analysis** Performs type checking, ensures identifiers are declared before use, enforces scope rules, and resolves overloaded or built-in functions, emitting errors for type mismatches or undefined symbols
- **IR(Intermediate Representation) Generation** Converts the validated AST into a lower-level IR (often a tree or SSA form), which abstracts away syntactic details while preserving program semantics for optimization, lowers the AST into GIMPLE or another IR suitable for optimizations.

In the **middle end**, the compiler applies **machine-independent optimizations** on the IR to improve performance without considering CPU specifics:

- **Constant Folding & Propagation**  Precomputes constant expressions and replaces variables with known constant values
- **Dead Code Elimination** Removes code that can never execute (unreachable branches) or whose results are unused.
- **Loop Transformations** Applies loop unrolling, invariant code motion, and other techniques to reduce overhead in loops.
- **Inlining** Replaces calls to small functions with their bodies to eliminate call overhead.
- These optimizations yield an **optimized IR**, ready for target-specific code generation.

The **back end** maps the optimized IR to **assembly code**, performing CPU-specific tasks:

- **Instruction Selection:** maps RTL operations to target CPU instructions.
- **Register Allocation:** assigns temporaries to hardware registers, spilling as needed.
- **Instruction Scheduling:** reorders instructions to minimize stalls.
- **Assembly Emission:** outputs the .s file tailored to the target architecture.

Assembly code, often referred to as assembly language or just assembly, is a low-level programming language that uses mnemonic symbols (e.g., `MOV` for "move," `ADD` for "add") to represent CPU operations (the so-called opcode), thus making the code human-readable.

- This is exactly the same code you may have worked with when programming microcontrollers directly in assembly language (e.g., 8051 microcontroller).
- The output file is `*.s` or `*.asm` file.

Strictly speaking, this is the most crucial part of the compilation process and cannot be done by no one but the `gcc` compiler. When we use the `gcc` to directly generate the executable file (without breaking down all the steps), what happens under the hood is: The `gcc` delegates all other compilation steps (preprocessing, assembling, and linking) to `cpp`, `as`, and `ld`, respectively, and only performs the compilation step. By doing so, we, `C` developers, can be unworried in calling such tools as it is already done by `gcc`. Therefore, we can work with a unique command interface (the `gcc`) to perform all the compilation process.

### What type of errors are identified at this stage (Compile time errors)

| Category     | Error Type                                   | Example Source                | Typical Message                                                        | Phase                      |
| ------------ | -------------------------------------------- | ----------------------------- | ---------------------------------------------------------------------- | -------------------------- |
| **Lexical**  | Illegal character                            | `int x$ = 5;`                 | `error: invalid ‘$’ in program`                                        | Character → Token grouping |
|              | Malformed numeric constant                   | `int n = 12AB34;`             | `error: invalid digit ‘B’ in octal constant`                           |                            |
|              | Unterminated string literal                  | `printf("Hello);`             | `error: missing terminating '"' character`                             |                            |
|              | Unterminated character constant              | `char c = 'a;`                | `error: missing terminating '\'' character`                            |                            |
| **Syntax**   | Missing semicolon                            | `int x = 5`                   | `error: expected ';' before '}' token`                                 | Token → Parse tree         |
|              | Unbalanced delimiters (`{}` / `()` / `[]`)   | `if (x>0) { …`                | `error: expected '}' at end of input`                                  |                            |
|              | Unexpected or misspelled keyword             | `swich (x) {}`                | `error: unrecognized statement type 'swich'`                           |                            |
|              | Invalid construct (e.g. misplaced `case`)    | `switch(x) case 1: break;`    | `error: expected '{' after 'switch'`                                   |                            |
| **Semantic** | Undeclared identifier                        | `printf("%d", foo);`          | `error: 'foo' undeclared (first use in this function)`                 | AST → Semantic checks      |
|              | Conflicting/redefinition of types or symbols | `int f(); double f(int);`     | `error: conflicting types for 'f'`                                     |                            |
|              | Incompatible pointer or assignment types     | `int x = "hi";`               | `error: incompatible types when assigning to type 'int' from 'char *'` |                            |
|              | Non-lvalue in assignment                     | `3 = x;`                      | `error: lvalue required as left operand of assignment`                 |                            |
|              | Invalid operands to operators                | `a && 5` (if `a` non-Boolean) | `error: invalid operands to binary '&&'`                               |                            |
|              | Missing return in non-void function          | `int f() {}`                  | `warning: control reaches end of non-void function`                    |                            |
|              | Bit-field width exceeds type limits          | `struct S { int f:33; };`     | `error: width of bit-field 'f' exceeds its type`                       |                            |
|              | Overflow in constant expression              | `int x = 2147483648;`         | `warning: overflow in implicit constant conversion`                    |                            |

### Assembler
```bash
# Who does it ?
- "as" the GNU assembler program

# What it does ?
- Parse through the assembly code and generate machine code (platform specific machine code)
- group machine code into .text, .data, .bss, rodata section, relocation record section.
- not the final executable, memory address of functions and variables are resolved in linking phase.
    - Because external functions like printf() are not defined in the .o file.
    - Function definitions and variable declarations that are defined in another source file are not included in .o file.
    - so references to these functions are later resolved by linker.
    - the symbol table might have blanks due to functions and variable that were not found or referenced/defined in current source file.

# What is the file type for this stage ?
- .s(input) file (assembly) is converted to .o(output) file (object - machine code)

# What are the commands to get the file type, or compile the program for this stage
- "gcc -c main.s -o main.o"  -c Compile and assemble, but do not link.
- "as main.s -o main2.o" using the assembler directly
```
- If you use `gcc` to assemble the file, you must name the extension to `.s`. Otherwise, the `-c` option of `gcc` will try to link the file instead of assembling it.
- Each assembly instruction typically represents a single machine code instruction, which is a set of `0`'s and `1`'s. A part of this binary sequence is the opcode, while the remainder is usually memory addresses of variables or a numeric value. While Assembly is a programming language that is independent from the CPU architecture, the machine code it represents is specific to the target CPU. In other words, the machine code is highly platform-specific, meaning that it is tailored to a specific computer architecture and operating system. The machine instructions for one type of CPU will probably not run on a different CPU architecture without modification.
- The tool that converts Assembly code into machine code is called *assembler*, and its task is called *assembling*.
    * **Lexical Analysis & Macro Expansion**: tokenize input and expand macros into flat assembly code
    * **Location Counter Management**: maintain a location counter (LC) to assign addresses to instructions/data
    * **Symbol Table Construction**: record each label’s name → address mapping in the symbol table
    * **Directive Processing**: interpret assembler directives (e.g., `.text`, `.data`, `.globl`) to switch sections or set attributes
    * **Opcode Lookup & Encoding**: map mnemonics to their binary opcodes via the opcode table and emit bytes
    * **Operand Resolution**: encode registers, immediates, and internal symbol offsets; evaluate expressions 
    * **Section Organization**: group machine code and data into `.text`, `.data`, `.bss`, `.rodata`, etc. 
    * **Relocation Record Generation**: create relocation entries for external or yet-unknown symbols (e.g. R\_X86\_64\_PC32)
    * **Section Header Table Construction**: build metadata entries listing section names, sizes, alignments, and flags 
    * **Symbol & String Tables Embedding**: emit the `.symtab` (symbols) and `.strtab` (symbol names) for the linker
    * **Object File Emission**: write out ELF/COFF/Mach-O headers, sections, symbol/relocation tables into the relocatable `.o` file
- In low-level microcontroller programming, the assembler converts the assembly code into a binary sequence (typically represented in hexadecimal) and embed it into the microcontroller. The micro is now ready to run. 
- On the other hand, in `C`/`C++`, the assembler converts the assembly code into a `.o` intermediate file, known as object file. This intermediate representation contains machine-level code, that is, non-human-readable instructions that represent the functions and variables defined in your code. The `.o` file is not the final executable code, though. That is, it contains machine-readable instructions but cannot be directly executed by the operating system. This is because some information necessary for a file to be executable by the OS is missing, such as the memory addresses of functions and variables, which is resolved during linking phase.

[More on assembler](https://www.cs.princeton.edu/courses/archive/spr11/cos217/lectures/16AssemblersAndLinkers.pdf)

### What type of errors are identified at this stage (Assembler errors)

| **Category**              | **Example Error Message**                                                      | **Typical Cause**                                                          |
| ------------------------- | ------------------------------------------------------------------------------ | -------------------------------------------------------------------------- |
| **Syntax & Tokenization** | `Error: invalid char '[' beginning operand 2 '[esp+4]'`                        | Unexpected character in operand (e.g. missing `%` in AT\&T syntax)         |
|                           | `Error: syntax error; found ‘,’ but expected ‘(’`                              | Malformed instruction or bad inline-asm constraints                        |
|                           | `Error: junk at end of line: ‘,3’`                                             | Extraneous text after a valid instruction/directive                        |
| **Directive & Option**    | `Error: invalid directive`                                                     | Mistyped or unrecognized assembler directive                               |
|                           | `Error: unknown directive .intel_syntax`                                       | Using Intel syntax without appropriate option (e.g. `noprefix`)            |
|                           | `Fatal error: invalid -march= option: 'rv64imafdc'`                            | Unsupported architecture/machine option                                    |
| **Symbol & File**         | `Error: File number 1 already allocated`                                       | Reusing an internal file handle or macro reference improperly              |
|                           | `Error: Unassigned file number 2`                                              | Referencing a file number that was never opened                            |
|                           | `Error: symbol 'foo' undefined`                                                | Forward reference to a label or global not declared via `.extern`/`.globl` |
| **Operand & Encoding**    | `Error: invalid constant (87c0) after fixup`                                   | Immediate value out of range for the target ISA                            |
|                           | `Error: operands invalid for 'movdqa'`                                         | Operand types or addressing modes not allowed by the instruction           |
|                           | `Error: 'dword ptr [rip+eax]' is not a valid base/index expression`            | Unsupported register combination in addressing (x86\_64 RIP-relative)      |
| **Relocation**            | `Error: cannot represent T32_OFFSET_IMM relocation in this object file format` | Relocation type not supported by chosen object-file format                 |
|                           | `Error: relocation truncated to fit: R_X86_64_PC32 against '.text'`            | PC-relative branch or data reference out of allowed displacement range     |

| **Error Message**                                                                  | **Explanation / Typical Cause**                                                                                                                                |
|----------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **`relocation truncated to fit: R_X86_64_PC32 against '.text'`**                   | A PC-relative reference (e.g. a jump or data access) exceeds the 32-bit displacement range allowed by the ISA ([Stack Overflow][1]).                           |
| **`relocation truncated to fit: R_AVR_13_PCREL`**                                  | On AVR targets, a branch or call is out of range for the 12-bit PC-relative field ([avr-gcc-list.nongnu.narkive.com][2]).                                      |
| **`Error: attempt to .org backwards ignored`**                                     | The `.org` directive moved the location counter backwards, which assemblers disallow ([Binutils Narkive][3]).                                                  |
| **`Error: invalid char '[' beginning operand 2 '[esp+4]'`**                        | Unexpected character in an operand—often due to mixing Intel/AT\&T syntax or missing/register prefix (`%`) ([Stack Overflow][4]).                              |
| **`Error: syntax error; found ‘,’ but expected ‘(’`**                              | Malformed instruction syntax or bad inline-asm constraints generated by the compiler’s inline-asm expansion ([Reddit][5]).                                     |
| **`Error: invalid directive`**                                                     | The assembler encountered an unrecognized directive (e.g. a mistyped `.section` or an unsupported `.intel_syntax`) ([tigcc.ticalc.org][6]).                    |
| **`Error: undefined symbol 'foo'`**                                                | A symbol emitted by the compiler (e.g. for a static function) wasn’t defined in that translation unit, and wasn’t declared external ([porthos.ist.utl.pt][7]). |
| **`Error: cannot represent T32_OFFSET_IMM relocation in this object file format`** | A relocation type needed by the compiler (e.g. for Thumb-2 code) isn’t supported in the chosen object format ([Reddit][8]).                                    |
| **`Error: operands invalid for 'movdqa'`**                                         | The compiler emitted an SSE/AVX instruction with operand types or alignments the assembler doesn’t accept (e.g. misaligned memory) ([Arduino Forum][9]).       |
| **`Error: invalid constant (87c0) after fixup`**                                   | The compiler produced an immediate value out of range (e.g. a large offset) that the assembler can’t encode into the instruction ([porthos.ist.utl.pt][7]).    |
| **`as: unrecognized option '-mthumb-interwork'`**                                  | The compiler passed an assembler flag your installed `as` doesn’t support (version mismatch in binutils) ([Princeton Computer Science][10]).                   |
| **`Error: File number 1 already allocated` / `Unassigned file number 2`**          | Internal macro/file numbering conflicts in the assembler’s debug-info or `.file` directives auto-emitted by GCC ([porthos.ist.utl.pt][7]).                     |
| **`Error: cannot open CTF data file`**                                             | On FreeBSD, GCC may emit CTF (Compact Type Format) notes; if `ctfconvert` wasn’t installed, `as` can’t open the helper data ([GCC][11]).                       |
| **`fatal error: invalid -march= option: 'rv64imafdc'`**                            | GCC forwarded an unsupported architecture option to `as` for a RISC-V target your assembler version doesn’t recognize ([Reddit][5]).                           |
| **`Error: cannot find section `.rodata' for attribute section\`**                  | The compiler used `__attribute__((section(".rodata")))`; your assembler rejects out-of-order or mismatched section attributes ([MaskRay][12]).                 |

### Linker
```bash
# Who does it ?
- "ld" program
# What it does ?
- reads object files
- Resolution: Resolves references to make Symbol Table complete.
- Relocation: Uses Symbol Table and Relocation Records to patch code
- Linker writes resulting TEXT, RODATA, DATA, BSS sections to executable binary file (ELF in linux)
- assigns each section and symbol a virtual memory address. (inspect a.out and file.o to know the difference of memory address)

# What is the file type for this stage ?
- .o(input) file (machine code) is converted to .out(output) [or executable name] file (executable)

# What are the commands to get the file type, or compile the program for this stage
- "gcc main.o -o myprogram" get the executable
```
- The input file for this stage is `*.o` file.
- The linker merges all the object code from multiple modules into a single one. 
- If we are using a function from libraries, linker will link our code with that library function code.
    - All external functions and variables are found by the linker in their respective libraries and is combined to a single .object file.
- Combine different .data, .text, .bss section of different .o files into a single .o file.
- Readjust all the address of variables and functions when combing different object files
    - [Virtual address assigned by linker](https://stackoverflow.com/questions/55199546/does-a-linker-generate-absolute-virtual-addresses-when-linking)
- The `C` Standard Libraries are typically bundled with the `gcc` compiler. When you install `gcc` or any other `C` compiler, it includes the necessary standard libraries required to compile and link `C` programs. These libraries are an integral part of the compiler distribution. Therefore, they don't exist as a separate shared library file on your system and you won't find it by looking for a `.a` (static library) file. The shared libraries (the `.so` files) are not linked at compile time, but only in the runtime.
- For libraries outside the `C` standard library, you must to link it manually.
- The output is non-readable.

where `myprogram` is the executable file. Alternatively, you could directly use the `ld` command, but guess what? Although it is not the most crucial part, manually linking you object file to an executable file is **COMPLICATED AS HELL**. At this point you are literally twiddling bits to perfectly match with the hardware and OS specifications of your machine. You must understand stuffs such as computer organization and architecture, endianness, file types, dynamic linker/loader paths, BuildID, OS compatibility, magic numbers, stripped and non-stripped executable, etc... Thankfully, [`gcc` already knows all these stuffs and wonderfully does this hard work for us][4] by internally invoking `ld` with all the necessary options set. I suppose the `ld` options is out of the scope of this question.  It is also important to state that, in practice, is highly not recommended to directly use `ld`. You should use `gcc` (or other compiler) instead.

### What type of errors are identified at this stage (linker errors)

| **Error Message**                                                                   | **Typical Cause**                                                                                                                                         |
| ----------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `undefined reference to '<symbol>'`                                                 | The linker cannot find the definition for a declared function or variable—often because you forgot to link the object file or library that implements it. |
| `multiple definition of '<symbol>'`                                                 | The same symbol is defined in more than one object file or library (e.g., two non-`static` functions with the same name).                                 |
| `relocation truncated to fit: R_X86_64_PC32 against '.text'`                        | A PC-relative branch or data reference exceeds the 32-bit displacement range or uses an incompatible code model.                                          |
| `/usr/bin/ld: cannot find -l<library>`                                              | The specified library (e.g., `-lm`, `-lcudart`) isn’t installed, isn’t in the library search path, or the name/path is mistyped.                          |
| `collect2: ld returned 1 exit status`                                               | A generic failure indicator from `gcc`’s driver, meaning one or more preceding linker errors prevented successful linking.                                |
| `/usr/bin/ld: warning: skipping incompatible <file> when searching for -l<library>` | The linker found a library file of the wrong architecture (e.g., 32-bit vs. 64-bit) and skipped it, then continued searching.                             |
| `/usr/bin/ld: file not recognized: File format not recognized`                      | An object or archive file uses an unsupported or mismatched format (e.g., a.out vs. ELF, wrong endianness).                                               |
| `ld.lld: error: relocation R_X86_64_PC32 out of range`                              | The LLVM linker’s relocation overflow check detected a PC-relative reference beyond the supported range.                                                  |
| `/usr/bin/ld: unrecognized option '<opt>'`                                          | Passing an assembler/linker flag that the installed `ld` (or binutils version) doesn’t support.                                                           |

### Loader
```bash
# Who does it ?
- loader in the operating system

# What it does ?
- loads the executable from the disk into the primary memory(RAM) for execution.
- allocates the memory space to the executable module in the main memory.
- Transfers control to the beginning instruction of the program.
- Reading the file and creating an address space for the process.
- Page table entries for the instructions, data, and program stack are created and the register set is initialized.
- Then, Executes a jump instruction to the first instruction of the program which generally causes a page fault and 
  the first page of your instructions is brought into memory.

# What is the file type for this stage ?
- executable(ELF) file as the input, gives out program output (by OS)

# What are the commands to get the file type, or compile the program for this stage
- ./<executable-name> in a shell
```
### What type of errors are identified at this stage (program is executed)

Since program is running the following kind of errors might be reported

#### Runtime errors
| **Error Type**            | **Description**                                                         | **Examples**                                                    |                                             |
| ------------------------- | ----------------------------------------------------------------------- | --------------------------------------------------------------- | ------------------------------------------- |
| **Segmentation Faults**   | Accessing memory that the program doesn't have rights to.               | Dereferencing null or uninitialized pointers, buffer overflows. |                                             |
| **Division by Zero**      | Attempting to divide a number by zero, leading to undefined behavior.   | Calculating `a / 0`.                                            |                                             |
| **Memory Leaks**          | Failing to release allocated memory, leading to increased memory usage. | Allocating memory with `malloc` and not freeing it with `free`. |                                             |
| **Invalid Memory Access** | Accessing freed memory or writing to read-only memory segments.         | Using a pointer after freeing it, modifying string literals.    |                                             |
| **Stack Overflow**        | Exceeding the call stack limit, often due to infinite recursion.        | Recursive functions without a base case.                        | ([Vaia][1], [Wikipedia][2], [Wikipedia][3]) |

#### Logical errors
| **Error Type**             | **Description**                                                                | **Examples**                                  |                             |
| -------------------------- | ------------------------------------------------------------------------------ | --------------------------------------------- | --------------------------- |
| **Incorrect Algorithms**   | Implementing algorithms that don't solve the intended problem correctly.       | Using the wrong formula for calculations.     |                             |
| **Off-by-One Errors**      | Looping one time too many or too few, leading to incorrect results or crashes. | Using `<=` instead of `<` in loop conditions. |                             |
| **Incorrect Conditionals** | Using wrong logical conditions, leading to unintended code execution paths.    | Using `=` instead of `==` in `if` statements. | ([Wikipedia][1], [Vaia][2]) |

### Logs of compilation
```bash
$ gcc -Wall -g -v main.c
Using built-in specs.
COLLECT_GCC=gcc
COLLECT_LTO_WRAPPER=/usr/lib/gcc/x86_64-linux-gnu/11/lto-wrapper
OFFLOAD_TARGET_NAMES=nvptx-none:amdgcn-amdhsa
OFFLOAD_TARGET_DEFAULT=1
Target: x86_64-linux-gnu
Configured with: ../src/configure -v --with-pkgversion='Ubuntu 11.4.0-1ubuntu1~22.04' --with-bugurl=file:///usr/share/doc/gcc-11/README.Bugs --enable-languages=c,ada,c++,go,brig,d,fortran,objc,obj-c++,m2 --prefix=/usr --with-gcc-major-version-only --program-suffix=-11 --program-prefix=x86_64-linux-gnu- --enable-shared --enable-linker-build-id --libexecdir=/usr/lib --without-included-gettext --enable-threads=posix --libdir=/usr/lib --enable-nls --enable-bootstrap --enable-clocale=gnu --enable-libstdcxx-debug --enable-libstdcxx-time=yes --with-default-libstdcxx-abi=new --enable-gnu-unique-object --disable-vtable-verify --enable-plugin --enable-default-pie --with-system-zlib --enable-libphobos-checking=release --with-target-system-zlib=auto --enable-objc-gc=auto --enable-multiarch --disable-werror --enable-cet --with-arch-32=i686 --with-abi=m64 --with-multilib-list=m32,m64,mx32 --enable-multilib --with-tune=generic --enable-offload-targets=nvptx-none=/build/gcc-11-XeT9lY/gcc-11-11.4.0/debian/tmp-nvptx/usr,amdgcn-amdhsa=/build/gcc-11-XeT9lY/gcc-11-11.4.0/debian/tmp-gcn/usr --without-cuda-driver --enable-checking=release --build=x86_64-linux-gnu --host=x86_64-linux-gnu --target=x86_64-linux-gnu --with-build-config=bootstrap-lto-lean --enable-link-serialization=2
Thread model: posix
Supported LTO compression algorithms: zlib zstd
gcc version 11.4.0 (Ubuntu 11.4.0-1ubuntu1~22.04)
COLLECT_GCC_OPTIONS='-Wall' '-g' '-v' '-mtune=generic' '-march=x86-64' '-dumpdir' 'a-'
 /usr/lib/gcc/x86_64-linux-gnu/11/cc1 -quiet -v -imultiarch x86_64-linux-gnu main.c -quiet -dumpdir a- -dumpbase main.c -dumpbase-ext .c -mtune=generic -march=x86-64 -g -Wall -version -fasynchronous-unwind-tables -fstack-protector-strong -Wformat-security -fstack-clash-protection -fcf-protection -o /tmp/ccXwnHla.s
GNU C17 (Ubuntu 11.4.0-1ubuntu1~22.04) version 11.4.0 (x86_64-linux-gnu)
        compiled by GNU C version 11.4.0, GMP version 6.2.1, MPFR version 4.1.0, MPC version 1.2.1, isl version isl-0.24-GMP

GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
ignoring nonexistent directory "/usr/local/include/x86_64-linux-gnu"
ignoring nonexistent directory "/usr/lib/gcc/x86_64-linux-gnu/11/include-fixed"
ignoring nonexistent directory "/usr/lib/gcc/x86_64-linux-gnu/11/../../../../x86_64-linux-gnu/include"
#include "..." search starts here:
#include <...> search starts here:
 /usr/lib/gcc/x86_64-linux-gnu/11/include
 /usr/local/include
 /usr/include/x86_64-linux-gnu
 /usr/include
End of search list.
GNU C17 (Ubuntu 11.4.0-1ubuntu1~22.04) version 11.4.0 (x86_64-linux-gnu)
        compiled by GNU C version 11.4.0, GMP version 6.2.1, MPFR version 4.1.0, MPC version 1.2.1, isl version isl-0.24-GMP

GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
Compiler executable checksum: 50eaa2331df977b8016186198deb2d18
COLLECT_GCC_OPTIONS='-Wall' '-g' '-v' '-mtune=generic' '-march=x86-64' '-dumpdir' 'a-'
 as -v --gdwarf-5 --64 -o /tmp/ccSUzelK.o /tmp/ccXwnHla.s
GNU assembler version 2.38 (x86_64-linux-gnu) using BFD version (GNU Binutils for Ubuntu) 2.38
COMPILER_PATH=/usr/lib/gcc/x86_64-linux-gnu/11/:/usr/lib/gcc/x86_64-linux-gnu/11/:/usr/lib/gcc/x86_64-linux-gnu/:/usr/lib/gcc/x86_64-linux-gnu/11/:/usr/lib/gcc/x86_64-linux-gnu/
LIBRARY_PATH=/usr/lib/gcc/x86_64-linux-gnu/11/:/usr/lib/gcc/x86_64-linux-gnu/11/../../../x86_64-linux-gnu/:/usr/lib/gcc/x86_64-linux-gnu/11/../../../../lib/:/lib/x86_64-linux-gnu/:/lib/../lib/:/usr/lib/x86_64-linux-gnu/:/usr/lib/../lib/:/usr/lib/gcc/x86_64-linux-gnu/11/../../../:/lib/:/usr/lib/
COLLECT_GCC_OPTIONS='-Wall' '-g' '-v' '-mtune=generic' '-march=x86-64' '-dumpdir' 'a.'
 /usr/lib/gcc/x86_64-linux-gnu/11/collect2 -plugin /usr/lib/gcc/x86_64-linux-gnu/11/liblto_plugin.so -plugin-opt=/usr/lib/gcc/x86_64-linux-gnu/11/lto-wrapper -plugin-opt=-fresolution=/tmp/cceN2Nr1.res -plugin-opt=-pass-through=-lgcc -plugin-opt=-pass-through=-lgcc_s -plugin-opt=-pass-through=-lc -plugin-opt=-pass-through=-lgcc -plugin-opt=-pass-through=-lgcc_s --build-id --eh-frame-hdr -m elf_x86_64 --hash-style=gnu --as-needed -dynamic-linker /lib64/ld-linux-x86-64.so.2 -pie -z now -z relro /usr/lib/gcc/x86_64-linux-gnu/11/../../../x86_64-linux-gnu/Scrt1.o /usr/lib/gcc/x86_64-linux-gnu/11/../../../x86_64-linux-gnu/crti.o /usr/lib/gcc/x86_64-linux-gnu/11/crtbeginS.o -L/usr/lib/gcc/x86_64-linux-gnu/11 -L/usr/lib/gcc/x86_64-linux-gnu/11/../../../x86_64-linux-gnu -L/usr/lib/gcc/x86_64-linux-gnu/11/../../../../lib -L/lib/x86_64-linux-gnu -L/lib/../lib -L/usr/lib/x86_64-linux-gnu -L/usr/lib/../lib -L/usr/lib/gcc/x86_64-linux-gnu/11/../../.. /tmp/ccSUzelK.o -lgcc --push-state --as-needed -lgcc_s --pop-state -lc -lgcc --push-state --as-needed -lgcc_s --pop-state /usr/lib/gcc/x86_64-linux-gnu/11/crtendS.o /usr/lib/gcc/x86_64-linux-gnu/11/../../../x86_64-linux-gnu/crtn.o
COLLECT_GCC_OPTIONS='-Wall' '-g' '-v' '-mtune=generic' '-march=x86-64' '-dumpdir' 'a.'
```
