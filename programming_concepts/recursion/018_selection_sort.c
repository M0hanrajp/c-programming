#include <stdio.h>
#include <stdbool.h>
#define PRINT_ARR(arr, size) for(int i = 0; i < size; i++) { \
                                 printf("%d ", arr[i]);      \
                             }   printf("\n");


int idx = 0;
void selectionSortR(int *arr, int aSize, int minIndex, int col) {
    // exit condition
    if(idx > aSize - 1)
        return;
    // Body
    if(col < aSize) {
        if(arr[minIndex] > arr[col]) {
            minIndex = col;
        }
        selectionSortR(arr, aSize, minIndex, col + 1);
    } else {
        int temp = arr[idx];
        arr[idx] = arr[minIndex];
        arr[minIndex] = temp;
        minIndex = idx;
        idx++;
        selectionSortR(arr, aSize, minIndex + 1, minIndex + 1);
    }
}

// without extra variable, another solution
// takes the largest element and put it at it's right index
void selectionSortR2(int *arr, int row, int col, int max) {
    if(row == 0)
        return;
    if(col < row) {
        if(arr[col] > arr[max]) {
            selectionSortR2(arr, row, col + 1, col);
        } else {
            selectionSortR2(arr, row, col + 1, max);
        }
    } else {
        int temp = arr[row - 1];
        arr[row - 1] = arr[max];
        arr[max] = temp;
        selectionSortR2(arr, row - 1, 0, 0);
    }
}


int main(void) {
    int arr[] = {3, 0, 0, -5, 2, 1};
    int as    = sizeof(arr)/sizeof(*arr);
/* Without recursion, selection sort
    for(int i = 0; i < as; i++) {
        bool isSwap = false;
        int minIndex = i;
        for(int j = i + 1; j < as; j++) {
            if(arr[minIndex] > arr[j]) {
                minIndex = j;
                isSwap = true;
            }
        }
        if(isSwap) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            isSwap = false;
        }
        PRINT_ARR(arr, as);
    }
    PRINT_ARR(arr, as);
*/
    //selectionSortR(arr, as, 0, 1);
    selectionSortR2(arr, as, 0, 0);
    PRINT_ARR(arr, as);
    
    return 0;
}
