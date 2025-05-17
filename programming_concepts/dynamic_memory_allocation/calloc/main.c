/* A c program to understand calloc */
#include <stdio.h>
#include <stdlib.h>
// Function declaration - print array
void print_array(int *array, int array_size);
// main function
int main(void)
{   
    int *pointer_variable = NULL;
    pointer_variable = (int*)calloc(5, sizeof(int)); /* number of elements * size of integer */
    // void* calloc (size_t num, size_t size);
    // Allocates a block of memory for an array of num elements, each of them size bytes long, and initializes all its bits to zero.
    // The effective result is the allocation of a zero-initialized memory block of (num*size) bytes.
    // If size is zero, the return value depends on the particular library implementation (it may or may not be a null pointer)
    // the returned pointer shall not be dereferenced.
    // If the function failed to allocate the requested block of memory, a null pointer is returned.
    if(pointer_variable == NULL) {
        printf("Memory allcoation failed!\n");
        exit(0);
    }
    else {
        printf("Memory allcoation success!\n");
        // printing the elements of array after memory allocation
        print_array(pointer_variable, 5);
    }
    free(pointer_variable);
    // https://cplusplus.com/reference/cstdlib/free/
    // void free (void* ptr);
    // If ptr does not point to a block of memory allocated with the above functions, it causes undefined behavior.
    // If ptr is a null pointer, the function does nothing.
    // Notice that this function does not change the value of ptr itself, hence it still points to the same (now invalid) location.
    printf("After freeing memroy of &pointer_variable = %p & *pointer_variable = %d\n", pointer_variable, *pointer_variable);
    // After freeing memroy of &pointer_variable = 0x55d42ae742a0 & *pointer_variable = 1564651124
    // Will have an undefined value
    return 0;
}
// Function definition - print array
void print_array(int *array, int array_size)
{
    for(int element_index = 0; element_index < array_size; element_index++){
        *(array + element_index) = 6 * element_index;
        printf("Array[%2d] = %2d & address: %p\n", element_index, *(array + element_index), array + element_index);
    }
    printf("\n");
}
