#include <stdio.h>

int binarySearch(int *array, int array_size, int *element_search);

int main(void) {

    int array[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91}, key = 0, element_index = 0;
    int array_size = sizeof(array)/sizeof(*array);
    printf("Enter the key to be searched in the array :: ");
    scanf("%d", &key);
    element_index = binarySearch(array, array_size, &key);
    if(element_index != -1)
        printf("The element was found at index %d\n", element_index);
    else
        printf("No element found!\n");
    return 0;
}

int binarySearch(int *array, int array_size, int *element_search) {
    int low = 0, mid = 0, high = array_size - 1;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if(*element_search == array[mid]) {
            return mid;
            break;
        }
        else if (*element_search < array[mid])
            high = mid - 1;
        else if (*element_search > array[mid])
            low = mid + 1;
    }
    return -1;
}

