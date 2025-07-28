#include <stdio.h>
#include <stdbool.h>

bool isArraySorted(int *arr, int s, int i, bool res) {
    /* if array has one element return true as it's sorted */
    if(s < 1)
        return res;
    /* We are considering that array is sorted initially
     * if we find elements that are unsorted we make the res false
     * the below condition will make sure to end the recursive calls
     * to check sorting of elements
     */
    if(!res)
        return res;
    // end recursive calls when i exceeds last index of array
    if(i == s)
        return res;
    // compare elements and update the result
    if(arr[i - 1] > arr[i])
        return isArraySorted(arr, s, i + 1, false);
    // if elements being compared are same then keep the result as true
    else if(arr[i - 1] == arr[i])
        return isArraySorted(arr, s, i + 1, true);
    return isArraySorted(arr, s, i + 1, true);
}

bool isArraySortedMethod(int *arr, int s, int i) {
    if(i == s - 1) {
        return true;
    }
    return arr[i] <= arr[i + 1] && isArraySortedMethod(arr, s, i + 1);
}

int main(void) {
    int arr[] = {0, 9, 9, 10, 11};
    isArraySorted(arr, sizeof(arr)/sizeof(*arr), 1, true) ?
    printf("Array is sorted\n") : printf("Array unsorted\n");

    isArraySortedMethod(arr, sizeof(arr)/sizeof(*arr), 0) ?
    printf("Array is sorted\n") : printf("Array unsorted\n");
    return 0;
}
