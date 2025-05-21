#include <stdio.h>
// for usecases: https://www.gnu.org/software/c-intro-and-ref/manual/html_node/Void-Pointers.html

int main(void) {
    int a = 8;
    void *ptr = &a;
    /* type void *, a pointer whose target type is void, .It represents a pointer to we-don’t-say-what.
     * dereferencing it gives a void value that can’t be used (see The Void Type). 
     */
    printf("%p\n", ptr); // just prints the address
    // printf("%d\n", *ptr);
    // it's invalid becuase it's not of any type
    /* the following warning & error is observed
    $ gcc -g -Wall void_pointers.c
    void_pointers.c: In function ‘main’:
    void_pointers.c:9:20: warning: dereferencing ‘void *’ pointer
        9 |     printf("%d\n", *ptr);
          |                    ^~~~
    void_pointers.c:9:20: error: invalid use of void expression
    */

    /* solution
     * Assignments convert void * automatically to any other pointer type, if the left operand has a pointer type; for instance,
     */
    int *dref = ptr;
    printf("Converting void* to int* using assignment %d\n", *dref);

    // Passing an argument of type void * for a parameter that has a pointer type also converts. 
    // You can also convert to another pointer type with an explicit cast

    printf("Converting void* to int* using explicit cast %d\n", *(int *)ptr); // cast and dreference
                                                                              // The expression *(int *)ptr means to convert ptr to type int *, then dereference it.
    return 0;
}
