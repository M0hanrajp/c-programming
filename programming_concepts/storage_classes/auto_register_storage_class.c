// program to check auto storage class
#include <stdio.h>
// auto - automatic duration and no linkage

// register - automatic duration and no linkage; address of this variable cannot be taken (both have similar behavior)
// additionally hints the optimizer to store the value of this variable in a CPU register if possible. 
// Regardless of whether this optimization takes place or not, variables declared register cannot be used as arguments 
// to the address-of operator, cannot use _Alignas(until C23)alignas(since C23)(since C11), and register arrays are not 
// convertible to pointers.

// we cannot use storage class specifiers for function paramerters check concept.md for the answer
void foo(/*auto int*/ ) { // start of block-scope

    auto int i; auto float j; auto char k; auto double l;
    /* all these declarations are block scope, no linkage
     *
     * Note: any declaration at file scope does not defaults to auto storage class
     * It default's to global declaration, i.e. file-scope having external linkage
     */

    printf("with auto keyword Unitialized in foo() :: int = %d, float = %f, char = %c, double = %lf\n", i, j, k, l);
    int a; float b; char c; double d;
    /* all these declarations default to block scope, no linkage */

    printf("without auto keyword Unitialized in foo() :: int = %d, float = %f, char = %c, double = %lf\n", a, b, c, d);
    /* x = 2; (gives an error, x is local to function main(), x is out of scope here)
     * Meaning x is block-scope, no linkage to the function main
     * refering x in foo() is not possible 
     */

    register int r;
    printf("With register keyword and unintialized variables yeilds :: register int = %d\n", r);
    // block-scope, no linkage, stored in CPU register if possible by the compiler
    // works same as auto specifier
    /* (gdb) info address r
        Symbol "r" is a variable in $rbx.
        (gdb) p &r
        Address requested for identifier "r" which is in register $rbx
    */

} // end of block-scope

int main(void) {
    // check the default values of variables
    auto int i; auto float j; auto char k; auto double l;
    /* all these declarations are block scope, no linkage */
    printf("with auto keyword Unitialized in main :: int = %d, float = %f, char = %c, double = %lf\n", i, j, k, l);

    int a; float b; char c; double d;
    /* all these declarations default to block scope, no linkage */
    printf("without auto keyword Unitialized in main :: int = %d, float = %f, char = %c, double = %lf\n", a, b, c, d);

    foo();

    // block-scope and storage duration of a variable
    int x = 1; //block-scope, no-linkage level 1
    printf("outer scope :: %d\n", x);
    {// start of level 2
        int x = 2;  
        /* block-scope, no-linkage level 2, int x = 1 is not relevant here
         * int x = 2 is different variable
         * any calculations performed over x in level 2 remain in level 2, level 1 x is not affected.
         */
        printf("inner scope :: %d\n", x);
        {// start of level 3
            int x = 3;
            /* block-scope, no-linkage level 3, int x = 2 & int x = 1 are not relevant here
             * int x = 3 is different variable
             * any calculations performed over x in level 1, 2 remain in level 1, 2, level 1 x is not affected.
             */
            printf("Innermost scope :: %d\n", x);
        }// end of level 3
    } // end of level 2

    int *p;
    auto int *q;
    printf("Value of uninitialzed pointer p (without auto keyword) :: %p & q (with auto keyword) ::%p\n", p, q);
    /* Note unitialized pointers when dereferenced cause segementation fault
     * Meaning int *p when dereferenced using *p with %d, causes seg fault since we are accessing invalid memory location.
     * pointer when assigned a value (address, because pointer holds address of another variable) is a valid memory location.
     */ 

/*     typedef struct {
            int r;
            auto int s; <---- this is not allowed, check concept.md, questions seciton
       } test; */

    return 0;
}

// output:
/*
$ ./a.out
with auto keyword Unitialized in main :: int = 0, float = 0.000000, char = , double = 0.000000
without auto keyword Unitialized in main :: int = 0, float = 0.000000, char = , double = 0.000000
with auto keyword Unitialized in foo() :: int = 0, float = 0.000000, char = , double = 0.000000
without auto keyword Unitialized in foo() :: int = 0, float = 0.000000, char = , double = 0.000000

why are we seeing zeros here ? (expected garbadge/indeterminate values)
On most modern operating systems (Linux, Windows, macOS), when your process first uses a new stack page 
it comes in all-zero bytes (the OS supplies you a zero-filled page for security). Since your main’s locals 
and then foo()’s locals both live on those pages that have never been touched, you see zeros.
source i.e. #2 comment from https://stackoverflow.com/questions/1597405/what-happens-to-a-declared-uninitialized-variable-in-c-does-it-have-a-value

outer scope :: 1
inner scope :: 2
Innermost scope :: 3
*/
