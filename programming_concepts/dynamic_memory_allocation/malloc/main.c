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
    return 0;
}
// Function definition - print array
void print_array(int *array, int array_size)
{
    for(int element_index = 0; element_index < array_size; element_index++){
        *(array + element_index) = 6 * element_index;
        printf("Array[%2d] = %2d & address: %u\n", element_index, *(array + element_index), array + element_index);
    }
    printf("\n");
}
