/* A c program to find the common array elements */
#include <stdio.h>
#include <strings.h>
// Funciton declaration - print array
void print_array(int *array, int array_size);
// Function declaration - Find the common elements
void common_elements(int *array, int array_size);
int main(void)
{
    int array[] = {2, 3, 4, 5, 3, 6, 3, 4, 4, 7, 8, 9, 1, 6, 7, 8};
    int array_size = sizeof(array)/sizeof(*array);
    printf("Entered array is:\n");print_array(array, array_size);
    printf("The following are the common elements in the array:\n");common_elements(array, array_size);
    return 0;
}
// Funciton definition - print array
void print_array(int *array, int array_size)
{
    for(int index = 0; index < array_size; index++)
        printf("A[%2d] = %2d & address: %u\n", index, *(array + index), array + index);
    printf("\n");
}
// Function definition - Find the common elements
void common_elements(int *array, int array_size)
{
    int repeat_element_flag = 0;
    for(int selected_element = 0; selected_element < array_size; selected_element++)
    {
        int element_count = 0;
        for(int subscript = 1; subscript < array_size; subscript++)
        {
                if(*(array + selected_element) == *(array + subscript))
                    element_count++;
                    if(element_count > 2)
                        repeat_element_flag = *(array + selected_element);
        }
        if(element_count > 2)
            printf("%2d occurred %2d times\n", *(array + selected_element), element_count);
    }
}
