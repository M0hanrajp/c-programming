#include <stdio.h>

void display() {
    printf("from function\n");
}

int calculateDiv(int a, int b) {
    return a / b;
}

int main(void) {
    typedef void (*ptrf)();
    ptrf pointerToFunction = &display;
    typedef int (*fptr)(int, int);
    fptr CalculateIntegerDivision = &calculateDiv;
    pointerToFunction();
    printf("Result of the integer division %d\n", CalculateIntegerDivision(2, 2));
    return 0;
}

/* Output of the program
 * [Thread debugging using libthread_db enabled]
 *
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".

Breakpoint 1, main () at bascis.c:9
9           ptrf pointerToFunction = &display;
(gdb) info locals
pointerToFunction = 0x7fffffffddb8
(gdb) p display
$1 = {void ()} 0x555555555149 <display>
(gdb) n
10          pointerToFunction();
(gdb) info locals
pointerToFunction = 0x555555555149 <display>
(gdb) n
from function
11          (*pointerToFunction)();
(gdb) n
from function
12          return 0; */
