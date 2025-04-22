/* A C program to implement selection sort in ascending order
 * What: Find the minimum/maximum element's index and put it at it's right position.
 * Why: you will have largest/smallest element at their respective index after first iteration.
 * Use < while comparing elements to get ascending order
 * Use > while comparing elements to get descending order.
 * https://www.geeksforgeeks.org/selection-sort-algorithm-2/
 */
#include <stdio.h>
#include <stdbool.h>

// Function declaration - Sort array using selection sort
void selectionSort(int *arr, int array_size);

// Function declaration - to display
void displayArray(int *arr, int array_size);

// Function declaration - swap two elements
void swap(int *element_a, int *element_b);

int main(void) {
    int array[] = {4, 5, 2, 3, 1};
    int array_size = sizeof(array)/sizeof(*array);
    printf("Default array input:\n");displayArray(array, array_size);
    selectionSort(array, array_size);
    printf("Sorted array output:\n");displayArray(array, array_size);
    return 0;
}

// Function definition - Sort array using selection sort
void selectionSort(int *arr, int array_size) {
    /* This will hold the index of the array elements from
     * the start and will be assigned new values if element
     * was found smaller than current element 
     */
    int minIndex = 0;
    for(int i = 0; i < array_size; i++) {
        printf("Iteration :: %d\n", i);
        minIndex = i;
        bool swapFlag = false;
        for(int j = i + 1; j < array_size; j++) {
            // compare rest of the elements with selected element
            if(arr[j] < arr[minIndex]) {
                /* After the whole loop is traversed minIndex will
                 * have the shortest element index value */
                minIndex = j;
                // if condition is true then swap occurrs
                // if condition is false then elements are larger than selected element hence don't swap
                swapFlag = true;
            }
        }
        /* swap with the chosen index so smallest element will be
         * sorted from the start of the array.
         */
        if(swapFlag) {
            swap(&arr[i], &arr[minIndex]);
            displayArray(arr, array_size); // debugging purpose
        }
    }
}

// Function definiton - to display
void displayArray(int *arr, int array_size) {
    for(int index = 0; index < array_size; index++)
        printf("A[%d] = %d & addr: %p\n", index, arr[index], &arr[index]);
    printf("\n");
}

// Function definition - swap elements
void swap(int *element_a, int *element_b) {
    int temp = *element_a;
    *element_a = *element_b;
    *element_b = temp;
}

// output:
/*
 * int array[] = {4, 5, 2, 3, 1};

Default array input:
A[0] = 4 & addr: 0x7ffc37ee1d10
A[1] = 5 & addr: 0x7ffc37ee1d14
A[2] = 2 & addr: 0x7ffc37ee1d18
A[3] = 3 & addr: 0x7ffc37ee1d1c
A[4] = 1 & addr: 0x7ffc37ee1d20

Iteration :: 0
A[0] = 1 & addr: 0x7ffc37ee1d10
A[1] = 5 & addr: 0x7ffc37ee1d14
A[2] = 2 & addr: 0x7ffc37ee1d18
A[3] = 3 & addr: 0x7ffc37ee1d1c
A[4] = 4 & addr: 0x7ffc37ee1d20

Iteration :: 1
A[0] = 1 & addr: 0x7ffc37ee1d10
A[1] = 2 & addr: 0x7ffc37ee1d14
A[2] = 5 & addr: 0x7ffc37ee1d18
A[3] = 3 & addr: 0x7ffc37ee1d1c
A[4] = 4 & addr: 0x7ffc37ee1d20

Iteration :: 2
A[0] = 1 & addr: 0x7ffc37ee1d10
A[1] = 2 & addr: 0x7ffc37ee1d14
A[2] = 3 & addr: 0x7ffc37ee1d18
A[3] = 5 & addr: 0x7ffc37ee1d1c
A[4] = 4 & addr: 0x7ffc37ee1d20

Iteration :: 3
A[0] = 1 & addr: 0x7ffc37ee1d10
A[1] = 2 & addr: 0x7ffc37ee1d14
A[2] = 3 & addr: 0x7ffc37ee1d18
A[3] = 4 & addr: 0x7ffc37ee1d1c
A[4] = 5 & addr: 0x7ffc37ee1d20

Iteration :: 4 // no elements are displayed because 4 & 5 is in it's right position

Sorted array output:
A[0] = 1 & addr: 0x7ffc37ee1d10
A[1] = 2 & addr: 0x7ffc37ee1d14
A[2] = 3 & addr: 0x7ffc37ee1d18
A[3] = 4 & addr: 0x7ffc37ee1d1c
A[4] = 5 & addr: 0x7ffc37ee1d20
*/
