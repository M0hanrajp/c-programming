/* A c program to implement binary search */
#include <stdio.h>
#include <strings.h>
// Function declaration for sorting the array in ascending order 
void bubble_sort(int *input_array, int array_size);
// Function declaration for swap
void swap(int *variable_a, int *variable_b);
// Funciton declaration to display array
void display_array(int *array_element, int array_size);
// Function declaration for binary search
int binary_search(int *array, int low, int high, int *find_element);
int main(void)
{
    int array[10] = {2, 5, -3, -4, 6, 7, 9, 0, 8, 1}, search_element = 0, result = 0;
    printf("Enter any element < 10: ");
    scanf("%d", &search_element);
    printf("Initialized array:\n");display_array(array, 10);
    bubble_sort(array, 10);
    printf("Initialized array is sorted into ascending order\n");display_array(array, 10);
    result = binary_search(array, 0, 10, &search_element);
    result == -1 ? printf("Element was not found in the provided array!\n")
                : printf("Element was found in the array at index %d\n", result);
    return 0;
}
// Function definition for sorting the array
void bubble_sort(int *input_array, int array_size)
{
    for(int index = 0; index < array_size; index++)
    {
        for(int elements = 1; elements < array_size - index; elements++)
        {
            if(*(input_array + elements) < *(input_array + elements - 1))
            {
                swap(&(*(input_array + elements)), &(*(input_array + elements - 1)));
            }
        }
    }
}
// Function definition for swapping elements
void swap(int *variable_a, int *variable_b)
{
    int temp = 0;
    temp = *variable_a;
    *variable_a = *variable_b;
    *variable_b = temp;
}
// Function definition for printing array elements
void display_array(int *array_element, int array_size)
{
    for(int subscript = 0; subscript < array_size; subscript++)
    {
        printf("A[%2d] = %2d & address: %u\n", subscript, *(array_element + subscript), array_element + subscript);
    }
}
// Function definition for binary search
int binary_search(int *array, int low, int high, int *find_element)
{
    while(low <= high)
    {
        int mid = low + (high - low)/2;
        // Return that the element was found
        if(*find_element == *(array + mid))
            return mid;
        /* if the element value is greater than the middle element of the array 
         * then we need to compare the right half of the array after the middle 
         * element which will help shorten the path to find the element.
         * so here we use low (left indexer of array to move towards the desired search space) */
        if(*find_element > *(array + mid))
            low = mid + 1;
        /* if the element is found to be smaller than the middle element then its
         * found to be at the left side of the array hence we move the high (right indexer
         * to the left side of the search space array ) */
        else
            high = mid - 1;
    }
    return -1;
}
