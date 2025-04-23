/* Cyclic sort
 * What: When given numbers from range 1 to N use cyclic sort (VIMP) (when the range is 1 to N) only
 * Since numbers are 1 to N, each index has value - 1, where value is the element for example
 *           index 0  1  2  3  4 
 * array elemenets 1, 2, 3, 4, 5 (sorted), index is element - 1
 * So from any unsorted array we need to put the elements at their right index
 *
 * why: put the element at it's right index and swap that element, loop is not incremented
 * until the loop's index has proper element.
 * i is only incremented when i has arr[i] == i + 1 
 */

#include <stdio.h>

// Function definiton - to display
void displayArray(int *arr, int array_size) {
    for(int index = 0; index < array_size; index++)
        printf("A[%d] = %d & addr: %p\n", index, arr[index], &arr[index]);
    printf("\n");
}

// Function definition - cyclic sort 
void CyclicSort(int *arr, int n) {
    int i = 0;
    while (i < n) {
        int correctIndex = arr[i] - 1;
        if(arr[i] != arr[correctIndex]) {
            int temp = arr[correctIndex];
            arr[correctIndex] = arr[i];
            arr[i] = temp;
        } else {
            i++;
        }
        displayArray(arr, n); // for debugging purposes
    }
}

int main(void) {
    int arr[5] = {3, 5, 2, 1, 4};
    CyclicSort(arr, 5);
    return 0;
}
