// program to understand dangling pointers
#include <stdio.h>
#include <stdlib.h>

#define cFree(x) safeFreeMemory((void **)&x)

/* Dangling pointers,
 * Variable which can be modified by the program after variable is freed using free().
 * Does it apply only to the variable that have been allocated memory using calloc, malloc ?
 */

// A safe version of the free function that accesses the pointer that pointer
// to a pointer parameter ptr points to and 1) frees the block of memory the 
// pointer points to, 2) sets the pointer to NULL to prevent and dangling 
// pointer.
void safeFreeMemory(void **p /*double pointer because we pass the address of pointer */) {
    free(*p);
    *p = NULL;
}

int main(void) {
    int *ptr;
    /* ptr is block scope, no linkage, auto storage duration, undefined behavior when accessed, NIL (what variable contains)
     * dereferecning the variable and accessing it's content at this stage causes seg fault*/
    printf("intitial value of ptr = %p\n", ptr);

    ptr = (int *)malloc(sizeof(int));
    *ptr = 8;
    printf("value of ptr after malloc = %p & value of *ptr = %d\n", ptr, *ptr);

    // free(ptr);
    /* after free deallocates ptr, address remains same, value of *ptr is indeterminate 
     * memory is avaiable for program to be used for computing/assigning a value.
     * Since this memory is accessible by the program to be modified, ptr is called a dangling pointer
     * we can overcome this by assigning the variable to NULL after it has been freed (by using a custom function)
     * Output when using only free:
     * value of ptr after free() = 0x56336fb756b0 & value of *ptr = 1664547701 (already *ptr has some indeterminate value)
     */
    //safeFreeMemory((void **)&ptr);
    cFree(ptr);
    printf("value of ptr after cfree() = %p\n", ptr);
    /* output after using cFree:
     * value of ptr after cFree() = (nil) */

    return 0;
}
