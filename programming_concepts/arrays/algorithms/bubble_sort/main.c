/* A C program to sort an array using bubble sort in ascending order :
 * Bubble sort (also known as Sinking sort or Exchange sort)
 * What: Compare adjacent element and check if smaller/greater then swap the element.
 * why: the largest element is at the end of array if > is used for comparison after 1st iteration
 *      the smallest element is at the end of array if < is used for comparing elements.
 * for the inner loop, you don't parse the entire loop as the array from last is being sorted.
 * i.e. largest will not swap with any other element.
 * When > is used for comparing elements you are sorting in ascending (smaller)
 * When < is used for comparing elements you are sorting in descending (smaller)
 * for more theory https://www.geeksforgeeks.org/bubble-sort-algorithm/
 */
#include <stdio.h>
#include <stdbool.h>

#define SIZE 5

// Function declaration - bubble sort
int bubbleSort(int *arr, int array_size);

// Function declaration - to display array
void displayArray(int *arr, int array_size);

// Function declaration - swap elements
void swap(int *element_a, int *element_b);

int main(void) {
    int array[SIZE] = {4, 3, 5, 1, 2};
    bool result = false;
    printf("Array input: \n");
    displayArray(array, SIZE);
    result = bubbleSort(array, SIZE);
    // result = 0 means there was no swap performed meaning array is already sorted
    if(result) {
        printf("After bubble sort: \n");
        displayArray(array, SIZE);
    }
    else
        printf("Entered Array is already sorted!!\n");
    return 0;
}

// Function definition - bubble sort
int bubbleSort(int *arr, int array_size) {
    bool swapFlag = false;
    for(int i = 0; i < array_size; i++) {
        printf("Iteration :: %d\n", i + 1);
        for(int j = 1; j < array_size - i; j++) {
            /* Compare tow adjacent elements
             * Make sure that the largest element is swapped to the higher
             * index element, this way after first iteration the highest 
             * element is sorted at the last position of the array in first pass.
            */
            if(arr[j] < arr[j - 1]) {
                swap(&arr[j], &arr[j - 1]);
                swapFlag = true;
            }
            // For debugging purpose only, comment below line code for clean output
            displayArray(arr, array_size);
        }
        /* Optimization: Stop if no elements were swapped
         * in the case where the input is already sorted when the program
         * counter enters second loop and if no swap occurrs then swapFLag will not be true.
         * If there was no swap it means that array is already sorted.
         */
        if(!swapFlag) 
            break;
    }
    return swapFlag;
}

// Function definition - to display array
void displayArray(int *arr, int array_size) {
    for(int i = 0; i < array_size; i++)
        printf("Array[%d] = %d & address: %p\n", i, arr[i], &arr[i]);
    printf("\n");
}

// Function definition - swap elements
void swap(int *element_a, int *element_b) {
    int temp = *element_a;
    *element_a = *element_b;
    *element_b = temp;
}

// output
/*
Array input:
Array[0] = 4 & address: 0x7fffbc0dfcc0
Array[1] = 3 & address: 0x7fffbc0dfcc4
Array[2] = 5 & address: 0x7fffbc0dfcc8
Array[3] = 1 & address: 0x7fffbc0dfccc
Array[4] = 2 & address: 0x7fffbc0dfcd0

Iteration :: 1
Array[0] = 3 & address: 0x7fffbc0dfcc0
Array[1] = 4 & address: 0x7fffbc0dfcc4
Array[2] = 5 & address: 0x7fffbc0dfcc8
Array[3] = 1 & address: 0x7fffbc0dfccc
Array[4] = 2 & address: 0x7fffbc0dfcd0

Array[0] = 3 & address: 0x7fffbc0dfcc0
Array[1] = 4 & address: 0x7fffbc0dfcc4
Array[2] = 5 & address: 0x7fffbc0dfcc8
Array[3] = 1 & address: 0x7fffbc0dfccc
Array[4] = 2 & address: 0x7fffbc0dfcd0

Array[0] = 3 & address: 0x7fffbc0dfcc0
Array[1] = 4 & address: 0x7fffbc0dfcc4
Array[2] = 1 & address: 0x7fffbc0dfcc8
Array[3] = 5 & address: 0x7fffbc0dfccc
Array[4] = 2 & address: 0x7fffbc0dfcd0

Array[0] = 3 & address: 0x7fffbc0dfcc0
Array[1] = 4 & address: 0x7fffbc0dfcc4
Array[2] = 1 & address: 0x7fffbc0dfcc8
Array[3] = 2 & address: 0x7fffbc0dfccc
Array[4] = 5 & address: 0x7fffbc0dfcd0

Iteration :: 2
Array[0] = 3 & address: 0x7fffbc0dfcc0
Array[1] = 4 & address: 0x7fffbc0dfcc4
Array[2] = 1 & address: 0x7fffbc0dfcc8
Array[3] = 2 & address: 0x7fffbc0dfccc
Array[4] = 5 & address: 0x7fffbc0dfcd0

Array[0] = 3 & address: 0x7fffbc0dfcc0
Array[1] = 1 & address: 0x7fffbc0dfcc4
Array[2] = 4 & address: 0x7fffbc0dfcc8
Array[3] = 2 & address: 0x7fffbc0dfccc
Array[4] = 5 & address: 0x7fffbc0dfcd0

Array[0] = 3 & address: 0x7fffbc0dfcc0
Array[1] = 1 & address: 0x7fffbc0dfcc4
Array[2] = 2 & address: 0x7fffbc0dfcc8
Array[3] = 4 & address: 0x7fffbc0dfccc
Array[4] = 5 & address: 0x7fffbc0dfcd0

Iteration :: 3
Array[0] = 1 & address: 0x7fffbc0dfcc0
Array[1] = 3 & address: 0x7fffbc0dfcc4
Array[2] = 2 & address: 0x7fffbc0dfcc8
Array[3] = 4 & address: 0x7fffbc0dfccc
Array[4] = 5 & address: 0x7fffbc0dfcd0

Array[0] = 1 & address: 0x7fffbc0dfcc0
Array[1] = 2 & address: 0x7fffbc0dfcc4
Array[2] = 3 & address: 0x7fffbc0dfcc8
Array[3] = 4 & address: 0x7fffbc0dfccc
Array[4] = 5 & address: 0x7fffbc0dfcd0

Iteration :: 4
Array[0] = 1 & address: 0x7fffbc0dfcc0
Array[1] = 2 & address: 0x7fffbc0dfcc4
Array[2] = 3 & address: 0x7fffbc0dfcc8
Array[3] = 4 & address: 0x7fffbc0dfccc
Array[4] = 5 & address: 0x7fffbc0dfcd0

Iteration :: 5 // array was sorted
After bubble sort:
Array[0] = 1 & address: 0x7fffbc0dfcc0
Array[1] = 2 & address: 0x7fffbc0dfcc4
Array[2] = 3 & address: 0x7fffbc0dfcc8
Array[3] = 4 & address: 0x7fffbc0dfccc
Array[4] = 5 & address: 0x7fffbc0dfcd0
*/
