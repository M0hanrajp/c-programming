#include <stdio.h>

void insertionSort(int *array_input, int array_size);

void swap(int *element_a, int *element_b);

void printArray(int *array_input, int array_size);

int main(void) {

    int array[] = {3, 4, 5, 1, 2}, result = 0;
    int array_size = sizeof(array)/sizeof(*array);
    printf("Input array:\n");printArray(array, array_size);
    printf("Output array:\n");insertionSort(array, array_size);printArray(array, array_size);
    return 0;
}

void insertionSort(int *array_input, int array_size) {
    for(int i = 1; i < array_size; i++) {
        int key = array_input[i], j = 0;
        j = i - 1;
        while (j >=0 && array_input[j] > key) {
            array_input[j + 1] = array_input[j];
            j = j - 1;
        }
        array_input[j + 1] = key;
    }
}

void swap(int *element_a, int *element_b) {
    int temp = 0;
    temp = *element_a;
    *element_a = *element_b;
    *element_b = temp;
}

void printArray(int *array_input, int array_size) {
    for(int i = 0; i < array_size; i++) 
        printf("a[%d] = %2d & add:%u\n", i, array_input[i], &array_input[i]);
    printf("\n");
}
