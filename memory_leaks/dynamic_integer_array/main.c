#include <stdio.h>
#include <stdlib.h>

void create_integer_array(int size) {
    int *int_array = (int *)malloc(size * sizeof(int));
    if (!int_array) {
        printf("Memory allocation failed\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        int_array[i] = i * 2;
    }

    for (int i = 0; i < size; i++) {
        printf("%d ", int_array[i]);
    }
    printf("\n");
    free(int_array);
}

int main() {
    create_integer_array(10);
    return 0;
}

