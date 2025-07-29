#include <stdio.h>
#define PRINT_ARR(arr, size) for(int i = 0; i < size; i++) { \
                                 printf("%d ", arr[i]);      \
                             }   printf("\n");


void bubbleSortR(int *arr, int aSize, int col) {
    // exit condition
    if(aSize == 0)
        return;
    // Body
    if(col < aSize) {
        if(arr[col - 1] > arr[col]) {
            int temp = arr[col];
            arr[col] = arr[col - 1];
            arr[col - 1] = temp;
        }
        // the inner loop compares the elements and sorts them
        // after the first iteration the largest element will be 
        // at the last position.
        bubbleSortR(arr, aSize, col + 1);
    } else {
        // the outer loop decreases the size of array by 1, as the
        // largest elemnet will be at it's correct position
        bubbleSortR(arr, aSize - 1, 1);
    }
}

int main(void) {
    int arr[] = {4, 3, 0, 0, 0, 5, 2, 1};
    int as    = sizeof(arr)/sizeof(*arr);
/* without recursion, bubble sort program (without optimizations)
    for(int i = 0; i < as; i++) {
        for(int j = 1; j < as - i; j++) {
            if(arr[j - 1] > arr[j]) {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
        PRINT_ARR(arr, as);
    }
    PRINT_ARR(arr, as);
*/
    bubbleSortR(arr, as, 1);
    PRINT_ARR(arr, as);
    return 0;
}
