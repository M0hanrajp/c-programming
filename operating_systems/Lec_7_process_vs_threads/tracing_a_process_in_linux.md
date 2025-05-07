# Hello World Program Lifecycle on Linux

## 1. Writing the Code  
We begin with a simple C source file `hello.c` that prints “Hello, World!” and returns 0. For example:  
```c
#include <stdio.h>
int main() {
    printf("Hello, World!\n");
    return 0;
}
```  
This code uses the standard C library `printf` function. It is saved as `hello.c` in our working directory.  

## 2. Compiling with GCC  
We compile the source into an executable using GCC. For clarity and debugging, add the `-g` flag and optionally `-save-temps` to keep intermediate files:  
```bash
$ gcc -g -o hello hello.c        # compile with debugging symbols
```  
This produces the binary `hello`. (If we used `-save-temps`, GCC would also output files like `hello.i` (preprocessed) and `hello.s` (assembly), showing how the code is transformed.) The result is a Linux ELF executable.

## 3. Inspecting the Binary  
Before running, we can examine the binary with tools:

- **`file`**: Identifies the binary format. For example, on x86-64 Linux:  
  ```bash
  $ file hello
  hello: ELF 64-bit LSB executable, x86-64, version 1 (SYSV), dynamically linked, [...]
  ```  
  This output indicates an ELF 64-bit executable for Linux (LSB = least significant byte first), using shared libraries ([c - How to create a binary executable for 32 bit gcc machine from my 64 bit gcc machine? - Stack Overflow](https://stackoverflow.com/questions/41035585/how-to-create-a-binary-executable-for-32-bit-gcc-machine-from-my-64-bit-gcc-mach#:~:text=use%20file%20to%20check%20it)).  

- **`ldd`**: Lists dynamic library dependencies. Example output might include:  
  ```bash
  $ ldd hello
          linux-vdso.so.1 (0x00007ffff7ffd000)
          libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (...)
          /lib64/ld-linux-x86-64.so.2 => /lib64/ld-linux-x86-64.so.2 (...)
  ```  
  This shows our program links against `libc.so.6` (the C standard library) and the dynamic linker `ld-linux-x86-64.so.2` ([Linux ldd Command with Practical Examples | LabEx](https://labex.io/tutorials/linux-linux-ldd-command-with-practical-examples-422757#:~:text=Example%20output%3A)).  (Any other shared libraries would be listed here.)  

- **`objdump` or **`readelf`** (optional)**: These can disassemble or show headers, but for a “Hello World” they are not strictly needed for beginners.

## 4. Running the Program (Process Creation)  

1. **Shell Forks and Execs:** When we type `./hello` at the shell prompt, the shell creates a new process.  In Unix shells (e.g. bash), this typically happens by a `fork()` system call. The child process then invokes `execve("./hello", ...)` to replace its memory with our program.  (If the shell simply called `exec` without forking, the shell itself would be replaced and the terminal would close.  That’s why shells fork first ([command line - Why do shells call fork()? - Ask Ubuntu](https://askubuntu.com/questions/428458/why-do-shells-call-fork#:~:text=When%20you%20call%20an%20,process%20you%20want%20to%20run)).)

2. **`execve` System Call:** Once the shell child calls `execve`, the kernel loads the `hello` executable into memory.  In `strace`, we would see a line like:  
   ```
   execve("./hello", ["./hello"], [/* 62 vars */]) = 0
   ```  
   indicating our program has started ([system calls - Strace Hello World program - Unix & Linux Stack Exchange](https://unix.stackexchange.com/questions/160578/strace-hello-world-program#:~:text=execve%28,%3D%200)). Immediately after `execve`, execution jumps to the ELF entry point (usually a runtime start routine).

3. **Dynamic Loader (`ld.so`) Runs:** Because the program is dynamically linked, control first goes to the dynamic loader (part of libc).  The loader allocates memory (for example, it might call `brk(0)` and `mmap` to set up the heap) ([system calls - Strace Hello World program - Unix & Linux Stack Exchange](https://unix.stackexchange.com/questions/160578/strace-hello-world-program#:~:text=This%20is%20your%20program%20starting,is%20from%20the%20dynamic%20loader)).  For instance, `strace` shows:  
   ```
   brk(0) = 0x85a5000
   mmap2(NULL, 4096, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0xb774f000
   ```  
   These allocate and adjust the program break (heap) for malloc and other uses ([system calls - Strace Hello World program - Unix & Linux Stack Exchange](https://unix.stackexchange.com/questions/160578/strace-hello-world-program#:~:text=This%20is%20your%20program%20starting,is%20from%20the%20dynamic%20loader)).

4. **Loading Shared Libraries:** The dynamic loader then locates and loads required shared libraries.  For example, it will `open` the C library (`libc.so.6`), read its ELF header, and `mmap` its segments.  An excerpt from `strace` might show:  
   ```
   open("/usr/lib/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
   read(3, "\177ELF...", 512) = 512
   fstat64(3, {st_size=2035943, ...}) = 0
   mmap2(NULL, 1801892, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0xb7573000
   mmap2(0xb7724000, 20480, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1b0000) = 0xb7724000
   close(3) = 0
   ```  
   This shows the loader mapping the executable code (`PROT_EXEC`) and data (`PROT_READ|PROT_WRITE`) of libc into memory ([system calls - Strace Hello World program - Unix & Linux Stack Exchange](https://unix.stackexchange.com/questions/160578/strace-hello-world-program#:~:text=open%28,MAP_DENYWRITE%2C%203%2C%200x1b0000%29%20%3D%200xb7724000)). 

5. **Initial Thread Starts:** At this point the process is fully loaded.  The kernel creates the *main thread* (initial thread) to run the program, with its instruction pointer set to the entry point (`_start`).  Conceptually, one can think of the OS doing:  
   ```
   newProcess()               # allocate process structures
   loadProgram(program file)  # load ELF segments (text, data, etc)
   newThread(initialPc="_start")  # start the first thread at _start
   ```  
   (This pseudocode is illustrated in Linux discussions ([c - What is __libc_start_main and _start? - Stack Overflow](https://stackoverflow.com/questions/62709030/what-is-libc-start-main-and-start#:~:text=def%20spawnProg,make%20thread%20to%20run%20it)).)  In Linux, threads are implemented as lightweight processes; here only one thread (the main thread) exists, and its thread ID equals the process ID. 

6. **Runtime Startup (`_start` and `__libc_start_main`):** The `_start` code (in the C runtime) sets up the C environment.  Typically it calls `__libc_start_main`, which in turn calls our `main(argc, argv)`.  For example, a simplified startup sequence is:  
   ```
   _start:
       call __libc_start_main    ; sets up C runtime and calls main
       call _main               ; invoke our main()
       call __libc_stop_main    ; cleanup after main returns
       jmp __exit               ; system exit
   ```  
   (This pattern is described in low-level startup documentation ([c - What is __libc_start_main and _start? - Stack Overflow](https://stackoverflow.com/questions/62709030/what-is-libc-start-main-and-start#:~:text=_start%3A%20%20%3B%3B%20Weave%20magic,Tear%20down%20C%20environment)).)  By the time `main` runs, the arguments `argc, argv` have been placed on the stack by the loader ([c - What is __libc_start_main and _start? - Stack Overflow](https://stackoverflow.com/questions/62709030/what-is-libc-start-main-and-start#:~:text=,other%20ways%3B%20and%20so%20on)).

## 5. Memory Layout of the Process  
Once running, the process’s address space has a well-defined layout ([Chapter 6. Processes - Shichao's Notes](https://notes.shichao.io/tlpi/ch6/#:~:text=,of%20all%20of%20the%20processes)) ([Chapter 6. Processes - Shichao's Notes](https://notes.shichao.io/tlpi/ch6/#:~:text=,is%20called%20the%20program%20break)):

- **Text segment:** The machine code of the program (`hello` and shared libraries) resides here. It is typically read-only and may be shared among processes running the same executable ([Chapter 6. Processes - Shichao's Notes](https://notes.shichao.io/tlpi/ch6/#:~:text=,of%20all%20of%20the%20processes)).  
- **Initialized data segment:** Global/static variables with initial values would be here (none in our simple program).  
- **BSS segment:** Global/static variables without explicit initialization live here (zero-initialized) ([Chapter 6. Processes - Shichao's Notes](https://notes.shichao.io/tlpi/ch6/#:~:text=,that%20are%20uninitialized%20is%20that)).  
- **Heap:** Grows upward from the end of BSS. Managed by `malloc`/`free` (which use `brk` or `mmap`). For our program, the heap was set up by the loader, but we didn’t explicitly allocate any data.  
- **Stack:** Grows downward from a high address. Used for function call frames, local variables, return addresses, etc. For example, calling `main` creates a stack frame containing its return address and arguments (though on x86-64, arguments are typically passed in registers). The stack pointer register `RSP` points to the top of the stack. In GDB you can inspect `rsp` (and `rip`, the instruction pointer) with `info registers`.  

We can observe this layout at runtime via `/proc` or debugging:  
```bash
$ cat /proc/<pid>/maps
```  
This shows address ranges for text (rx), data (rw), heap (rw, growable), and stack (rw, at high addresses) among others. For example, you might see something like:  
```
00400000-00401000 r-xp 00000000 08:01 123456 /home/user/hello
00601000-00602000 rw-p 00001000 08:01 123456 /home/user/hello
...
7ffffffde000-7ffffffe0000 rw-p 00000000 00:00 0          [stack]
```
which corresponds to the compiled code (`r-xp` = read-exec) and data segments of `hello`, plus the stack area.

## 6. Running in GDB (Registers and Stack)  
Using GDB gives insight into registers and stack frames. For example:  
```bash
$ gdb hello
(gdb) break main
(gdb) run
Breakpoint 1, main (argc=1, argv=0x7fffffff...) at hello.c:4
(gdb) info registers
rax            0x0                 0
rbx            0x0                 0
...
rsp            0x7fffffffdc90      0x7fffffffdc90   # stack pointer
rip            0x400546            <main+...>       # instruction pointer
...
```
Here `rip` shows the address of the next instruction in `main`, and `rsp` shows the current stack pointer. You can also inspect stack contents (`x/32x $rsp`) and use `backtrace` to see the call stack (e.g., frame 0 is `main`).  In a simple Hello World, the call stack will show `main` and possibly one frame in the startup code.

## 7. Execution (System Calls and I/O)  

When `main()` runs, it executes `printf("Hello, World!\n")`. This call eventually results in a system call to write to standard output. Tracing with **`strace`** illustrates this:  
```bash
$ strace -o trace.txt ./hello
```
Looking at `trace.txt`, the final system calls will include something like:  
```
write(1, "Hello, World!\n", 14) = 14
exit_group(0)               = ?
+++ exited with 0 +++
```  
Here `write(1, "Hello, World!\n", 14)` is the syscall writing our message to file descriptor 1 (standard output).  The return value `14` is the number of bytes written.  Immediately after printing, the program calls `exit`, which in Linux appears as `exit_group(0)` in strace. The `?` indicates the return (never actually returns since the process ends) ([system calls - Strace Hello World program - Unix & Linux Stack Exchange](https://unix.stackexchange.com/questions/160578/strace-hello-world-program#:~:text=0xb7571000%20write%281%2C%20,exited%20with%200)). This sequence matches what is seen in examples:  
```
write(1, "Hello World!\n", 13)          = 13
exit_group(0)                           = ?
```  
after which the program terminates normally ([system calls - Strace Hello World program - Unix & Linux Stack Exchange](https://unix.stackexchange.com/questions/160578/strace-hello-world-program#:~:text=write%281%2C%20,%3D)). (In this snippet, `13` bytes were written, accounting for the exclamation and newline.)

We can also trace library calls with **`ltrace`**. For example:  
```bash
$ ltrace ./hello
__libc_start_main(0x4006d6, 1, 0x7fffffffddc8, 0x400740 <unfinished ...>
printf("Hello, World!\n")               = 14
__libc_start_main(0x4006d6, 1, 0x7fffffffddc8, 0x400740 <unfinished ...>
+++ exited with 0 +++
```  
This shows the call to `printf` in the C library (here returning 14 characters written). (Actual output may vary slightly; the key point is that `ltrace` reports the call to `printf` and its return.)

## 8. Observing the Process in Linux  

- **`ps` / `top`:** While our program runs, it briefly appears in process listings. For example, one might do:  
  ```bash
  $ ps -f
  UID        PID  PPID  C STIME TTY          TIME CMD
  user     34567 34560  0 12:34 pts/0    00:00:00 ./hello
  ```  
  Here `PID` is the process ID and `PPID` (parent PID) is the shell’s PID.  In `top` or `htop`, the process would briefly appear and then disappear when it exits. For a very short-lived program like this, you may need to insert a `sleep()` call to observe it in `top`.  

- **`/proc` Files:** During execution you can inspect `/proc/<pid>/status` for memory and thread info, `/proc/<pid>/statm` for memory usage, etc. For example, `/proc/<pid>/status` shows `VmSize`, `VmRSS`, and `Threads: 1` (since we only have the main thread).  `/proc/<pid>/maps` (as shown above) lists memory segments.  

- **Context Switching:** If the system is busy, the kernel may preempt (context switch) the running thread on the CPU. On a multi-core machine, other processes may run concurrently. But our Hello World is so brief that it usually runs to completion on one core. In general, the Linux scheduler moves threads in and out of running state; you might see the process transition between states in `ps` (R for running, S for sleeping, etc.).

## 9. Termination and Cleanup  

After `exit(0)`/`exit_group(0)`, the program’s thread ends, and the kernel destroys the process. All user-space memory (text, data, heap, stack) is freed, open file descriptors (stdout, etc.) are closed, and the exit status is returned to the parent (shell). In `strace` we see `+++ exited with 0 +++` indicating normal exit. Control returns to the shell prompt.

Throughout this lifecycle, the key steps are **fork** (by the shell), **execve** (load program), dynamic **linking/loading**, **running `main`**, making **syscalls** (`write`, `exit`), and **process termination**.  Tools like `file`, `ldd`, `strace`, `ltrace`, `gdb`, and examining `/proc` illuminate each stage. By following these steps and observing the sample outputs above, a learner can trace a simple C program from source code to execution and termination on Linux.  

**Sources:** Concepts and examples are based on Linux process documentation and common tracing outputs ([c - How to create a binary executable for 32 bit gcc machine from my 64 bit gcc machine? - Stack Overflow](https://stackoverflow.com/questions/41035585/how-to-create-a-binary-executable-for-32-bit-gcc-machine-from-my-64-bit-gcc-mach#:~:text=use%20file%20to%20check%20it)) ([Linux ldd Command with Practical Examples | LabEx](https://labex.io/tutorials/linux-linux-ldd-command-with-practical-examples-422757#:~:text=Example%20output%3A)) ([system calls - Strace Hello World program - Unix & Linux Stack Exchange](https://unix.stackexchange.com/questions/160578/strace-hello-world-program#:~:text=execve%28,%3D%200)) ([system calls - Strace Hello World program - Unix & Linux Stack Exchange](https://unix.stackexchange.com/questions/160578/strace-hello-world-program#:~:text=open%28,MAP_DENYWRITE%2C%203%2C%200x1b0000%29%20%3D%200xb7724000)) ([Chapter 6. Processes - Shichao's Notes](https://notes.shichao.io/tlpi/ch6/#:~:text=,of%20all%20of%20the%20processes)) ([Chapter 6. Processes - Shichao's Notes](https://notes.shichao.io/tlpi/ch6/#:~:text=,is%20called%20the%20program%20break)) ([system calls - Strace Hello World program - Unix & Linux Stack Exchange](https://unix.stackexchange.com/questions/160578/strace-hello-world-program#:~:text=0xb7571000%20write%281%2C%20,exited%20with%200)) ([command line - Why do shells call fork()? - Ask Ubuntu](https://askubuntu.com/questions/428458/why-do-shells-call-fork#:~:text=When%20you%20call%20an%20,process%20you%20want%20to%20run)) ([c - What is __libc_start_main and _start? - Stack Overflow](https://stackoverflow.com/questions/62709030/what-is-libc-start-main-and-start#:~:text=def%20spawnProg,make%20thread%20to%20run%20it)) ([c - What is __libc_start_main and _start? - Stack Overflow](https://stackoverflow.com/questions/62709030/what-is-libc-start-main-and-start#:~:text=_start%3A%20%20%3B%3B%20Weave%20magic,Tear%20down%20C%20environment)).
