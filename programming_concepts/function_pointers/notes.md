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
>Note: The parenthesis here are crucial as they set the type of the data you are declaring. 
    - a. `return_type (*ptr)(parameter_types) -> ptr is a pointer to a function type return_type.
    - b. `return_type *ptr(parameter_types) -> ptr is a function of type return_type * (function declaration) it's the reason why paranthesis are important
    - Note: in a. ptr is also called function pointer since it holds the address of a function 

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

## Use cases of function pointers.

### Callbacks

>When reference to a function is passed to another functions then that particular function is a callback function.
    - Also: A callback in C is a function that is provided to another function to "call back to" at some point when
            the other function is doing its task.

example of a callback function in callback_functions.c

[From](https://www.codeproject.com/Tips/5366204/What-is-Synchronous-and-Asynchronous-Callback-in-C)

**Synchronous callback**:

- A synchronous callback is a function or delegate that is executed immediately and blocks the calling thread until it completes. 
- In other words, when a synchronous callback is invoked, the program will wait for it to finish before moving on to the next task. 
- This can lead to potential performance issues and blocking of the main thread, which could make the application less responsive.

**Asynchronous callback**:

- An asynchronous callback, on the other hand, is used to execute code without blocking the calling thread. 
- Instead of waiting for the callback to complete, the calling thread can continue executing other tasks while the callback is running in the background. 
- This approach helps maintain the responsiveness of the application and can lead to better utilization of system resources.

Some info:

https://stackoverflow.com/questions/631273/function-pointers-and-callbacks-in-c

>"registering the callback" is the act of telling the underlying system which precise function to call, 
and (optionally) with which parameters, and possibly also for which particular class of events that 
callback should be invoked.

>The "event dispatcher" receives events from the O/S (or GUI, etc), and actually invokes the callbacks, 
by looking in the list of registered callbacks to see which are interested in that event.


https://stackoverflow.com/questions/17749452/still-not-getting-callback-vs-normal-function-call

>This is a argument between usage of `(*func_ptr)(args);` [explicit] & `func_ptr(args);` [Implicit] both are same

https://stackoverflow.com/questions/142789/what-is-a-callback-in-c-and-how-are-they-implemented

>Asynchronous and synchronous, static and dynamic callbacks info.

https://www.geany.org/manual/gtk/gtk-tutorial/x159.html
https://www.cs.purdue.edu/homes/cs240/lectures/Lecture-17-Callbacks.pdf

>Signals and callbacks, examples on async & sync callbacks

https://docs.gtk.org/gio/func.bus_own_name.html

>name_acquired_handler Type: GBusNameAcquiredCallback (this is an async function callback)
