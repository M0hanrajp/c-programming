// Program to understand how to read a pointer, how to understand 
// the properties of the variable when more than one keyword is used
// in declaring a pointer.

/* https://stackoverflow.com/questions/1143262/what-is-the-difference-between-const-int-const-int-const-and-int-const
 * is used to understand the readings 
 * https://cdecl.org/ (converts any c code to readable english output
 * https://stackoverflow.com/a/31331389/22135402 (visual representation of the answer)
 * https://stackoverflow.com/a/29183538/22135402 (How const changes properties of a variable ?)
 */

#include <stdio.h>

int main(void) {
    /* Whenever you see * -> "pointer to", then add qualifier or data type assoicated with it 
     * In usage of pointers, the data, pointer or both will be constant based on where the const keyword is used
     * 
     * pointer arithmetic - trying to change the ptr or increase it's value
     * pointer arithemtic != ptr[0] or ptr[1] because in ptr[1], ptr stays constant, expression gives new result.
     * in ptr[1] we are not trying to modify ptr, hence it's allowed
     * 
     * how a++ is decided ---> in chunks the size of the thing you point to
     * int a = just a value, a++ is addition (not a pointer)
     * int *a = a points to a int value hence moves by sizeof(int)
     * int **a = a points to int * value hence moves by sizeof(int *)
     */

    int x = 88;
    int y = 98;
    printf("address of x = %p, value x = %d & address of y = %p, value y = %d\n", &x, x, &y, y);

    // type 1
    int *p = &x;
    //*p = 8; p = &y; p++;
    /* p is declared as * = "pointer to", int = "an integer". (pointer to an integer)
     * *p - mutable, p - mutable, pointer arithmetic is allowed
     */

    printf("*p = %d\n", *p);
    printf("*p++  = %d\n", *p++);
    printf("*p = %d (postfix hence in the next statement the value is updated)\n", *p);
    printf("++*p = %d\n", ++*p);
    printf("*++p = %d\n", *++p);
    /* output of the program
    address of x = 0x7ffcf0ae6b90, value x = 88 & address of y = 0x7ffcf0ae6b94, value y = 98
    *p = 88
    
     *p++  = 88
    // postfix operators have highest precedence, next are prefix operators
    - here *p++ is evaluated as *(p++)
    - the os has allocted x & y in consecutive address even when declared in separate variables.
    - p++ moves ahead by sizeof(int) & then (*)dereferences it to 98, the effect takes in the next statement
    *p = 98 (postfix hence next statement the value is updated)

    ++*p = 99
    *++p = -257004648
    // prefix opertors ++ & unary operator (prefix) both have the same precedence level.
    - when the precedence level is same then we consider associativity which is right to left here.
    - ++*p is evaluated as ++(*p) which gives us 99.
    - *++p is evaluated as *(++p) which gives us indeterminate value 
        - (p moves by +1 * sizeof(int), this memory location is invalid for our program)
    */

    // type 2
    const int *q = &x;
    //*q = 8; q = &y; q++;
    /* q is declared as * = "pointer to", int = "an integer", const = "constant" (pointer to an integer constant)
     * *q is not assignable(error: assignment of read-only location ‘*q’), q is modifiable
     * const qualifier is used over int data type hence *q is not assignable.
     * pointer arithemtic allowed.
     * similar declaration: int const *p;
     */

    // type 3
    int* const r = &x;
    //*r = 8; r = &y; r++;
    /* r is declared as const = "constant", * = "pointer to", int = "an integer" (constant pointer to an integer)
     * r is not modifiable(error: assignment of read-only variable ‘r’), *r is assignable
     * const qualifier is used over variable hence r is not assignable.
     * pointer arithemtic is not allowed.
     * similar declaration: int *const p;
     */

    // type 4
    const int* const s = &x;
    //*s = 8; s = &y; s++;
    /* s is declared as constant pointer to a constant integer
     * s - is not assignable, pointer arithmetic is not allwoed.
     * *s is not assignable, const qualifier is used both over data type & variable
     * const int* const != const int const *ptr (edundant const on int, pointer itself mutable)
     * const int * const == int const * const
     */

    // type 5
    int *t = &x;
    int **u = &t;
    u = &t;
    /* u is declared as pointer to a pointer to a int (double pointer to an int).
     * u holds the address of a single pointer variable.
     * dereferencing once -> gives you address of pointee.
     * dereferencing twic -> gives you value of pointee.
     * u is assignable, *u is assignable, pointer arithmetic is allowed on u & *u & **u
     */
    printf("**u = %d\n", **u);
    printf("**u++  = %d\n", **u++);
    printf("**u = %d (postfix hence in the next statement the value is updated)\n", *p);
    printf("++**u = %d\n", ++**u);
    printf("**++u = %d\n", **++u);
    // u = &t; (pointer to address x) *u = has address of x, **u value at address x;
    /* output
    **u = 88
    - dereference two times to get x

    **u++  = 88
    - **u++ is evaluated as **(u++)
    - here u points to int *, hence u moves by 1 * sizeof(int *)
    - then value at that address is derferenced
    - as we can see for our program the memory location is invalid, hence prints indeterminate value
    **u = -51707168 (postfix hence in the next statement the value is updated)

    ++**u = -51707167
    - here u points to int *, hence u moves by 1 * sizeof(int *)
    - ++ & **(prefix) have the same precedence, associativity is right to left
    - ++**u is evaluated as ++(**u), prints out -1 of indeterminate value (consider previous value)

    **++u = 88
    - here u points to int *, hence u moves by sizeof(int *)
    - ++ & **(prefix) have the same precedence, associativity is right to left
    - **++u is evaluated as **(++u), prints out value 88 which is x.
    - since previously u pointed out invalid location, by performing ++ again on u we landed back to address of x
    */

    /* The followig gives a warning
     * const int **v = &t;
     * warning: initialization of ‘const int **’ from incompatible pointer type ‘int **’ [-Wincompatible-pointer-types] 
     * the reason for this is included in reading_pointers.md */

    // type 6
    const int *z = &x;
    const int **a = &z;
    /* a is declared as pointer to a pointer to a constant integer
     * **a (int) is not assignable (it's constant), *a (int *) is assignable, a (int **) is assignable (which are pointers)
     * **a (any arithmetic here is not allowed since it's a constant integer)
     * *a & a (pointer arithmetic is allowed since both are pointers)
     */

    // type 7
    int *e = &x;
    int** const b = &e;
    /* b is declared as constant pointer to a pointer to an integer
     * b is constant, *b == &x & **b == x are modifiable, hence int** can be assigned to int** const
     * only the base level b remains constant.
     * arithmetic opertions on b is not allowed where as on *b is allowed && **b
     */

    // type 8
    int* const *g = &e;
    /* g is declared as pointer to a constant pointer to an integer
     *   g - base - level - int* const * (mutable), can perform pointer arithmetic
     *  *g - mid  - level - int* const (non-mutable), cannot perform pointer arithmetic
     * **g - int (mutable)
     */

    // type 9
    int* const* const h = &e;
    /* h is declared as constant pointer to a constant pointer to a integer
     *   h - base level - int* const *const - (non mutable/assignable) - no pointer arithmetic
     *  *h - mid level - int* const - (non mutable/assignable) - no pointer arithmetic
     * **h - int - mutable 
     */

    return 0;
}
