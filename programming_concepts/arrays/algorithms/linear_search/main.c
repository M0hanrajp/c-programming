/* A C program to learn linear search algorithm 
 * What: Search the element index by iterating the loop and look for the element
 * if the element is found, return the index/value or -1 if failed.
 * Why: to search in increments of 1, linear
 * */

#include <stdio.h>

// Function declaration - Linear search
int linearSearchAlgorithmIntegers(int *array, int array_size, int *search_element);

int linearSearchAlgorithmCharacters(char *array, int *search_element);

int main(void) {

    int array[] = {10, 50, 30, 70, 80, 20, 90, 40}, result = 0;
    char arr[] = {"Carpe Diem\n"};

    int key = 'e'; // enter the integer/char that needs to be found
    int array_size = sizeof(array)/sizeof(*array);

    //result = linearSearchAlgorithm(array, array_size, &key);
    result = linearSearchAlgorithmCharacters(arr, &key);

    if(result != -1) {
        printf("The element was found at %d index in the array\n", result);
    }
    else 
        printf("There was no element found in the array!\n");
    return 0;
}

// Function definition - Linear search
int linearSearchAlgorithm(int *array, int array_size, int *search_element) {
    for(int element_index = 0; element_index < array_size; element_index++) {
        if(*search_element == array[element_index]) {
            return element_index; // you can return value to using arr[element_index]
        }
    }
    return -1;
}

int linearSearchAlgorithmCharacters(char *array, int *search_element) {
    for(int element_index = 0; array[element_index] != '\0'; element_index++) {
        if((char)*search_element == array[element_index]) {
            return element_index; // you can return value to using arr[element_index]
        }
    }
    return -1;
}
