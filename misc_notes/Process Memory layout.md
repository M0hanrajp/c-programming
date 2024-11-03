## Process memory layout

* Stack: memory is allocated and deallocated in defined order.
* Stack manages local variables, function calls & input arguments.
* Heap: memory allocated and deallocated in random (or without any) order.

![image](https://github.com/user-attachments/assets/56e46017-89f7-4f10-83fa-c655e96211ad)

The stack is called LIFO (Last In First Out) because:
1. When functions are called, they are "pushed" onto the stack in order
2. When functions complete, they are "popped" off in reverse order - the last function pushed is the first one to be removed
3. This maintains a strict execution order and helps track program flow

Types of data typically stored in the stack:
1. Local variables within functions
2. Function parameters
3. Return addresses (where to go back after function completes)
4. Function call frame/activation record
5. Register values that need to be restored

For example:
```c
void func1() {
    int x = 10;    // Stored on stack
    func2(x);      // Parameters and return address pushed to stack
}                  // When func1 ends, its stack frame is popped
```
![image](https://github.com/user-attachments/assets/8a69ec53-6493-4e1f-88ad-c0e34635abbd)

Yes, here are some other important points about memory layout in C programs:

1. BSS vs Data Segment:
- Data segment: Contains initialized global/static variables
- BSS: Contains uninitialized global/static variables (automatically initialized to 0/NULL)
```c
static int initialized = 10;    // Data segment
static int uninitialized;      // BSS segment
```

2. Text/Code Segment:
- Read-only section containing executable code
- Typically shared among multiple processes running same program
- Protected from modification to prevent code corruption

3. Memory Protection:
- Text segment: Read + Execute
- Data & BSS: Read + Write
- Stack & Heap: Read + Write
- Attempting to write to read-only segments causes segmentation fault

5. Common Issues:
- Stack overflow: Too many function calls/large local variables
- Memory leaks: Not freeing heap memory
- Buffer overflow: Writing beyond allocated memory
- Segmentation fault: Accessing invalid memory addresses

These concepts are crucial for:
- Debugging memory issues
- Writing efficient code
- Understanding program behavior
- Preventing security vulnerabilities

Would you like me to elaborate on any of these points?

### References

- https://youtu.be/2htbIR2QpaM?si=J_Qt6-pPwTRjHtYa
- 
