#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* calling function calls itself to compute an expression or solve a problem */

// NASA function, counts 10 to 1
void countdown(int n) {
    printf("Countdown : %d", n--);
    if(n == 1)
        printf("\n[ :: IGNITION :: ]");
    printf("\n");
    if(n > 0) { 
        countdown(n);
    } else {
        printf("[ :: BLAST OFF ::]\n");
    }
}

// factorial program
/* my own way of writing factorial program using recursion
 * I took an variable and got the answer
 * below there is another program that does it without this */
void myFactorial(int n) {
    static int f = 1;
    f *= n--;
    if(n > 0) 
        myFactorial(n);
    else
        printf("myFactorial = %d\n", f);
}

int factorial(int n) {
    if(n == 1)
        return 1;
    return (factorial(n - 1) * n);
}
/* First call of function from main 
    42          printf("Factorial = %d\n", factorial(12));
    (gdb) s
    factorial (n=12) at main.c:33
    33          if(n == 1)
    (gdb) n
    35          return (factorial(n - 1) * n);
    (gdb) s
    factorial (n=11) at main.c:33 <---------- second call (recursive)
    33          if(n == 1)
    (gdb) n
    35          return (factorial(n - 1) * n);
    ...
    ...
    // recursion break condition is hit, it returns 1
    (gdb) s
    factorial (n=1) at main.c:33
    33          if(n == 1)

    Now at this time, there are multiple call stacks of the same function 
    waiting for their return value

    factorial (n=2) at main.c:35 
    35          return (factorial(n - 1) * n); // factorial(n-1) 1 * (n)  2 = returns 2
    factorial (n=3) at main.c:35
    35          return (factorial(n - 1) * n); // factorial(n-1) 2 * (n)  3 = returns 6
    factorial (n=4) at main.c:35
    35          return (factorial(n - 1) * n); // factorial(n-1) 6 * (n)  4 = returns 24
    ...
    ...
*/

void myFibonacci(int n) {

}

// recursion
int main(void) {
    countdown(10);
    myFactorial(12);
    printf("Factorial = %d\n", factorial(12));
    return 0;
}
