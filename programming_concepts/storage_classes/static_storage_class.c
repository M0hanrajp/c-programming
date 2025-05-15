#include <stdio.h>
// static - static duration and internal linkage (unless at block scope)
// It can be used with functions at file scope and with variables at both file and block scope
// but not in function parameter lists.

static int x = 1; // file scope x, internal linkage (available only within this TU)
static int a; // file scope x, internal linkage (available only within this TU)

void f(void) {
    static int x = 1;  // block-scope, no linkage, new object, static storage duration

    /* This is a different object: it has static storage duration 
     * (it lives for the lifetime of the program) 
     * but no linkage (you can’t refer to it by name from outside f) 
     *
     * Note: we refer x from g(), that refers to x declared at file scope & internal linkage 
     * (defined at top of the file)
     */

    /* No Linkage meaning:- 'x' can be refered below, but cannot be refered by the other functions */
    x++;               // modifies x block scope, no linkage 
    printf("inside f(): x = %d\n", x); // prints 3
}

void g(void) {
    x++; // modifies file scope, internal linkage x to 2
    printf("inside g(): x = %d\n", x); // prints 2

    /* If in g(), one defines static int x = 1, then it's a new object
     * with block scope & no internal linkage for g()
     */
}

int main(void) {
    f();  // prints "inside f(): using block scope, no linkage x
    g();  // prints "inside g(): using file scope, internal linkage x

    /* Internal Linkage meaning:- 'a' can be refered below, since it's file scope defined */
    printf("inside main(): a = %d\n", a); // using file scope, internal linkage x
    return 0;
}

// output
/*
$ ./a.out
inside f(): x = 3
inside g(): x = 2
*/
