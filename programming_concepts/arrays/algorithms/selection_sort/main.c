/* A C program to implement selection sort in ascending order
 *
 * Note if decesending order is required then :
 * input_array[j] > input_array[min_index] condition needs to 
 * be changed in this manner so that the largest element will 
 * be sorted a the first index of the array 
 */
#include <stdio.h>

// Function declaration - Sort array using selection sort
void selectionSort(int *input_array, int array_size);

// Function declaration - to display
void displayArray(int *input_array, int array_size);

// Function declaration - swap two elements
void swap(int *element_a, int *element_b);

int main(void) {
    int array[] = {1, 2, 3, 4, 5}, result = 0;
    int array_size = sizeof(array)/sizeof(*array);
    printf("Default array input:\n");displayArray(array, array_size);
    selectionSort(array, array_size);
    printf("Sorted array output:\n");displayArray(array, array_size);
    return 0;
}

// Function definition - Sort array using selection sort
void selectionSort(int *input_array, int array_size) {
    /* This will hold the index of the array elements from
     * the start and will be assigned new values if element
     * was found smaller than current element 
     */
    int min_index = 0;
    for(int i = 0; i < array_size; i++) {
        min_index = i;
        for(int j = i + 1; j < array_size; j++) {
            // compare rest of the elements with selected element
            if(input_array[j] > input_array[min_index])
                /* After the whole loop is traversed min_index will
                 * have the shortest element index value */
                min_index = j;
        }
        /* swap with the chosen index so smallest element will be
         * sorted from the start of the array.
         *
         * note: end of 1st pass smallest element is sorted at first index
         */
        swap(&input_array[i], &input_array[min_index]);
        displayArray(input_array, array_size); // debugging purpose
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
