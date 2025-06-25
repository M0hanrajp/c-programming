#include <stdio.h>

int calSumOfArray(int *arr, int size) {
    if(size <  0)
        return 0;
    if(size == 0)
        return arr[0];
    return calSumOfArray(arr, size - 1) + calSumOfArray(arr, size - 2);
}

int main(void) {
    int arr[] = {1, 1, 1, 1};
    printf("The sum of array using recursion is: %d\n", calSumOfArray(arr, 4));
    return 0;
}
