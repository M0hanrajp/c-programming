### What is a process ?
- In computing, a process is the instance of a computer program that is being executed by one or many threads.
- Depending on the OS, a process may be made up of multiple threads of execution that execute instructions concurrently.
    - Concurrency is an ability of the system to execute multiple tasks simulteanously through time sharing etc..
    - https://en.wikipedia.org/wiki/Concurrency_(computer_science)

![Image](https://github.com/user-attachments/assets/8294ea05-0745-4e06-b02c-468f94ede65b)

While a computer program is a passive collection of instructions typically stored in a file on disk, a process is 
the execution of those instructions after being loaded from the disk into memory.

Program vs. Process vs. Thread vs Scheduling, Preemption, Context Switching
![Image](https://github.com/user-attachments/assets/d5914447-4c65-40a7-9d5f-87a4672c3006)

In general, a computer system process consists of (or is said to own) the following resources:

- An image of the executable machine code associated with a program.
- Memory (typically some region of virtual memory); which includes the executable code, process-specific data (input and output), a call stack (to keep track of active subroutines and/or other events), and a heap to hold intermediate computation data generated during run time.
- Operating system descriptors of resources that are allocated to the process, such as file descriptors (Unix terminology) or handles (Windows), and data sources and sinks.
- Security attributes, such as the process owner and the process' set of permissions (allowable operations).
- Processor state (context), such as the content of registers and physical memory addressing. The state is typically stored in computer registers when the process is executing, and in memory otherwise.[1]
