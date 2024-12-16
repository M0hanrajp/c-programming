### Notes on dynamic memory allocation.

### Error 1, dynamic allocation to array pointers.

The following error was encountered while allocating memory to array pointers
```bash
46        char *p = "hello";
# here str is array of pointer type char
48        char *str[5] = (char *)calloc(25, sizeof(char));
49        for (int i = 0; p[i] != '\0'; i++) {
50          strcpy(str[i], p);
(gdb) l
51          str[i][i] -= 32;
52          printf("%s\n", str[i]);
53        }
54        return 0;
55      }
(gdb) n
49        for (int i = 0; p[i] != '\0'; i++) {
(gdb) info locals
i = 0
p = 0x555555556004 "hello"
str = {0x0, 0x0, 0x0, 0x0, 0x0}
(gdb) n
50          strcpy(str[i], p);
(gdb) n

Program received signal SIGSEGV, Segmentation fault.
__strcpy_evex () at ../sysdeps/x86_64/multiarch/strcpy-evex.S:596
596     ../sysdeps/x86_64/multiarch/strcpy-evex.S: No such file or directory.
```
>#### Case 1 In the line 48 above, if char *str[5] only if it was declared then :
- The segmentation fault occurs because the str array is declared as an array of uninitialized pointers (char *str[5]), and you are attempting to use strcpy(str[i], p); to copy the contents of p into these pointers without allocating memory for them.
- Uninitialized Pointers: The str array contains five uninitialized pointers. Using them without allocating memory leads to undefined behavior and eventually a segmentation fault.
```bash
# See below 0x0 means no address allocated and there is no string.
(gdb) p str
$1 = {0x0 <repeats 15 times>}
(gdb) n
51          if(p[i] == ' ')
(gdb) n
53          strcpy(str[count], p);
(gdb) n

Program received signal SIGSEGV, Segmentation fault.
__strcpy_evex () at ../sysdeps/x86_64/multiarch/strcpy-evex.S:614
614     ../sysdeps/x86_64/multiarch/strcpy-evex.S: No such file or directory.
```
- Improper Use of strcpy: strcpy requires the destination pointer (str[i] in this case) to point to a valid memory location where the string can be copied. Without memory allocation, this will crash.

>#### Case 2 In the line 48 above, if char *str[5] = (char *)calloc(25, sizeof(char)) only if it was declared then :
- char *str[5] declares str as an array of 5 pointers to char. You cannot use a single call to calloc to initialize all elements of an array of pointers in this manner because calloc returns a single pointer, not an array of pointers.

### Error 1 solution :: proper way to allocate memory
- for each row based on the use case proper allocation needs to be done. i.e. inside a loop.
```bash
# str is NULL
str = {0x0 <repeats 15 times>}
# proper allocation memory
53          str[count] = (char *)calloc(strlen(p), sizeof(char));
(gdb) n
54          strcpy(str[count], p);
(gdb) info locals
i = 0
p = 0x555555556004 "two words where"
# we can see below row 0 is allocated first memory and string is copied
str = {0x5555555592a0 "two words where", 0x0 <repeats 14 times>}
```
