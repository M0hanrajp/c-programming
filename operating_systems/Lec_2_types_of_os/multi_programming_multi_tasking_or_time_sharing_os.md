**Multi-Programming vs. Multi-Tasking Operating Systems - Detailed Notes**

## 1. Introduction
- **Multi-programming and Multi-tasking Operating Systems** are two fundamental types of OS that improve CPU utilization and responsiveness.
- **Multi-programming** focuses on maximizing CPU utilization by keeping multiple processes in memory.
- **Multi-tasking (Time-Sharing)** ensures that multiple tasks run concurrently by allocating time slices to each process.

Important for this topic https://www.geeksforgeeks.org/preemptive-and-non-preemptive-scheduling/

## 2. Multi-Programming Operating System
### **2.1 Concept**
- On a single CPU.
- **First introduced** before multi-tasking.
- The idea is to **load multiple processes** into RAM so that the CPU always has a job to execute.
- The **goal is to reduce CPU idle time** by switching to another process when one is waiting for I/O.

![Image](https://github.com/user-attachments/assets/a6259a93-e852-44dc-9afb-c74fe798e503)

### **2.2 Execution Process**
- The **CPU executes one process completely** before moving to the next.
- Execution is **non-preemptive**, meaning the CPU only switches if a process voluntarily moves to I/O.(Context switching)
- Switch	happens	when	current	process	goes	to	wait	state.
- Non-Preemptive Scheduling:
    - Once a process starts executing, it continues until it completes its task, voluntarily yields control, or encounters an event that causes it to wait (e.g., waiting for I/O).
    - Example: First-Come, First-Served (FCFS) scheduling, where processes are executed in the order they arrive.
    - Advantages:
        - Simplicity: Easier to implement and manage.
        - Reduced Overhead: Minimal context switching overhead.
    - Disadvantages:
        - Lack of Responsiveness: Can be unresponsive to high-priority tasks if a low-priority process is currently running.
        - Starvation: A long-running process can prevent other processes from getting access to the CPU. 
- **Scheduling is sequential**, following a **First Come, First Served (FCFS)** approach.

### **2.3 Example Analogy**
- Suppose **10 students** are in a classroom, each with **5 questions** to solve.
- A teacher (CPU) will **help Student1 solve all 5 questions** before moving to Student2, then Student3, and so on.
- If a student **needs a break (I/O request)**, the teacher moves to the next student.
- Once a student finishes their questions, they leave, and the next student gets their turn.

### **2.4 Advantages**
✅ **Better CPU Utilization:** CPU is not idle when a process is waiting for I/O.
✅ **Efficient for batch processing:** Suitable for systems where job completion time is not critical.
✅ **Simple Scheduling:** Jobs are executed one after another without complex scheduling algorithms.

### **2.5 Disadvantages**
❌ **Long Waiting Time:** A process has to wait until the previous one completes.
❌ **Poor Responsiveness:** If one process takes too long, others have to wait longer.
❌ **No Pre-emption:** The OS does not interrupt a running process to switch to another.

## 3. Multi-Tasking (Time-Sharing) Operating System
### **3.1 Concept**
- On a single CPU
- Multi-tasking is **pre-emptive**, meaning that the CPU **allocates a fixed time slice** to each process.
- Preemptive Scheduling:
    - A process can be interrupted and suspended by the operating system, even if it's currently running, to allow a higher-priority process to access the CPU.
    - Round-robin scheduling, where each process gets a fixed time slice, and if it doesn't finish within that time, it's interrupted and the next process gets the CPU.
    - Advantages:
        - Flexibility: Allows the system to quickly respond to urgent tasks or high-priority events.
        - Fairness: Prevents a single process from monopolizing the CPU.
    - Disadvantages:
        - Overhead: Context switching (saving the state of the interrupted process and loading the state of the new process) can be computationally expensive.
        - Complexity: Requires a more complex scheduler.
- Processes **switch rapidly**, giving the illusion that they are running simultaneously.
- Used in **modern computing devices** like laptops, desktops, and mobile devices.
- Context	switching	and	time	sharing	used. Increases	responsiveness.

![Image](https://github.com/user-attachments/assets/ba058560-461d-4050-8729-9a3f42681872)

### **3.2 Execution Process**
- The **CPU executes each process for a fixed time slice** (e.g., 10ms per process).
- If a process **completes within its time slice**, it exits.
- If not, the OS **pre-empts (interrupts) the process** and schedules it for the next cycle.

### **3.3 Example Analogy**
- Suppose **10 students** are in a classroom, each with **5 questions**.
- The teacher (CPU) **helps Student1 with only 2 questions** and then moves to Student2, then Student3, and so on.
- After reaching the last student, the teacher **returns to Student1** to solve the remaining questions.
- This ensures that **each student gets attention frequently**, rather than waiting for their entire turn.

### **3.4 Advantages**
✅ **Better Responsiveness:** Users don’t have to wait long for their processes to get CPU time.
✅ **Efficient for real-time interaction:** Used in modern operating systems for smooth user experience.
✅ **Allows fair CPU allocation:** Ensures every process gets some execution time.

### **3.5 Disadvantages**
❌ **Overhead of Context Switching:** Frequent switching between processes increases overhead.
❌ **Complex Scheduling Algorithms:** Requires time-sharing algorithms like **Round Robin**.
❌ **Not Always Optimal for CPU Utilization:** Switching too frequently may waste CPU cycles.

## 4. Key Differences Between Multi-Programming and Multi-Tasking
| Feature            | Multi-Programming OS | Multi-Tasking (Time-Sharing) OS |
|--------------------|---------------------|-------------------------------|
| **Execution Type** | Non-preemptive       | Preemptive                    |
| **Process Scheduling** | CPU executes one process until completion | CPU switches between processes after fixed time slices |
| **Response Time**  | Longer, as processes execute one by one | Faster, as processes get frequent CPU time |
| **CPU Utilization** | High (but idle during I/O) | Very high due to frequent switching |
| **Complexity**     | Simple              | More complex (requires scheduling algorithms) |
| **Best Used For**  | Batch Processing, Heavy Computing | Interactive systems like PCs, Laptops, Mobile Phones |

### **Examples of Multi-Programming OS:**  
- **IBM OS/360** – Early batch processing systems used multi-programming to keep the CPU busy.  
- **UNIX (Early versions)** – Allowed multiple programs to reside in memory but did not support preemptive task switching.  
- **Mainframes & Supercomputers** – Used in scientific calculations and batch processing.  

### **Examples of Multi-Tasking OS:**  
- **Windows, macOS, Linux (Modern systems)** – Allow users to run multiple applications, switching between them using preemptive scheduling.  
- **Unix-based systems (Modern versions)** – Implement multi-tasking with time-sharing concepts.  
- **Mobile OS (Android, iOS)** – Run multiple applications concurrently, managing CPU time efficiently.  

## **Multiprocessing Operating System**

### **1. Introduction**
A **Multiprocessing Operating System** is an OS that supports the execution of multiple processes simultaneously by using multiple processors (CPUs). Unlike single-processor systems, where tasks are managed through scheduling, multiprocessing systems improve performance by distributing workloads across multiple CPUs.

### **2. Features of Multiprocessing OS**
- Utilizes **two or more processors** for executing multiple processes.
- Supports **parallel processing** for better efficiency.
- Reduces CPU idle time and increases throughput.
- Handles **multiple users and processes** effectively.
- Provides **high reliability and fault tolerance**, as one CPU failure does not halt the entire system.

### **3. Types of Multiprocessing OS**
#### **a. Symmetric Multiprocessing (SMP)**
- Each processor runs an identical copy of the operating system.
- A single OS manages all CPUs.
- Load balancing is automatic as all CPUs share resources equally.
- Example: **Linux, Windows, MacOS (modern versions).**

#### **b. Asymmetric Multiprocessing (AMP)**
- One CPU is designated as the master processor, controlling system functions.
- Other CPUs (slave processors) execute user tasks.
- Less efficient but simpler to implement.
- Example: **Early mainframe computers, some real-time systems.**

### **4. Advantages of Multiprocessing OS**
✅ **Increased Performance** – Multiple CPUs execute tasks in parallel, reducing execution time.
✅ **Better Resource Utilization** – Distributes workloads effectively across processors.
✅ **High Reliability & Fault Tolerance** – If one CPU fails, others continue working.
✅ **Efficient Multitasking & Multi-User Support** – Handles multiple processes and users efficiently.

### **5. Disadvantages of Multiprocessing OS**
❌ **Complex Architecture** – Managing multiple CPUs requires advanced scheduling algorithms.
❌ **High Cost** – Requires expensive hardware.
❌ **Synchronization Issues** – Shared resource management can lead to bottlenecks if not handled correctly.

### **6. Examples of Multiprocessing OS**
- **Linux (Ubuntu, Red Hat, CentOS, etc.)** – Supports symmetric multiprocessing.
- **Windows Server OS** – Used in enterprise environments for handling multiple tasks simultaneously.
- **IBM AIX, Solaris** – Unix-based systems optimized for high-performance computing.
- **MacOS (latest versions)** – Uses multiprocessing for efficient performance.

### **7. Applications of Multiprocessing OS**
🔹 **Supercomputers** – Used in scientific research, simulations, and large-scale computations.
🔹 **Datacenters & Cloud Computing** – Enables efficient task management across multiple CPUs.
🔹 **Embedded Systems & Real-time Processing** – Used in aerospace, automotive, and industrial applications.
🔹 **Gaming & Graphics Processing** – High-end games and software use multiprocessing for better performance.

### **8. Conclusion**
A **Multiprocessing OS** enhances system efficiency by allowing multiple CPUs to work together. It is widely used in high-performance computing environments and modern operating systems to improve processing speed, reliability, and resource management.

```bash
# Mutliprogramming
+--------------------------------+
|            RAM                 |
+--------------------------------+
|  P1  |  P2  |  P3  |  P4       |  <-- Multiple processes in memory
+--------------------------------+

Execution Timeline:

CPU ---> [ P1 Running ] ---> (P1 needs I/O) ---> [ CPU Idle ] ---> [ P2 Running ] ---> [ P3 Running ]
                 |                                |
           Disk Access                     Disk Access

Disadvantages:
- CPU idle time is high** due to I/O waits.
- Slow response time** since one process must finish before the next starts.

# Multitasking/ Timesharing
+--------------------------------+
|            RAM                 |
+--------------------------------+
|  P1  |  P2  |  P3  |  P4       |  <-- Multiple processes in memory
+--------------------------------+

Execution Timeline (Round-Robin Scheduling):

Time ---> [ P1 for 2ms ] --> [ P2 for 2ms ] --> [ P3 for 2ms ] --> [ P4 for 2ms ]
           |                      |                     |
     (P1 needs I/O)         (P2 continues)       (P3 needs I/O) 
           |                      |                     |
     [ P2 runs next ]       [ P4 runs next ]       [ P1 resumes ]

Advantages:
- Fast response time** because every process gets CPU time frequently.
- CPU never stays idle** since it quickly switches to another task
- Example: Windows, Linux (Desktop)

# Multiprocessing
+---------------------------+
|              RAM          |
+---------------------------+
|  P1  |  P2  |  P3  |  P4  |  <-- Multiple processes in memory
+---------------------------+

Execution Timeline (Parallel Processing):

Time --->  [ P1 on CPU1 ]  |  [ P2 on CPU2 ]  |  [ P3 on CPU3 ]  |  [ P4 on CPU4 ]
           (Independent Execution - No Switching)

Advantages:
- Zero CPU idle time** (no need to wait for time slices).
- Best for high-performance tasks** like AI, cloud computing.

Example: Supercomputers, Multi-Core Systems
```

---
https://www.geeksforgeeks.org/types-of-operating-systems/
https://www.indeed.com/career-advice/career-development/types-of-operating-systems
