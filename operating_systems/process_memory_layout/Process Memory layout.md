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
![Image](https://github.com/user-attachments/assets/63d667eb-cc86-44ba-b3ae-c6fc53c4b6e3)

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

### Questions:
-  What happens when we call a function
What happens when we call a function: (Have a look at how arguments and variables are stored onto the stack
![Image](https://github.com/user-attachments/assets/eeea7095-7a0f-4040-ba8a-1cb852fb6de0)

What data needs to be stored ? & Where does it go ?
![Image](https://github.com/user-attachments/assets/db37fd4b-c6c1-4fe0-85d8-5ca7cb70bddc)
Compiler is generating code to access the variables, question is if it want's to increase the value of loc2,
How will it do ?
Where is loc2 stored ? how program knows address ? 
- compiler cannot know this address at compile time,
- compiler knows the relative address i.e. the stack frame, so the reference pointer in the stack frame stored in %ebp register
- so the loc2 variable is -8(%ebp) from the reference point

- What happens when we return from a function
    - What data needs to be restored ?
    - where does it come from ?


- Caller's data, in main() uses frame pointer to access it's local variables.

How do we restore frame pointer
- after pushing arg1, arg2, arg3, now at the current stack pointer,
    - the stack frame pointer (often stored in the EBP register) is pointing to the current top of the stack. 
    - This pointer helps in accessing local variables and arguments within the stack frame.

![Image](https://github.com/user-attachments/assets/2e1b72a0-116a-435b-b540-321609329fa3)

(Need to explore them practically)
Saving the Frame Pointer:
Saving main's Frame Pointer: Before main calls funk, it saves its own frame pointer onto the stack. This ensures that main can restore its frame pointer after funk returns, allowing it to access its own local variables correctly.

Updating the Frame Pointer:
Updating to Current Stack Pointer: After saving main's frame pointer, the frame pointer is updated to the current stack pointer. This new frame pointer will be used by funk to manage its own stack frame.

Pushing Local Variables:
Local Variables of funk: When funk starts executing, it will push its local variables onto the stack. These local variables are stored after the current stack pointer, which has been updated to point to the top of the stack.

the instruction pointer %eip, moves through instrcutions that implement main and calls func
![Image](https://github.com/user-attachments/assets/8bff5fe5-3b73-4aa2-943e-09c99b9d4ced)

Using %eip before %ebp
![Image](https://github.com/user-attachments/assets/f5177392-5914-4a7e-aa40-f48acf113c11)

![Image](https://github.com/user-attachments/assets/e2ec8b63-8e0c-490d-bc72-bd9961ea17c0)

### References

- https://youtu.be/2htbIR2QpaM?si=J_Qt6-pPwTRjHtYa
