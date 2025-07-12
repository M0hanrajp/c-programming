/* A c program to implement binary search 
 * What: For a given sorted array either in descending or ascending
 * 1. divide the array in two halves
 * 2. compare the middle element with the target element
 * 2a. check if target element is greater or smaller than middle elememt
 * 2b. if target element greater than middle element it will be present on right side of array else left side.
 * so search for the element but from start index and end index should be modified according to postion of target element.
 * // TODO: why
 * Why: In linear search where we are making multiple comparison for each pass.
 * Time complexity 
 * */
#include <stdio.h>
#include <strings.h>
#include <stdbool.h>

// Function declarations  
void bubble_sort(int *input_array, int array_size);
void swap(int *variable_a, int *variable_b);
void display_array(int *array_element, int array_size);
int binary_search(int *array, int low, int high, int *find_element);
int orderAgnosticBinarySearch(int *array, int low, int high, int *find_element);

int main(void) {

    int array[] = {-1, -45, 45, 66}, result = 0;
    int arrSize = sizeof(array)/sizeof(*array);

    int search_element = 45;
    printf("Initialized array:\n");display_array(array, arrSize);
    // Case 1: if the array you are changing in the code will be unsorted
    // bubble_sort(array, 10);
    // printf("Initialized array is sorted into ascending order\n");display_array(array, 10);
    // result = binary_search(array, 0, arrSize - 1, &search_element);
    // Case 2: NOTE:if array is sorted but you dont know in which order the array is sorted
    result = orderAgnosticBinarySearch(array, 0, arrSize - 1, &search_element);
    result == -1 ? printf("Element was not found in the provided array!\n")
                 : printf("Element was found in the array at index %d\n", result);
    return 0;
}

// Function definition for sorting the array
// When you have been given an unsorted array you can sort it using the below function
// Note it sorts in ascending order
void bubble_sort(int *input_array, int array_size)
{
    for(int index = 0; index < array_size; index++) {
        for(int elements = 1; elements < array_size - index; elements++) {
            if(input_array[elements] < input_array[elements - 1]) {
                swap(&input_array[elements], &input_array[elements - 1]);
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
    for(int subscript = 0; subscript < array_size; subscript++) {
        printf("A[%2d] = %2d & address: %p\n", subscript, *(array_element + subscript), array_element + subscript);
    }
}

// Function definition for binary search
// this is used when the array is sorted in ascending order
int binary_search(int *array, int low, int high, int *find_element)
{
    while(low <= high) {
        int mid = low + (high - low)/2; // if the integer is very large
                                        // Also when element is at last index
                                        // this particular operation, based on precedence, the (high - low)/2 becomes 0.
                                        // then we move to assigning low as mid + 1 giving us the last index.
        // Return that the element was found
        if(*find_element == array[mid])
            return mid;

        /* if the element value is greater than the middle element of the array 
         * then we need to compare the right half of the array after the middle 
         * element which will help shorten the path to find the element.
         * so here we use low (left indexer of array to move towards the desired search space) */
        if(*find_element > array[mid])
            low = mid + 1;

        /* if the element is found to be smaller than the middle element then its
         * found to be at the left side of the array hence we move the high (right indexer
         * to the left side of the search space array ) */
        else
            high = mid - 1;
    }
    return -1;
}

// When you do not know the array is sorted in ascending or descending order
int orderAgnosticBinarySearch(int *array, int low, int high, int *find_element) {
    
    /* if the array is in ascending order , array[low] < array[high]
     * if the array is in descending order, array[low] > array[high]
     * if array[low] == array[high], then all elements are same
     */
    bool isAscending = array[low] < array[high];

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if(array[mid] == *find_element)
            return mid;

        if(isAscending) {
            if(*find_element > array[mid])
                low = mid + 1;
            else
                high = mid - 1;
        } else {
            // descending order
            // all elements greater than mid will be to the left
            // so search to the left else search to the right
            if(*find_element > array[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }

    }

    return -1;
}
