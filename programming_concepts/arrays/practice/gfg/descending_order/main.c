/* A c program to sort elements of the array into descending order
 * Selection sort is used for arranging the elements into descending order 
 */
#include <stdio.h>
// Function declaration - swap elements
void swap(int *element_a, int *element_b);
// Function declaration - display array
void print_array(int *array, int array_size);
// Function declaration - selection sort array
void selection_sort(int *array, int array_size);
// Main function
int main(void)
{
    int array[] = {-1, -9, -6, -8, 4, 5, 2, 9, 1, 1, 0};
    int array_length = sizeof(array)/sizeof(*array);
    printf("Default input array:\n");print_array(array, array_length);
    selection_sort(array, array_length);printf("Sorted array:\n");print_array(array, array_length);
    return 0;
}
// Function declaration - swap elements
void swap(int *element_a, int *element_b)
{
    int temp = 0;
    temp = *element_a;
    *element_a = *element_b;
    *element_b = temp;
}
// Function declaration - display array
void print_array(int *array, int array_size)
{
    for(int index = 0; index < array_size; index++)
    {
        printf("M[%2d] = %2d & address: %u\n", index, *(array + index), array + index);
    }
    printf("\n");
}
// Function declaration - selection sort array
void selection_sort(int *array, int array_size)
{
    for(int selected_element = 0; selected_element < array_size - 1; selected_element++)
    {
        for(int compare_element = selected_element + 1; compare_element < array_size; compare_element++)
        {
            if(*(array + compare_element) < *(array + compare_element - 1))
            {
                swap(&(*(array + compare_element - 1)), &(*(array + compare_element)));
            }
        }
    }
}
