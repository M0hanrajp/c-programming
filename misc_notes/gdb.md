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

Yes! You can use GDB to dig deeper into the segmentation fault and understand more about why it occurs. Here are some useful debugging techniques:

---

### **1. Use `backtrace (bt)` to see the call stack**

>Note: check scenarios.md file in strings/, it has a segfault debugging note.

After the segmentation fault occurs, type:

```gdb
(gdb) bt
```
This will show the sequence of function calls leading to the crash, helping you determine where exactly the issue occurs.
```bash

Program received signal SIGSEGV, Segmentation fault.
__strlen_evex () at ../sysdeps/x86_64/multiarch/strlen-evex.S:77
77      ../sysdeps/x86_64/multiarch/strlen-evex.S: No such file or directory.
(gdb) bt
#0  __strlen_evex () at ../sysdeps/x86_64/multiarch/strlen-evex.S:77
#1  0x00007ffff7e00d31 in __vfprintf_internal (s=0x7ffff7fa5780 <_IO_2_1_stdout_>, format=0x555555556008 "<< String[%u]  >> :: %8s at address :: %p stored in %p\n",
    ap=ap@entry=0x7fffffffde10, mode_flags=mode_flags@entry=0) at ./stdio-common/vfprintf-internal.c:1517
#2  0x00007ffff7dea79f in __printf (format=<optimized out>) at ./stdio-common/printf.c:33
#3  0x00005555555551de in display (input=0x7fffffffdf20) at array_of_pointers_to_strings.c:7
#4  0x0000555555555304 in main () at array_of_pointers_to_strings.c:39
```

---

### **2. Inspect memory addresses**
Use `print` (`p`) to check the address and contents of `str[0]`:

```gdb
(gdb) p str
$1 = {0x555555556008 "Welcome", 0x555555556010 "to", 0x555555556013 "jumanji"}
```
This confirms that `str[0]` points to a read-only memory section.

You can also check the specific address of `str[0]`:

```gdb
(gdb) p &str[0]
$2 = (char **) 0x7fffffffe220
```

To inspect memory at `str[0]`, use:

```gdb
(gdb) x/s str[0]
```
This will print the string at that memory location.
```gdb
(gdb) x/3s str[0]
0x555555556008: "Welcome"
0x555555556010: "to"
0x555555556013: "jumanji"
```
---

### **3. Check memory protections with `info proc mappings`**
To see if `str[0]` is in a read-only section, use:

```gdb
(gdb) info proc mappings
```
This lists memory regions and their permissions (`r`, `w`, `x`). If the segment containing `"Welcome"` is **read-only**, modifying it will cause a segmentation fault.

---

### **4. Use `disassemble` to examine compiled instructions**
To see the actual machine instructions where it crashes:

```gdb
(gdb) disassemble main
```
Look for the exact instruction that caused the segmentation fault.

---

### **5. Use `catch` to break on segmentation faults**
Instead of waiting for the crash, you can make GDB stop execution **before** the segmentation fault happens:

```gdb
(gdb) catch segfault
```
Then, run the program:

```gdb
(gdb) run
```
GDB will break as soon as the segmentation fault happens, allowing you to inspect values before the crash.

---

### **6. Examine Registers (`info registers`)**
If you suspect the segmentation fault is due to an invalid memory access, inspect CPU registers:

```gdb
(gdb) info registers
```
Check the **instruction pointer (RIP/eip)** and the **faulty memory address (RAX, RDX, etc.)**.

---

### **7. Step Into (`si`) and Step Over (`ni`)**
Use `si` (step into) to execute one assembly instruction at a time:

```gdb
(gdb) si
```
Or `ni` (next instruction) to step over function calls:

```gdb
(gdb) ni
```
This helps pinpoint the exact instruction causing the fault.

---

### **8. Use Valgrind for More Details**
If you have Valgrind installed, running:

```bash
valgrind --tool=memcheck --track-origins=yes ./your_program
```
will show **invalid memory accesses**, making debugging easier.

### **Memory Permissions in GDB (`r`, `w`, `x`)**
When you inspect memory regions in GDB using `info proc mappings`, you will see different permission flags:

| Permission | Meaning |
|------------|---------|
| `r` (Read) | The memory region can be read. |
| `w` (Write) | The memory region can be modified. |
| `x` (Execute) | The memory region contains executable code. |
| `-` (None) | No permission is granted for this region. |

#### **🔹 Common Debugging Scenarios**
| Scenario | Likely Cause |
|----------|-------------|
| **Segmentation Fault when modifying a string** | String literal is in `.rodata` (`r--p`). |
| **Stack overflow** | Exceeded stack limit (`rw-p`). |
| **Jumping to an invalid memory address** | Trying to execute non-executable memory (`rw-p`). |
| **Buffer overflow attack detection** | Writing past allocated memory in `rw-p`. |

#### **🔹 Summary**
| Flag  | Meaning | Example Memory Region |
|-------|---------|----------------------|
| `r--p` | Read-only | `.rodata` (String literals) |
| `rw-p` | Read & Write | Heap, Global Variables |
| `r-xp` | Read & Execute | Program Code (`.text`) |
| `rwxp` | Read, Write & Execute | JIT Code (Rare) |

#### **What Does "Private" Mean in GDB Memory Permissions?**

In GDB’s `info proc mappings` output, the **last character** in the permissions field (`r--p`, `rw-p`, `r-xp`, etc.) indicates whether the memory mapping is **private (`p`)** or **shared (`s`)**.

---

#### **🔹 Meaning of "Private" (`p`) vs. "Shared" (`s`)**
| Flag | Meaning |
|------|---------|
| `p` (Private) | Changes to this memory are **not** visible to other processes. |
| `s` (Shared) | Changes to this memory **are** visible to other processes. |

#### **🔹 Summary**
| Permission | Meaning | Example |
|------------|---------|---------|
| `r--p` | Read-only, private | String literals (`.rodata`) |
| `rw-p` | Read & write, private | Stack, heap, global variables |
| `r-xp` | Read & execute, private | Program code (`.text`) |
| `r--s` | Read-only, shared | Shared memory (`shm_open`) |
| `rw-s` | Read & write, shared | Shared memory between processes |

---

#### **🔹 Key Takeaway**
- **"Private" (`p`)** means **modifications are only visible to the process**.
- **"Shared" (`s`)** means **modifications are visible across multiple processes** (e.g., shared memory regions or shared libraries).
- **Most process memory is private (`p`)**, except for explicitly shared memory.
