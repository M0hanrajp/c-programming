/* A C program to implement insertion sort in ascending order */

#include <stdio.h>

// Function declaration - sort an array using insertion sort
void insertionSort(int *input_array, int array_size);

// Function declaration - to display
void displayArray(int *input_array, int array_size);

// Function declaration - to swap elements
void swap(int *element_a, int *element_b);

int main(void)
{
    int array[] = {2, 1, 3, 5, 4};
    int array_size = sizeof(array)/sizeof(*array);
    printf("Array input: \n");displayArray(array, array_size);
    insertionSort(array, array_size);
    printf("Array output: \n");displayArray(array, array_size);
    return 0;
}

// Function definition - sort an array using insertion sort
void insertionSort(int *input_array, int array_size) {
    for(int i = 1; i < array_size; i++) {
        /* assign the value of array element to variable element to compare */
        int element = input_array[i], j = 0;
        j = i - 1;
        /* As long as current element(j) is larger than selected element
         * keep shifting the elements to the right */
        while (j >= 0 && input_array[j] > element) {
            input_array[j + 1] = input_array[j];
            j = j - 1;
            displayArray(input_array, array_size);
        }
        // correct position of element after shifiting is done or 
        // no elements were shifted.
        input_array[j + 1] = element;
        displayArray(input_array, array_size);
    }
}

// Function definiton - to display
void displayArray(int *input_array, int array_size) {
    for(int index = 0; index < array_size; index++)
        printf("A[%d] = %d & addr: %u\n", index, input_array[index], &input_array[index]);
    printf("\n");
}

// Function definition - swap elements
void swap(int *element_a, int *element_b) {
    int temp = *element_a;
    *element_a = *element_b;
    *element_b = temp;
}
