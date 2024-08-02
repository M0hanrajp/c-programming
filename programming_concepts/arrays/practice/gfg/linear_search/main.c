/* A C program to learn linear search algorithm */

#include <stdio.h>

// Function declaration - Linear search
int linearSearchAlgorithm(int *array, int array_size, int *search_element);

int main(void) {

    int array[] = {10, 50, 30, 70, 80, 20, 90, 40}, key = 0, result = 0;
    int array_size = sizeof(array)/sizeof(*array);
    printf("Enter key to be found :: ");scanf("%d", &key);
    result = linearSearchAlgorithm(array, array_size, &key);
    if(result != -1) {
        printf("The element was found at %d index in the array\n", result);
    }
    else 
        printf("There was no element found in the array!\n");
    return 0;
}

// Function declaration - Linear search
int linearSearchAlgorithm(int *array, int array_size, int *search_element) {
    for(int element_index = 0; element_index < array_size; element_index++) {
        if(*search_element == array[element_index]) {
            return element_index;
            break;
        }
    }
    return -1;
}


