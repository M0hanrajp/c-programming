## Notes for GDB

### Contents
- [How to use printf in GDB](#how-to-use-printf-in-gdb)

### [How to use printf in GDB](#how-to-use-printf-in-gdb)

You can use `printf` in GDB to print formatted output while debugging your program. This is useful for inspecting variables, expressions, or memory contents in a controlled format.

Here's how to use `printf` in GDB:

#### Basic Syntax:
```gdb
printf "format string", [arguments]
```

#### Examples:

#### 1. Printing Simple Values:
```gdb
(gdb) print some_variable          # Simple print
(gdb) printf "Value: %d\n", some_variable
```

#### 2. Printing Strings:
```gdb
(gdb) printf "String value: %s\n", some_string
```

#### 3. Printing Pointers:
```gdb
(gdb) printf "Pointer address: %p\n", some_pointer
```

#### 4. Printing Memory Content:
To print the content at a memory address:
```gdb
(gdb) printf "Memory content: %d\n", *((int *) 0xaddress)
```

#### 5. Printing an Array:
To print the elements of an array:
```gdb
(gdb) printf "Array[0]: %d, Array[1]: %d\n", array[0], array[1]
```

#### 6. Using Expressions:
You can also use expressions within `printf`:
```gdb
(gdb) printf "Sum: %d\n", some_variable + 10
```

#### Additional Tips:
- **String formatting:** GDB follows the standard C `printf` format specifiers (`%d`, `%f`, `%s`, `%p`, etc.).
- **Escape sequences:** You can use `\n` for a newline or `\t` for a tab.
- **Evaluate complex expressions:** Combine variables and calculations for detailed debugging.

---

#### Example Debugging Session:
1. **Start GDB and set a breakpoint:**
   ```bash
   gdb ./my_program
   (gdb) break main
   (gdb) run
   ```

2. **Inspect a variable with `printf`:**
   ```gdb
   (gdb) printf "Variable x: %d\n", x
   ```

3. **Continue execution:**
   ```gdb
   (gdb) continue
   ```
This approach helps you format the output more precisely than the default `print` command in GDB.

#### Print the type of variable

Use [`whatis <variable>` in gdb to get to know the type](https://github.com/M0hanrajp/c-programming/blob/188035dbc5b7d9b6857aef5314238186831238b1/programming_concepts/function_pointers/notes.md?plain=1#L19)
```bash
The following snip shows that display has address associated to it.
```bash
(gdb) p display
$1 = {void ()} 0x555555555149 <display>
(gdb) whatis display
type = void ()
(gdb) printf"%p", display
0x555555555149(gdb)
```

### Printing multidimensional array
```bash
(gdb)  p ((char (*)[4])input)[1]
$3 = "Git"
(gdb)  p ((char (*)[4])input)[0]
$4 = "Bit"
```
This is the solution for the issue :: `Cannot perform pointer math on incomplete types`
- Because input when it's declared as: `char input[rows][cols]` input is a pointer to an array of characters (i.e., char (*)[cols]).
- because cols is a variable length (provided at runtime), GDB treats the type as incomplete.
- This means GDB doesn't know the exact size of each element (cols) and cannot perform pointer arithmetic or dereference properly.
- Since cols is determined at runtime, the exact size of the row (cols * sizeof(char)) is unknown to GDB at compile time, making the type incomplete.

Yes, GDB provides several commands that can give a **detailed memory layout**, allowing you to inspect memory in various formats. Here's a list of useful commands and techniques for exploring memory in-depth:

---

### Examine Memory (`x` command)

The `x` command is very flexible and supports multiple formats and sizes. Here’s a breakdown of how to use it:

#### Syntax:
```bash
x/[count][format][size] <address>
```

#### Formats:
- `c`: Character (`char`)
- `d`: Decimal (`int`)
- `u`: Unsigned decimal
- `x`: Hexadecimal
- `o`: Octal
- `f`: Floating-point
- `s`: String (null-terminated)
- `i`: Instructions (disassemble)

#### Sizes:
- `b`: Byte (`1 byte`)
- `h`: Halfword (`2 bytes`)
- `w`: Word (`4 bytes`)
- `g`: Giant word (`8 bytes`)

---

#### Examples:
1. **Inspect memory as bytes**:
   ```bash
   x/16b input
   ```
   Displays 16 bytes from `input` as integers (in decimal).

2. **Inspect memory as characters**:
   ```bash
   x/16c input
   ```
   Displays memory content as characters.

3. **Inspect memory as strings**:
   ```bash
   x/s input
   ```
   Displays the null-terminated string starting at `input`.

4. **Inspect memory in hexadecimal**:
   ```bash
   x/16x input
   ```
   Displays 16 bytes from `input` as hexadecimal values.

5. **Inspect rows of the array**:
   To print each row as a string:
   ```bash
   x/s input
   x/s input+4  # Assuming each row is 4 bytes
   ```
```bash
#outputs
(gdb) x/16c input
0x7fffffffdf80: 66 'B'  105 'i' 116 't' 0 '\000'        71 'G'  105 'i' 116 't' 0 '\000'
0x7fffffffdf88: 0 '\000'        -36 '\334'      -64 '\300'      -101 '\233'     -128 '\200'     -35 '\335'      -55 '\311'      -125 '\203'
(gdb) x/16b input
0x7fffffffdf80: 66 'B'  105 'i' 116 't' 0 '\000'        71 'G'  105 'i' 116 't' 0 '\000'
0x7fffffffdf88: 0 '\000'        -36 '\334'      -64 '\300'      -101 '\233'     -128 '\200'     -35 '\335'      -55 '\311'      -125 '\203'
(gdb) x/s input
0x7fffffffdf80: "Bit"
(gdb) x/sb input
0x7fffffffdf80: "Bit"
(gdb) x/16x input
0x7fffffffdf80: 0x42    0x69    0x74    0x00    0x47    0x69    0x74    0x00
0x7fffffffdf88: 0x00    0xdc    0xc0    0x9b    0x80    0xdd    0xc9    0x83
```
---

### **2. Print Memory Regions (`info proc mappings`)**
This command shows the memory layout of the process, including stack, heap, and loaded segments:
```bash
info proc mappings

(gdb) info proc mappings
process 9153
Mapped address spaces:

          Start Addr           End Addr       Size     Offset  Perms  objfile
      0x555555554000     0x555555555000     0x1000        0x0  r--p   /home/mpunix/c-programming/programming_concepts/strings/rough
      0x555555555000     0x555555556000     0x1000     0x1000  r-xp   /home/mpunix/c-programming/programming_concepts/strings/rough
      0x555555556000     0x555555557000     0x1000     0x2000  r--p   /home/mpunix/c-programming/programming_concepts/strings/rough
      0x555555557000     0x555555558000     0x1000     0x2000  r--p   /home/mpunix/c-programming/programming_concepts/strings/rough
      0x555555558000     0x555555559000     0x1000     0x3000  rw-p   /home/mpunix/c-programming/programming_concepts/strings/rough
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
---

// explore below
### **3. Dump Memory to File**
You can save a memory dump to a file for offline inspection:
```bash
dump memory memory_dump.bin <start_address> <end_address>
```

Example:
```bash
dump memory array_dump.bin input input+16
```
You can then use tools like `xxd` or `hexdump` to analyze the binary file:
```bash
xxd array_dump.bin
```

### **5. Disassemble Memory as Instructions**
If the memory contains executable code, you can disassemble it to inspect:
```bash
disassemble <function_name>
```

Or directly disassemble memory:
```bash
x/10i <address>

(gdb) x/10i input
   0x7fffffffdf80:      imul   $0x7469,0x47(%rax,%r8,1),%esi
   0x7fffffffdf89:      fadd   %st,%st(0)
   0x7fffffffdf8b:      fwait
   0x7fffffffdf8c:      sbb    $0xc9,%ch
   0x7fffffffdf8f:      addl   $0x0,(%rcx)
   0x7fffffffdf92:      add    %al,(%rax)
   0x7fffffffdf94:      add    %al,(%rax)
   0x7fffffffdf96:      add    %al,(%rax)
   0x7fffffffdf98:      nop
   0x7fffffffdf99:      cmp    $0x7ffff7db,%eax
```
