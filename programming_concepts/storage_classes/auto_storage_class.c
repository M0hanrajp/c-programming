// program to check auto storage class
#include <stdio.h>

void foo() {
    auto int i; auto float j; auto char k; auto double l;
    printf("with auto keyword Unitialized in foo() :: int = %d, float = %f, char = %c, double = %lf\n", i, j, k, l);
    int a; float b; char c; double d;
    printf("without auto keyword Unitialized in foo() :: int = %d, float = %f, char = %c, double = %lf\n", a, b, c, d);
    // x = 2; (gives an error, x is local to function main(), x is out of scope here)
}

int main(void) {
    // check the default values of variables
    auto int i; auto float j; auto char k; auto double l;
    printf("with auto keyword Unitialized in main :: int = %d, float = %f, char = %c, double = %lf\n", i, j, k, l);
    int a; float b; char c; double d;
    printf("without auto keyword Unitialized in main :: int = %d, float = %f, char = %c, double = %lf\n", a, b, c, d);
    foo();

    // scope and life the variable
    int x = 1;
    printf("outer scope :: %d\n", x);
    {
        x = 2;
        printf("inner scope :: %d\n", x);
        {
            x = 3;
            printf("Innermost scope :: %d\n", x);
        }
    }
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
