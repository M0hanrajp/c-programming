#include <stdio.h>

int main(void) {
    int a = 5;

    // we can declare pointer in two different ways
    int *p1 = &a;
    int* p2 = &a;

    // both are fine unless we encounter below situation
    int* x1, x2;
    /* x1 - is of type pointer to a int
     * x2 - is of type int
     */

    /* Conclusion
     * declare pointers int *p1, *p2 for better clarity or use single line declarations
     */

    return 0;
}
