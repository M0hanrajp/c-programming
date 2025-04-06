### system calls

![Image](https://github.com/user-attachments/assets/2725ca27-4300-4736-8354-6eec1a8f3870)

- In computing, a system call (syscall) is the programmatic way in which a computer program requests a service from the operating system on which it is executed. 
- This may include hardware-related services (for example, accessing a hard disk drive or accessing the device's camera), creation and execution of new processes, and communication with integral kernel services such as process scheduling. 
- System calls provide an essential interface between a process and the operating system.

An overview of Linux architecture, highlighting the system call interface.
![Image](https://github.com/user-attachments/assets/060d07b5-2c2c-4fd5-929c-b755eb911351)

### References.

- https://juliensobczak.com/inspect/2021/08/10/linux-system-calls-under-the-hood/
  - Has good overview of system calls vs library calls.
```bash
A library function is simply one of the functions that constitute the standard C library.
Some library functions are layered on top of system calls. For example, the fopen() library 
function uses the open system call to actually open a file.
```
  - provides difference between ABI(hardware dependent) and API(hardware independent).
```bash
Linux system calls are accessible using an application binary interface (ABI). 
An ABI defines how a routine is accessed in machine code (hardware-dependent) 
whereas an API defines a similar access in source code (hardware-independent).
```
An overview of how system call works ?
![Image](https://github.com/user-attachments/assets/aa592a89-fd97-4099-9793-0754f76ae8f9)


- https://www.sobyte.net/post/2021-12/whys-the-design-syscall-overhead/
- https://stackoverflow.com/questions/24036214/how-does-a-system-call-work (important)
- https://stackoverflow.com/questions/499188/how-is-the-system-call-in-linux-implemented (important)
- https://linux-kernel-labs.github.io/refs/pull/282/merge/index.html (some good lessons) (one of the best)
- Using strace to check system calls
```bash
# Summary of System Calls
$ strace -c touch test
-------------------------------------------------------------------
% time     seconds  usecs/call     calls    errors syscall
------ ----------- ----------- --------- --------- ----------------
  0.00    0.000000           0         1           read
  0.00    0.000000           0         6           close
  0.00    0.000000           0         2           fstat
  0.00    0.000000           0         8           mmap
  0.00    0.000000           0         3           mprotect
  0.00    0.000000           0         1           munmap
  0.00    0.000000           0         3           brk
  0.00    0.000000           0         6           pread64
  0.00    0.000000           0         1         1 access
  0.00    0.000000           0         1           dup2
  0.00    0.000000           0         1           execve
  0.00    0.000000           0         2         1 arch_prctl
  0.00    0.000000           0         3           openat
  0.00    0.000000           0         1           utimensat
------ ----------- ----------- --------- --------- ----------------
100.00    0.000000                    39         2 total

# Check Certain System Calls
$ strace  -e  trace=read touch test1.txt 
-------------------------------------------------------------------
read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\300A\2\0\0\0\0\0"..., 832) = 832
+++ exited with 0 +++
********************************************************************
$ strace -c -e  trace=read,close touch test2.txt 
-------------------------------------------------------------------
% time     seconds  usecs/call     calls    errors syscall
------ ----------- ----------- --------- --------- ----------------
  0.00    0.000000           0         1           read
  0.00    0.000000           0         6           close
------ ----------- ----------- --------- --------- ----------------
100.00    0.000000                     7           total
```
