
### Process Lifecycle and States

Diagram followed by theory part

![Image](https://github.com/user-attachments/assets/7f677eec-0398-4a42-80c8-16afb725ca65)

https://en.wikipedia.org/wiki/Scheduling_(computing)

- **New State** A process is in the new state when it is created (e.g., when a program is written and stored in secondary memory).
    - **Example:** Saving a C program to disk without executing it.
- **Ready State (Ready Queue)** The process is loaded into RAM and awaits CPU allocation.
    - **Management: who sends a process from new state to ready state**
        - **Long Term Scheduler:** Moves processes from secondary memory to the ready state to maintain multiprogramming.
            - RAM capacity limits the number of processes that can be in the ready state simultaneously.
            - If the ready queue is getting full then it is sent to **suspend ready** state.
                
- **Running State** The process that is currently being executed by the CPU.
    - **Dispatch:** **Short Term Scheduler:** Selects a process from the ready queue and dispatches it to the CPU.
    - it has some modes :
        - **Non Pre-emptive:** The process runs to completion without interruption.
        - **Pre-emptive:** The process may be interrupted by a higher-priority process or when its time quantum expires (e.g., in round robin scheduling).
            
- **Waiting (Blocked) State** The process is waiting for an event (typically an I/O request) to complete.
    - **Transition:** Once the I/O is finished, the process returns to the ready state.
    - Handled by Short term scheduler
 
- **Terminated State** The process has completed its execution and its resources are deallocated (returned to the system).
    - Handled by Long term scheduler, deallocation of memory.

- **Suspend Waiting state**: used by MTS, and moves process from waiting state to suspend waiting state.
    - MTS does this becuase waiting state queue is full.
- **Ready suspend state**: Used by MTS to move process from ready state to ready suspend state.
    - MTS does this because ready state is full

### Scheduling Types and Their Roles
- **Long Term Scheduler**
    - **Role:** Brings processes from secondary memory into the ready state.
    - **Purpose:** Ensures there is an adequate mix of processes in RAM, supporting multiprogramming.
- **Short Term Scheduler**
    - **Role:** Dispatches processes from the ready queue to the CPU.
    - **Key Concepts:**
        - Can operate in pre-emptive or non pre-emptive modes.
        - Responsible for context switching when a process is interrupted (e.g., due to time quantum expiration or higher-priority process arrival).
-   **Medium Term Scheduler**
    - **Role:** Manages the swapping of processes between RAM and secondary memory when RAM is full.
    - **Purpose:**
        - Prevents overload of the ready or waiting queues.
        - Swaps processes out (suspension) to free up memory, and later swaps them back in when space is available.
        - May prioritize processes based on criteria like frequency of use or priority.

### Additional Points

- **I/O Requests and Blocking:**
    - When a process requests I/O (e.g., reading a file), it is moved to the waiting state to allow the CPU to work on other tasks.
    - Once I/O is complete, the process returns to the ready state if resources permit.
- **Handling Overloads:**
    - If too many processes are waiting (e.g., the wait queue is full), the system may use techniques like suspending some processes (swapping them to secondary memory).
    - **Backing Store:** A temporary area in secondary memory where processes may reside if both ready and wait queues are full.
- **Practical Observation:**
   -   On UNIX/Linux systems, the `ps` command (with various options like `ps -e` or `ps -u`) displays process information including their state.
