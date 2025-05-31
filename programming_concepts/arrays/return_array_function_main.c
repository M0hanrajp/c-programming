#include <stdio.h>
int* f(); 
/* declare f as function returning pointer to int (don't confuse with function pointers they are different)
 * so when the array is being returned from function
 * starting address of the element is returned.
 *
 * Note:
 * When you return a scalar type (like an int or float) from a function, even if it was stored on the stack,
 * the compiler copies its value into a CPU register before tearing down the function’s stack frame.
 * The caller then gets the value directly from that register, so it never tries to read from the old
 * (now-invalid) stack slot.
 *
 * In this program, however, we return a pointer to an integer that was allocated on the stack:
 *   - In f(), we create an array (or int) on the stack.
 *   - When f() finishes, its stack frame is popped, and that memory is reclaimed.
 *   - Returning a pointer to that stack memory gives the caller an address pointing to freed space.
 *   - Reading or writing through that pointer is undefined behavior, because the memory no longer belongs to your variable.
 *
 * To fix this, you can:
 *   1. Make the array (or variable) static inside f(), so it lives for the lifetime of the program:
 *        static int arr[SIZE];
 *      In that case, arr is stored in static data, not on the stack, and returning its address is safe.
 *
 *   2. Allocate memory on the heap instead (using malloc or calloc), which also outlives f():
 *        int *arr = malloc(SIZE * sizeof(int));
 *      Then returning arr gives the caller a valid pointer until you explicitly free() it.
 */

int main(void)
{
    int *arr = f();
    printf("arr is passed from f() to main()\n");
    for(int i = 0; i < 5; i++)
    {
        printf("arr[%d] = %d & address: %p\n", i, *(arr + i), (arr + i));
    }
    return 0;
}
int* f()
{
    static int arr[5] = {1, 2, 3, 4, 5};
    printf("Address of arr in f(), %p\n", arr);
    return arr;
}
// output
/*
Address of arr in f(), 0x55900ff6a010
arr is passed from f() to main()
arr[0] = 1 & address: 0x55900ff6a010
arr[1] = 2 & address: 0x55900ff6a014
arr[2] = 3 & address: 0x55900ff6a018
arr[3] = 4 & address: 0x55900ff6a01c
arr[4] = 5 & address: 0x55900ff6a020
*/
