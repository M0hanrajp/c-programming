#include <stdio.h>

int binarySearch(int *arr, int target, int s, int e) {
    if(s > e) {
        return -1;
    }

    int m = s + (e - s) / 2;
    if(arr[m] == target) {
        return m;
    }

    if(target <= arr[m] && target >= arr[s]) {
        return binarySearch(arr, target, s, m - 1);
    } else {
        return binarySearch(arr, target, m + 1, e);
    }

    if(target >= arr[m] && target <= arr[e]) {
        return binarySearch(arr, target, m + 1, e);
    }
    return binarySearch(arr, target, s, m - 1);
}


int main(void) {
    /* Rotated array
     * =============
     * A rotated array is just a sorted array that’s been “wrapped around” at some pivot.
     * It isn’t arbitrary: it always consists of two sorted segments.
     * That structural guarantee lets you adapt binary search for fast lookups in O(log n).
     */
    int arr[] = {5, 6, 7, 8, 9, 1, 2, 3};
    printf("target %d found at %d\n", 1, binarySearch(arr, 1, 0, sizeof(arr)/sizeof(*arr) - 1));
    return 0;
}
