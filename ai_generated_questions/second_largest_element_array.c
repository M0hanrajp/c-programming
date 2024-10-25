#include <stdio.h>
#include <limits.h>

// function declaration
int findSecondLargestElementOfArray(int array[], int size);

int main(void) {
    int a[6] = {100, 90, 12, 7, 45, 23};
    int result = findSecondLargestElementOfArray(a, 6);  // Corrected size here
    if(result == -1)
        printf("All elements are the same or only one unique element exists!\n");
    else if(result == -2)
        printf("Please enter two or more elements.\n");
    else
        printf("The second largest element is: %d\n", result);
    return 0;
}

// function definition
int findSecondLargestElementOfArray(int array[], int size) {
    if (size < 2)
        return -2;  // Not enough elements
    int largest = 0, secondLargest = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] > largest) {
            secondLargest = largest;
            largest = array[i];
        } else if (array[i] > secondLargest && array[i] < largest) {
            secondLargest = array[i];
        }
    }

    if (secondLargest == 0)
        return -1;  // All elements are the same or only one unique element

    return secondLargest;
}
