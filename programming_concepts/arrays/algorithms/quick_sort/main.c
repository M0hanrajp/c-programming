/* Program to understand quick sort:
 * What: sort an unsorted array using quick sort
 * How: Choose a pivot, 
 *      a. move all the elements smaller than pivot to the LHS.
 *      b. move all the elements greater than pivot to the RHS.
 * Call recursive calls to LHS and RHS so that they are sorted.
 *
 * When: start <= end
 */
#include <stdio.h>
#define SIZE 4
#define PRINT(arr) for(int i = 0; i < SIZE; i++) { \
                       printf("%d ", arr[i]);      \
                   } printf("\n");                 \

void quickSort(int *arr, int low, int high) {
    int start = low;
    int end = high;
    int mid = low + (high - low) / 2;
    int pivot = arr[mid]; // any pivot is fine

    // low cannot be greater than high (recursive exit condition)
    if(low >= high) {
        return;
    }

    /* Take two variables to track start and end of the array,
     * use pivot and swap the array elements if they are larger/smaller than pivot
     * quit the loop once start > end */
    while (start <= end) {
        // If LHS element is smaller than pivot then ok, move ahead
        while (arr[start] < pivot) {
            start++;
        }
        // If RHS element is greater than pivot then ok, move ahead
        while (arr[end] > pivot) {
            end--;
        }
        // If the start and end elements are not at their corresponding
        // positions, swap them.
        if(start <= end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }
    /* After swapping the array for the first time,
     * we will have all the elements shorter than pivot in LHS
     * all elements larger than pivot on RHS.
     * recursive calls on LHS and RHS and perform the operation until array is sorted
     */
    quickSort(arr, low, end); // sort LHS
    quickSort(arr, start, high); // sort RHS
}

int main(void) {
    int a[SIZE] = {4, 3, -1, 1};
    quickSort(a, 0, SIZE - 1);
    PRINT(a);
    return 0;
}
