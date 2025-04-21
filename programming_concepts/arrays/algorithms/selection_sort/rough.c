#include <stdio.h>

void displayArray(int *arr, int s) {
    for(int i = 0; i < s; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int *arr, int s) {
    for(int i = 0; i < s; i++) {
        for(int j = i + 1; j < s; j++) {
            int temp = 0;
            if(arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        displayArray(arr, s);
    }
}

int main(void) {
    int arr[5] = {44, 33, 55, 22, 11};
    selectionSort(arr, sizeof(arr)/sizeof(*arr));
    return 0;
}
