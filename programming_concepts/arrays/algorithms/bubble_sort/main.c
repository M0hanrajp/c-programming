/* A C program to sort an array using bubble sort in ascending order :
 *
 * note that if we compare adjacent elements with different condition
 * i.e. let's consdier the logic has been made greater than (as below)
 * input_array[j] > input_array[j - 1]
 * then the output will be an array sorted in descending order
 */
#include <stdio.h>
#define SIZE 5

// Function declaration - bubble sort
int bubbleSort(int *input_array, int array_size);

// Function definiton - to display array
void displayArray(int *input_array, int array_size);

// Function declaration - swap elements
void swap(int *element_a, int *element_b);

int main(void) {
    int array[SIZE] = {1, 2, 3, 4, 5}, result = 1;
    printf("Array input: \n");
    displayArray(array, SIZE);
    result = bubbleSort(array, SIZE);
    // result = 0 means there was no swap performed meaning array is already sorted
    if(result > 0) {
        printf("After bubble sort: \n");
        displayArray(array, SIZE);
    }
    else
        printf("Entered Array is already sorted!!\n");
    return 0;
}

// Function definition - bubble sort
int bubbleSort(int *input_array, int array_size) {
    int swap_count = 0;
    for(int i = 0; i < array_size; i++) {
        for(int j = 1; j < array_size - i; j++) {
            /* Compare tow adjacent elements
             * Make sure that the largest element is swapped to the higher
             * index element, this way after first iteration the highest 
             * element is sorted at the last position of the array in first pass.
            */
            if(input_array[j] < input_array[j - 1]) {
                swap(&input_array[j], &input_array[j - 1]);
                swap_count++;
                // For debugging purpose only, comment below line code for clean output
                displayArray(input_array, array_size);
            }
        }
        /* The below swap condition works:
         * when we enter inside the 2nd loop and when the 2nd loop starts 
         * traversing for any element to swap, if there is no element to 
         * be swapped that means the array is already sorted.
         */
        if(swap_count == 0) break; // Optimization: Stop if no elements were swapped
    }
    return swap_count;
}

// Function definition - to display array
void displayArray(int *input_array, int array_size) {
    for(int i = 0; i < array_size; i++)
        printf("Array[%d] = %d & address: %u\n", i, input_array[i], &input_array[i]);
    printf("\n");
}

// Function definition - swap elements
void swap(int *element_a, int *element_b) {
    int temp = *element_a;
    *element_a = *element_b;
    *element_b = temp;
}
