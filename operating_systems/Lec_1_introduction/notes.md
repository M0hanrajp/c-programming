## 1. Overview and Introduction

- **Main Focus:**
  - The topic is "Introduction to Operating Systems" with an emphasis on understanding its functionalities.
  ![Image](https://github.com/user-attachments/assets/b34afd92-46f6-4742-9476-185baae28701)

## 2. Definition and Basic Role of an Operating System (OS)

- **Definition:**
  - The OS is defined as a system software that acts as an intermediary between the user and the computer hardware.
  - It hides the complexities of direct hardware access from the user.

- **Function as an Interface:**
  - Provides a layer of abstraction, allowing users to interact with hardware without needing to write specialized programs for each device.
  - Enables user-friendly operations such as launching applications, managing files, and controlling peripheral devices (keyboard, mouse, printer, etc.).

- **Illustrative Example:**
    - **Hardware Components:** CPU (the "brain"), input/output devices, RAM (main memory), and secondary memory (hard disk).
    - **User Interaction:** Instead of directly manipulating these hardware elements, users interact via the OS, which coordinates the underlying operations.

---

## 3. Rationale Behind Using an Operating System

- **Complexity of Direct Hardware Access:**
  - Without an OS, every hardware action would require a specific, manually written program.
  - For example, to print a document or run a process, the user would have to create individual programs for each task.

- **Benefits of an OS:**
  - **Simplifies Interaction:** Reduces complexity by providing standardized methods for hardware control.
  - **Resource Sharing:** Manages concurrent access by multiple processes or users, ensuring fair allocation of resources.
  - **Prevention of Resource Conflicts:** Acts as a mediator to avoid conflicts when two processes try to access the same hardware simultaneously.

- **Historical Context:**
  - The example of Microsoft Windows is used to illustrate how an OS gained massive popularity due to the convenience it provides.
  - Early dominance of Windows (up to 95% market share) was largely because of its user-friendly interface.

---

## 4. Primary Goals and Objectives of Operating Systems

- **Convenience:**
  - OSs are designed to provide ease of use and a seamless interface, abstracting the complexities of hardware interaction.
  - This convenience is a key factor behind the widespread adoption of user-centric OSs like Windows.

- **Throughput and Performance:**
  - **Definition of Throughput:** The number of tasks or processes executed within a given time frame.
  - Modern operating systems strive for high throughput, meaning they are optimized to execute as many tasks as possible per unit time.
  - **Linux Example:** The notes explain how Linux has gained traction by offering high throughput along with satisfactory convenience, especially in environments where performance is critical.

- **Diverse Market Presence:**
  - **Microsoft Windows:** Initially dominant due to ease of use; still popular for personal and office use.
  - **Linux:** Increasingly preferred in server environments and situations demanding high performance.
  - **Apple Macintosh (Mac OS):** Carves its niche with a blend of performance and an intuitive graphical interface.

---

## 5. Detailed Functionalities of Operating Systems

### A. Resource Management
- **Role and Importance:**
  - The OS acts as a resource governor by managing hardware resources (CPU, memory, I/O devices) among various processes.
  - It dynamically allocates and deallocates resources, ensuring that system load remains balanced.
- **Multi-user and Server Environments:**
  - Essential in scenarios where multiple users or applications access a single hardware resource simultaneously.
  - Prevents a situation where one process monopolizes the hardware, ensuring fair access.

### B. Process Management
- **Definition and Process Lifecycle:**
  - Process management involves creating, scheduling, executing, and terminating processes.
  - When a program is executed, it becomes a process. The OS then schedules these processes using CPU scheduling algorithms.
- **CPU Scheduling Algorithms:**
  - The OS decides the order in which processes are executed based on factors like priority, burst time, and fairness.
- **Multi-tasking:**
  - Allows simultaneous running of multiple applications, enhancing user productivity.
  - Uses context switching to manage the execution of several processes on a single CPU.

### C. Storage Management
- **Secondary Memory Management:**
  - The OS manages long-term data storage on devices such as hard disks.
  - It organizes data using file systems (e.g., NIFS, CFS, CIFS, NFS), which dictate how data is stored, retrieved, and managed.
- **File System Concepts:**
  - Tracks, sectors, and blocks: The OS divides the disk into manageable units for efficient data storage and retrieval.
  - File management utilities help users create, delete, modify, and organize files.

### D. Memory Management
- **Managing RAM:**
  - Memory management is critical because RAM is a limited resource compared to secondary storage.
  - The OS handles allocation (assigning memory to processes) and deallocation (freeing memory after process completion).
- **Key Techniques:**
  - **Swapping:** Moving processes in and out of RAM to maximize utilization.
  - **Segmentation and Paging:** These techniques prevent processes from interfering with each other by defining boundaries and mapping virtual memory to physical memory.
- **Multitasking Support:**
  - Efficient memory management allows multiple processes to reside in RAM, ensuring smooth multitasking operations.

### E. Security and Privacy
- **User Authentication:**
  - When the system starts, it typically requires a password or another form of authentication to verify the user's identity.
- **Security Protocols:**
  - Windows, for instance, uses the Kerberos security protocol to securely store and manage passwords.
- **Process Isolation and Memory Protection:**
  - Each process is allocated its own segment of memory.
  - If a process tries to access memory outside its allocated range, the OS blocks it, thus preventing potential interference or data corruption.
- **Data Privacy:**
  - The OS enforces permissions and access control lists to ensure that sensitive data remains protected from unauthorized access.

### F. User Interfaces and Interaction Mechanisms
- **Graphical User Interface (GUI):**
  - Provides a visual desktop environment where users can interact with icons, windows, and menus.
  - Example: Windows Desktop allows access to files, applications, and settings.
- **Command-Line Interface (CLI):**
  - Especially prominent in Linux and Unix-like systems.
  - Enables users to interact with the system through typed commands, which is often more powerful for advanced operations.
- **Application Integration:**
  - Applications serve as intermediaries between the user and the OS. For instance, when you print a document from Microsoft Word, the application triggers a system call to the OS to manage the printing process.
- **Shells and Terminals:**
  - In addition to GUIs, the OS provides shells (e.g., command prompt in Windows, terminal in Linux) that allow for direct command execution and scripting.

### G. System Calls
- **Definition and Importance:**
  - System calls are the standardized methods by which applications request services from the OS kernel.
- **Examples of System Calls:**
  - **Print Command:** When a user selects print, the application makes a system call that communicates with the printer driver.
  - **File Operations:** Opening, reading, writing, and closing files are all executed via system calls.
- **Bridge Between User Space and Kernel Space:**
  - They facilitate secure and controlled access to hardware, ensuring that user applications do not directly manipulate the hardware, which could lead to errors or security vulnerabilities.

---

Questions: Where is process executed ?, how is process mapped to main memory ?
