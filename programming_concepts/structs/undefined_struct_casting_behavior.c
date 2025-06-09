#include <stdio.h>

int main(void) {
    struct A { int x; float y;};
    struct B { float w; int z;};
    struct A a = {88, 88.88};
    struct B *b = (struct B *)&a;
    printf("b->w = %f and b->z = %d\n", b->w, b->z);
    // output $ ./a.out
    // b->w = 0.000000 and b->z = 1118945935
    /* You're treating the memory of a struct A as if it were a struct B 
     * — this is type punning, and in standard C, accessing an object via 
     * an incompatible type is undefined behavior (unless it's via a union or char *).
     */
    return 0;
}
