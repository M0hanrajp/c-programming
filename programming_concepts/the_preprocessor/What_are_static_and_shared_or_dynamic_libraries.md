## What are static and dynamic/shared libraries 

- A **static library(.a)** is a library that can be linked directly into the final executable produced by the linker,
  it is contained in it and there is no need to have the library in the system where the executable will be deployed.
- A **shared library(.so)** is a library that is linked but not embedded in the final executable, so it will be loaded when 
  the executable is launched and needs to be present in the system where the executable is deployed.

https://stackoverflow.com/questions/9688200/difference-between-shared-objects-so-static-libraries-a-and-dlls-so
https://stackoverflow.com/questions/6181078/why-are-static-and-dynamic-linkable-libraries-different

https://medium.com/@896/dynamic-libraries-5828c54105c

![Image](https://github.com/user-attachments/assets/2483a132-084f-4368-bc91-b50caa2d9e03)

https://medium.com/@valentina.rua123/static-and-dynamic-library-in-c-fc4f168ae71d

![Image](https://github.com/user-attachments/assets/360e70f0-688c-4e93-8734-8494c725c569)

- https://medium.com/@valentina.rua123/what-happens-when-you-type-gcc-main-c-1ecc72516c22
- https://medium.com/@valentina.rua123/what-is-the-difference-between-static-and-dynamic-libraries-3091db1252d4


>What is the difference between the files that are named `.so` and `so.6`
```bash
# example
libc.a, libc.so, libc.so.6
```
| File    | Purpose                  | Typical Use  |
| ------- | ------------------------ | ------------ |
| `.so`   | Unversioned symlink      | Compile-time |
| `.so.6` | Versioned shared library | Runtime      |

| Stage   | Role of `.so`                                 | Role of `.so.6` (or `.so.x.y.z`)          |
| ------- | --------------------------------------------- | ----------------------------------------- |
| Compile | Used to **resolve symbols** (headers + stubs) | Not used directly                         |
| Runtime | Not used                                      | Real file **loaded into memory** and used |

executable only contains references, not the actual function code. The code is pulled in (mapped) at runtime from .so.6.

![Image](https://github.com/user-attachments/assets/872c9d5b-4691-481f-a2aa-0eec9e000d4a)

### 1. Listing object files in a static library (`.a`)

If you have a static archive, e.g. `libmylib.a`, you can use `ar`:

```bash
# List the members (object files) in the archive
ar t libmylib.a
```

Output might look like:

```
/lib/x86_64-linux-gnu$ ar t libc.a
init-first.o
libc-start.o
...
scanf.o
printf.o
```
---

### 2. Examining symbols in a static archive

To see which symbols are defined or undefined in each object, use `nm`:

```bash
# List all symbols (U = undefined, T = text/code, D = data, etc.)
nm libmylib.a

# If you only want defined (T) symbols:
nm --defined-only libmylib.a

# C-symbol demangling (for C++, but harmless in C):
nm -C libmylib.a
```
Output:
```bash
# example
foo.o:
00000000 T myfunc
         U printf

get-cpuid-feature-leaf.o:
0000000000000000 T __x86_get_cpuid_feature_leaf
                 U _dl_x86_cpu_features
0000000000000000 r feature.0
...
printf.o:
0000000000000000 T _IO_printf
0000000000000000 T __printf
                 U __vfprintf_internal
0000000000000000 T printf
```
if you need to search a particular .o file in the output of `nm lib.a` then use `nm libmylib.a | grep print`
```bash
fprintf.o:
0000000000000000 W _IO_fprintf
0000000000000000 T __fprintf
                 U __vfprintf_internal
0000000000000000 T fprintf
printf.o:
0000000000000000 T _IO_printf
0000000000000000 T __printf
                 U __vfprintf_internal
0000000000000000 T printf
snprintf.o:
0000000000000000 T __snprintf
                 U __vsnprintf_internal
0000000000000000 W snprintf
sprintf.o:
0000000000000000 T _IO_sprintf
0000000000000000 T __sprintf
                 U __vsprintf_internal
0000000000000000 T sprintf
asprintf.o:
0000000000000000 T ___asprintf
0000000000000000 T __asprintf
                 U __vasprintf_internal
0000000000000000 W asprintf
```

---

### 3. Inspecting a shared library (`.so`)

For shared libraries (“shared objects”), you can list exported symbols:

```bash
# Show dynamically exported (global) symbols
nm -D /lib/x86_64-linux-gnu/libc.so.6      # or wherever your libc.so.6 lives
...
$ nm -D libc.so.6
00000000000606f0 T _IO_printf@@GLIBC_2.2.5
```
>What is the meaning of `00000000000606f0 T _IO_printf@@GLIBC_2.2.5`

| Field              | Meaning                                                              |
| ------------------ | -------------------------------------------------------------------- |
| `00000000000606f0` | Virtual memory **address** of the symbol in the shared object        |
| `T`                | The symbol is in the **text section** (i.e., it's a global function) |
| `_IO_printf`       | The **symbol name** (function name in this case)                     |
| `@@GLIBC_2.2.5`    | The **version** of the symbol provided by the library                |

Or more portably with `readelf`:

```bash
# List all dynamic symbols
readelf -Ws /lib/x86_64-linux-gnu/libc.so.6

# Or show only the dynamic symbol table:
readelf -s /lib/x86_64-linux-gnu/libc.so.6

$ readelf -s libc.so.6

Symbol table '.dynsym' contains 3024 entries:
   Num:    Value          Size Type    Bind   Vis      Ndx Name
     0: 0000000000000000     0 NOTYPE  LOCAL  DEFAULT  UND
     1: 0000000000000000     0 FUNC    GLOBAL DEFAULT  UND [...]@GLIBC_PRIVATE (38)
...
  2922: 00000000000606f0   204 FUNC    GLOBAL DEFAULT   15 printf@@GLIBC_2.2.5
```
>What is the meaning of `2922: 00000000000606f0   204 FUNC    GLOBAL DEFAULT   15 printf@@GLIBC_2.2.5`

| Field                 | Meaning                                                                                                                                                                                               |
| --------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `2922`                | Symbol table **entry number**                                                                                                                                                                         |
| `00000000000606f0`    | Virtual **address** of the symbol (`printf`) in the shared object                                                                                                                                     |
| `204`                 | **Size** of the function in bytes                                                                                                                                                                     |
| `FUNC`                | The **type** of symbol — this is a **function**                                                                                                                                                       |
| `GLOBAL`              | **Linkage scope** — visible outside the shared object                                                                                                                                                 |
| `DEFAULT`             | **Visibility** — normal visibility for external linking                                                                                                                                               |
| `15`                  | **Section index** — refers to section number 15 (likely `.text`, the code section)                                                                                                                    |
| `printf@@GLIBC_2.2.5` | The **symbol name** and **version** info: <br>– `printf` is the function name <br>– `@@GLIBC_2.2.5` means this is the **default version** of `printf` exported by `libc.so.6` for the GLIBC 2.2.5 ABI |

---

### 4. Seeing dependencies

If you just want to know which libraries a shared object depends on:

```bash
ldd /lib/x86_64-linux-gnu/libc.so.6
$ ldd libc.so.6
        /lib64/ld-linux-x86-64.so.2 (0x00007f648faaf000)
        linux-vdso.so.1 (0x00007fffa45dc000)
```

---

### 5. Disassembling or dumping contents

If you want to see the actual machine code or sections:

```bash
# Disassemble all functions in a shared object
objdump -d /lib/x86_64-linux-gnu/libc.so.6

# Dump section headers, symbol table, etc.
objdump -h /lib/x86_64-linux-gnu/libc.so.6

# will have the assembly code
000000000005d680 <register_printf_function>:
   5d680:	f3 0f 1e fa          	endbr64 
   5d684:	41 54                	push   %r12
   5d686:	55                   	push   %rbp
   5d687:	53                   	push   %rbx
   5d688:	48 63 df             	movslq %edi,%rbx
   5d68b:	81 fb ff 00 00 00    	cmp    $0xff,%ebx
   5d691:	0f 87 b1 00 00 00    	ja     5d748 <register_printf_function+0xc8>
   5d697:	48 89 d5             	mov    %rdx,%rbp
   5d69a:	49 89 f4             	mov    %rsi,%r12
   5d69d:	31 c0                	xor    %eax,%eax
   5d69f:	ba 01 00 00 00       	mov    $0x1,%edx
   5d6a4:	f0 0f b1 15 24 f3 1b 	lock cmpxchg %edx,0x1bf324(%rip)        # 21c9d0 <lock>
   5d6ab:	00 
   5d6ac:	0f 85 7e 00 00 00    	jne    5d730 <register_printf_function+0xb0>
   5d6b2:	48 8b 15 0f f3 1b 00 	mov    0x1bf30f(%rip),%rdx        # 21c9c8 <__printf_function_table>
   5d6b9:	48 85 d2             	test   %rdx,%rdx
   5d6bc:	74 2a                	je     5d6e8 <register_printf_function+0x68>
   5d6be:	48 8b 05 eb e1 1b 00 	mov    0x1be1eb(%rip),%rax        # 21b8b0 <__printf_arginfo_table>
   5d6c5:	4c 89 24 da          	mov    %r12,(%rdx,%rbx,8)
   5d6c9:	45 31 e4             	xor    %r12d,%r12d
   5d6cc:	48 89 2c d8          	mov    %rbp,(%rax,%rbx,8)
   5d6d0:	31 c0                	xor    %eax,%eax
   5d6d2:	87 05 f8 f2 1b 00    	xchg   %eax,0x1bf2f8(%rip)        # 21c9d0 <lock>
   5d6d8:	83 f8 01             	cmp    $0x1,%eax
   5d6db:	7f 3b                	jg     5d718 <register_printf_function+0x98>
   5d6dd:	44 89 e0             	mov    %r12d,%eax
```

### Creating and using a library file
https://medium.com/@estebandelahoz/static-libraries-vs-dynamic-libraries-8496accd2c15
   - has good information on creating and using library file.
