### fork()

`System call` `fork()` is used to create processes. 
- It takes no arguments 
- and returns a process ID. 
The purpose of fork() is to create a new process, which becomes the child process of the caller. 
After a new child process is created, both processes will execute the next instruction following the fork() system call. 
Therefore, we have to distinguish the parent from the child. This can be done by testing the returned value of fork():

- If fork() returns a negative value, the creation of a child process was unsuccessful.
- [a] fork() returns a zero to the newly created child process.
- [b] fork() returns a positive value, the process ID of the child process, to the parent. 
  - remeber [a] and [b] are happening parallel

https://man7.org/linux/man-pages/man2/fork.2.html

### Few more things about fork()

The returned process ID is of type pid_t defined in sys/types.h. Normally, the process ID is an integer. 

Moreover, a process can use function getpid() to retrieve the process ID assigned to this process.

- Therefore, after the system call to fork(), a simple test can tell which process is the child. 
- Please note that Unix will make an exact copy of the parent's address space and give it to the child. 
- Therefore, the parent and child processes have separate address spaces. (but they are identical)

- if the call to fork() is executed successfully, Unix will
  - make two identical copies of address spaces, one for the parent and the other for the child.
  - Both processes will start their execution at the next statement following the fork() call. In this case, both processes will start their execution at the assignment statement as shown below:
  ![Image](https://github.com/user-attachments/assets/d80fea48-9b6a-4f1c-8458-ccec219d3557)

Since both processes have identical but separate address spaces, those variables initialized before the fork() call have the same values in both address spaces.

Since every process has its own address space, any modifications will be independent of the others. 
In other words, if the parent changes the value of its variable, the modification will only affect the 
variable in the parent process's address space. 

Other address spaces created by fork() calls will not be affected even though they have identical variable names.

### Q: How printf() statement affects parent and child process during execution ?
- printf() will group the output of a process together.
- output will not be send to screen immediately.
- You can use write() call to send output to screen, the scheduling of the ouptut will be done by the CPU.
- More https://www.csl.mtu.edu/cs4411.ck/www/NOTES/process/fork/create.html

### Q: when fork() is called and it let's say it's successful but it does not return 0, a non zero is returned, so is the child still created ?
- System call fork() returns the child process ID to the parent and returns 0 to the child process.
- https://www.csl.mtu.edu/cs4411.ck/www/NOTES/process/fork/create.html
- So the above question is irrelevant, which was my doubt, when fork() is called we have two processes which are executing statements simultaneously

(For better understanding check below, this is executed in [1]_understanding_fork.c)
When the main program executes fork(), an identical copy of its address space, including the program and all data, is created. System call fork() returns the child process ID to the parent and returns 0 to the child process. The following figure shows that in both address spaces there is a variable pid. The one in the parent receives the child's process ID 3456 and the one in the child receives 0.

![Image](https://github.com/user-attachments/assets/e19dba1f-5f72-401d-a568-ab3266b3af52)

Now both programs (i.e., the parent and child) will execute independent of each other starting at the next statement:
In the parent, since pid is non-zero, it calls function ParentProcess(). On the other hand, the child has a zero pid and calls ChildProcess() as shown below:

![Image](https://github.com/user-attachments/assets/76eabdc7-4e9a-4ef4-a06f-78b0a48509c9)

Due to the fact that the CPU scheduler will assign a time quantum to each process, the parent or the child process will run for some time before the control is switched to the other and the running process, if you want to see this then keep a loop and execute till some x time to see the switching.

### Q: What are the cases in which child process becomes a zombie when fork() is called in parent process
- Need to explore
  - Zombie Process: A process which has finished the execution but still has entry in the process table to report to its parent process is known as a zombie process. 
    - A child process always first becomes a zombie before being removed from the process table. The parent process reads the exit status of the child process which reaps off the child process entry from the process table.
  - Orphan Process: A process whose parent process no more exists i.e. either finished or terminated without waiting for its child process to terminate is called an orphan process.
- https://medium.com/@akshat.mistry/zombie-vs-orphan-process-21643ec75558

### Q: What does identical address space mean when a child process is created by forking the parent process
- from 2_understanding_indetical_address_space_between_child_parent.c
- from https://www.csl.mtu.edu/cs4411.ck/www/NOTES/process/fork/create.html
>Modifications in a process does not affect it's forked process
- Both processes start their execution right after the system call fork(). 
- Since both processes have identical but separate address spaces, those variables initialized before the fork() 
  call have the same values in both address spaces. 
- Since every process has its own address space, any modifications will be independent of the others. 
- In other words, if the parent changes the value of its variable, the modification will only affect the
  variable in the parent process's address space. 
- Other address spaces created by fork() calls will not be affected even though they have identical variable names.

>Modifications in a process does not affect it's forked process (Need to understand why and how this happens)
 * // consider reading below links to understand more on how the memory space is created/assigned by OS
 * https://stackoverflow.com/questions/63831450/why-doesnt-address-change-in-forked-process?rq=3
 * https://stackoverflow.com/questions/27486873/fork-system-call-and-memory-space-of-the-process?rq=3
 * https://stackoverflow.com/questions/9724473/how-the-memory-is-mapped-when-fork-is-used?rq=3
 * https://stackoverflow.com/questions/8353641/parent-and-child-address-space-confusion?rq=3
 * // has diagram
 * https://stackoverflow.com/questions/7253659/why-the-address-of-variable-of-child-process-and-parent-process-is-same?rq=3
 * https://stackoverflow.com/questions/5365580/fork-same-memory-addresses?rq=3
 * https://unix.stackexchange.com/questions/207918/what-does-it-mean-fork-will-copy-address-space-of-original-process
