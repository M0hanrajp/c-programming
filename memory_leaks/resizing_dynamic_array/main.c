#include <stdio.h>
#include <stdlib.h>

int* resize_array(int *array, int old_size, int new_size) {
    int *new_array = (int *)malloc(new_size * sizeof(int));
    if (!new_array) {
        printf("Memory allocation failed\n");
        exit(0);
    }
    int i = 0;
    for (i = 0; i < old_size; i++)
        new_array[i] = array[i];
    for(i = old_size; i < new_size; i++)
        new_array[i] = i;
    return new_array;
}

int main() {
    int *array = (int *)malloc(5 * sizeof(int));
    if (!array) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < 5; i++) {
        array[i] = i + 1;
    }
    int *resized_array = resize_array(array, 5, 10);
    if (resized_array) {
        for (int i = 0; i < 10; i++) {
            printf("%d ", resized_array[i]);
        }
        printf("\n");
    }
    free(array);
    free(resized_array);
    return 0;
}

