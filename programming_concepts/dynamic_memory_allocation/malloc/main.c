/* A c program to understand malloc */
#include <stdio.h>
#include <stdlib.h>
// Function declaration - print array
void print_array(int *array, int array_size);
// main function
int main(void)
{   
    int *pointer_variable = NULL;
    pointer_variable = (int*)malloc(5 * sizeof(int));
    // void* malloc (size_t size/*bytes*/);
    // https://cplusplus.com/reference/cstdlib/malloc/
    // On success, a pointer to the memory block allocated by the function.
    // The type of this pointer is always void*, which can be cast to the desired type of data pointer in order to be dereferenceable.
    //
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
    // Will have an undefined value, but the memory is made avaiable to be used
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
