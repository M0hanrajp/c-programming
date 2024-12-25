## Pointer to function

In the following snip, display is a function that is of type void and does not take any arguments.
```bash
(gdb) l
3       void display() {
4           printf("from function\n");
5       }
6
7       int main(void) {
8           display();
9           return 0;
10      }
```
The following snip shows that display has address associated to it.
```bash
(gdb) p display
$1 = {void ()} 0x555555555149 <display>
(gdb) whatis display
type = void ()
(gdb) printf"%p", display
0x555555555149(gdb)
```
from https://www.geeksforgeeks.org/how-to-declare-a-pointer-to-a-function/

**Function Pointer Declaration**

The syntax for declaring a function pointer depends on the function itself but the general syntax can be specified as:
```bash
return_type (*ptr)(parameter_types);
```
- return_type: Return type of the function (e.g., int, void, float).
- ptr: Name of the pointer to the function.
- parameter_types: Types of parameters the function will accept.
>Note: The parenthesis here are crucial as they set the type of the data you are declaring. Missing any of this parenthesis may declare ptr as whole different type.

**Function Pointer Initialization**

Once the function pointer is declared, it is then assigned the address of the function it should point to. Note that we can assign address of any function to function pointer as long as it matches the signature of the function pointer.
```bash
ptr = &func;   // Using addressof operator
ptr = func;    // Without using addressof operator
```
- where, func is the name of the function.
- After assigning the function pointer, we can use the ptr in place of function.

The same example with pointers:
```bash
3       void display() {
4           printf("from function\n");
5       }
6
7       int main(void) {
8           typedef void (*ptrf)();
9           ptrf pointerToFunction = &display;
10          pointerToFunction();
# Using GDB to check
(gdb) p display
$4 = {void ()} 0x555555555149 <display>
(gdb) p pointerToFunction
$5 = (ptrf) 0x555555555149 <display>
```
One can use `(*pointerToFunction)();` for calling the program. paranthesis ensure the pointer is dereferenced first.
(Good calculater example explaining use of pointer to a function)[https://www.geeksforgeeks.org/how-to-declare-a-pointer-to-a-function/]

>Todo Q: how are functions called in C programming ?

