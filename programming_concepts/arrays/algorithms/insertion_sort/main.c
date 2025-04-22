/* Insertion sort
 * What: insert the choosen element at the left hand side of the array which is sorted.
 * You start from left most 0th index + 1 element and sort the first two.
 * so left side is sorted.
 * Continue to the next element and put it in (sorted array) correct position.
 * 
 * Why: After iteration 1, first two indexs of the array will be sorted. (left side)
 * After second pass first 3 index elements will be sorted.
 * Last element does not need any sorting as it will be greater once outermost loop reaches n - 1 value.
 * Hence outermost loop runs till length - 1.
 * Inner most loop will be outermost loop value + 1 & will decrement (sort the left side)
 *
 * Less swaps are used,
 * when array is sorted, steps are reduced
 * https://www.geeksforgeeks.org/insertion-sort-algorithm/
 */

#include <stdio.h>

// Function declaration - sort an array using insertion sort
void insertionSort(int *arr, int array_size);

// Function declaration - to display
void displayArray(int *arr, int array_size);

// Function declaration - to swap elements
void swap(int *element_a, int *element_b);

int main(void)
{
    int array[] = {1, 2, -3, -4, 0};
    int array_size = sizeof(array)/sizeof(*array);
    printf("Array input: \n");displayArray(array, array_size);
    insertionSort(array, array_size);
    printf("Sorted output: \n");displayArray(array, array_size);
    return 0;
}

// Function definition - sort an array using insertion sort
void insertionSort(int *arr, int array_size) {
    for(int i = 0; i < array_size - 1; i++) {
        printf("Iteration :: %d\n", i);
        // start j from start index + 1 and sort the array to the left
        // by comparing j - 1 elements, put j element at it's right position
        for(int j = i + 1; j > 0; j--) {
            if(arr[j] < arr[j - 1]) {
                swap(&arr[j], &arr[j - 1]);
            } else {
                break; /* if the element which is selected for comparison is not greater than it's j - 1
                             element then skip becuase left side array is already sorted. */
            }
            displayArray(arr, array_size);
        }
    }
}

// Function definiton - to display
void displayArray(int *arr, int array_size) {
    for(int index = 0; index < array_size; index++)
        printf("A[%d] = %d & addr: %p\n", index, arr[index], &arr[index]);
    printf("\n");
}

// Function definition - swap elements
void swap(int *element_a, int *element_b) {
    int temp = *element_a;
    *element_a = *element_b;
    *element_b = temp;
}

// output:
/* 

   Array input:
A[0] = 2 & addr: 0x7ffeed083cb0
A[1] = 1 & addr: 0x7ffeed083cb4
A[2] = 3 & addr: 0x7ffeed083cb8
A[3] = 5 & addr: 0x7ffeed083cbc
A[4] = 4 & addr: 0x7ffeed083cc0

Iteration :: 1
A[0] = 1 & addr: 0x7ffeed083cb0
A[1] = 2 & addr: 0x7ffeed083cb4
A[2] = 3 & addr: 0x7ffeed083cb8
A[3] = 5 & addr: 0x7ffeed083cbc
A[4] = 4 & addr: 0x7ffeed083cc0

Iteration :: 2 
// Means till index 3, as we can see above till index 3 all elements are sorted.

Iteration :: 3
A[0] = 1 & addr: 0x7ffeed083cb0
A[1] = 2 & addr: 0x7ffeed083cb4
A[2] = 3 & addr: 0x7ffeed083cb8
A[3] = 4 & addr: 0x7ffeed083cbc
A[4] = 5 & addr: 0x7ffeed083cc0

Sorted output:
A[0] = 1 & addr: 0x7ffeed083cb0
A[1] = 2 & addr: 0x7ffeed083cb4
A[2] = 3 & addr: 0x7ffeed083cb8
A[3] = 4 & addr: 0x7ffeed083cbc
A[4] = 5 & addr: 0x7ffeed083cc0

*/
