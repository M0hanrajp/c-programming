/* Write a C program that takes an array of integers and counts the frequency 
 * of each unique element in the array. Print the element and its frequency.
 * Example:
 *  Input: {3, 5, 3, 8, 8, 8, 1}
 *  Output:
    Element 3 occurs 2 times
    Element 5 occurs 1 time
    Element 8 occurs 3 times
    Element 1 occurs 1 time
*/
#include <stdio.h>
#define SIZE 7

// function declaration
void findFrequencyOfUniqueElement(int array[], int size);

int main(void) {
    int arr[SIZE] = {3, 5, 3, 8, 8, 8, 1};
    findFrequencyOfUniqueElement(arr, SIZE);
    return 0;
}

// function definition
void findFrequencyOfUniqueElement(int array[], int size) {
    int uniqueElements[size]; // Auxiliary array to track processed elements
    int uniqueCount = 0;      // Counter for unique elements

    for (int i = 0; i < size; i++) {
        int current = array[i];
        int count = 0;
        int alreadyCounted = 0;

        // Check if the element is already processed
        for (int j = 0; j < uniqueCount; j++) {
            if (uniqueElements[j] == current) {
                alreadyCounted = 1;
                break;
            }
        }

        // Skip counting if the element is already processed
        // All the below code will be skipped and program continues execution from line 28
        if (alreadyCounted)
            continue;

        // Count occurrences of the current element
        for (int k = 0; k < size; k++) {
            if (array[k] == current)
                count++;
        }

        // Print the element and its frequency
        printf("Element %d occurs %d times\n", current, count);

        // Mark the element as processed by adding to uniqueElements
        uniqueElements[uniqueCount] = current;
        uniqueCount++;
    }
}
