### Process vs threads

```
+---------------------------------------------+---------------------------------------------+
| Process                                     | Threads (User Level)                        |
+---------------------------------------------+---------------------------------------------+
| 1) System Calls involved in Process         | 1) There is no System Call involved         |
+---------------------------------------------+---------------------------------------------+
| 2) OS treats different processes differently| 2) All User Level threads treated as Single |
|                                             |    task for OS                              |
+---------------------------------------------+---------------------------------------------+
| 3) Different processes have different       |                                             |
|    copies of Data, Files, Code              | 3) Threads share same copy of code and data |
|                                             |                                             |
+---------------------------------------------+---------------------------------------------+
| 4) Context switching is slower              | 4) Context switching is faster              |
+---------------------------------------------+---------------------------------------------+
| 5) Blocking a process will not block others | 5) Blocking a thread will block entire      |
|                                             |    process                                  |
+---------------------------------------------+---------------------------------------------+
| 6) Independent                              | 5) Interdependent                           |
|                                             |                                             |
+---------------------------------------------+---------------------------------------------+
```
Sure! Here are the notes based on the video content:

---

### Differences Between Process and Threads

**Introduction:**
- Processes are considered heavy-weight tasks.
- Threads are considered light-weight tasks.

**Environment:**
- Multi-processing and multi-tasking environment.
- Multiple processes or tasks run parallel at the same time.
- Typically, systems have one CPU.

**WE can proceed with following**
- Create more child processes within a process.
- Perform multi-threading.

**Real-life Example:**
- Task: Move a duster from one place to another.
- CPU/Processor can:
  - Create a new process (clone) to perform the task.
  - Create an extra hand (thread) to perform the task.

**Process Components:**
- Data, code, stack, registers.
- Child process: exact copy of the parent process (clone).
  - Own data, same code, own stack, and registers.

**Fork System Call:**
- Creates a child process of an existing process.
- Child process is an exact copy (clone) of the parent process.
- Involves system calls and kernel intervention.
- Uses the `fork` system call to generate a new process.

**Threads:**
- Creating threads within a process divides the process into multiple threads.
- Threads share the same data and code, reducing overhead.
- Each thread has its own stack and registers.
- No system calls are involved in creating threads.
- Threads are created by application programs (user-level threads).
- Kernel is not involved in thread creation at the user level.

**Differences Between Processes and Threads:**
- **System Calls:**
  - Processes: System calls involved (e.g., `fork`).
  - Threads: No system calls involved.
- **Kernel Involvement:**
  - Processes: Kernel and operating system generate new processes.
  - Threads: User or application creates threads.
- **OS Treatment:**
  - Processes: OS treats different processes separately with unique Process IDs.
  - Threads: OS treats all threads within a process as a single task.
- **Data and Code:**
  - Processes: Different processes have separate copies of data, files, and code.
  - Threads: Threads share the same data, files, and code.
- **Context Switching:**
  - Processes: Context switching is slower due to saving and restoring process states.
  - Threads: Context switching is faster with minimal overhead.
- **Blocking:**
  - Processes: Blocking one process does not block others.
  - Threads: Blocking one thread blocks the entire process.

**Context Switching:**
- Involves time slicing and saving process states in the Process Control Block (PCB).
- Slower in processes due to extensive state saving and restoring.
- Faster in threads with minimal state switching.

**Blocking:**
- Processes: Independent; blocking one does not affect others.
- Threads: Interdependent; blocking one thread blocks the entire process.

**Additional Points:**
- Processes use different memory and addresses.
- Threads share memory and addresses, reducing overhead.
- https://hanwenzhang123.medium.com/process-v-s-thread-and-background-processing-with-worker-25dd763fb88a
- https://medium.com/javarevisited/most-people-in-tech-cant-answer-the-process-vs-thread-question-correctly-079635291e14
- https://stackoverflow.com/questions/200469/what-is-the-difference-between-a-process-and-a-thread

---

### Difference in process and threads
https://stackoverflow.com/questions/200469/what-is-the-difference-between-a-process-and-a-thread#:~:text=3,2%2C%202021%20at%2021:03

[todo]:
- In order to understand the difference
  - understand and capture how threads work ?
    - What are they ? do they consist memory ? who assigns them ?
    - who controls them ? who terminates them ?
    - anatomy of a thread (stack, register diagram similar to process)
    - how can they be invoked ? created ? terminated (if we can) ? assigning tasks on thread (based on current understanding) ?
    - where do they exist ? what is the time when ? do they have any states ?

  - For process, memory layout, their states (captued already), linux commands related to them
  - same as above questions with linux commands.
