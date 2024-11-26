### Strings

Observations & notes:
- In order to print a string (manually by iterating through each character)
    - Use '\0' character as the exit expression.
    - when iterating with i as an integer from 0 till `\0` make sure expression checks the character not the integer.
        - i.e. check `variable[iteration n] != '\0'` not `iteration n' != '\0'` inside the loop.
        - in ascii `\0` (The null terminator) character value is 0.

**Key Differences**

| **Aspect**             | **`input[i] != '\0'`**                           | **`i != '\0'`**                     |
|-------------------------|--------------------------------------------------|--------------------------------------|
| **Context**            | Character array/string traversal                 | Numeric comparison                  |
| **Checks**             | If the current character is not the null terminator (`'\0'`) | If the integer `i` is not zero       |
| **Use Case**           | Iterating or processing strings                  | General numeric conditions           |
| **Outcome**            | Relates to the data in `input`                   | Relates to the value of `i`          |

- While using strcat, size of target string should be the total amount of characters in both soruce and target strings.
- You can pass a char * to a function that expects a const char *, const char * means that the function promises not to modify the data that the pointer points to, When you pass a char * to such a function, the function treats the data as read-only, ensuring it won't change the content.
    - You cannot pass a const char * to a function expecting a char * without a cast. This is because it could lead to attempts to modify read-only data, which would violate the const promise.
- In GDB you can use `p strlen(variable) to check the size of the variable.
```bash
Breakpoint 1, main () at problem_e.c:8
warning: Source file is more recent than executable.
8           printFibonacci("a", "b", 5);
(gdb) s
printFibonacci (f0=0x555555556006 "a", f1=0x555555556004 "b", order=5) at problem_e.c:12
12      void printFibonacci(const char *f0, char *f1, int order) {
(gdb) p strlen(f1)
$1 = 1
(gdb) p strlen(f0)
$2 = 1
```
### Questions

- char words[] = {'A', 'B', 'C', 'D', '\0'};, when printed by calling the function mentioned in basics_main.c prints ABCD.
    - when the same words[] is used without '\0' it prints ABCD, what is the behavior here ? does compiler add the '\0' terminator ?
