#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define PRINT_ARR(arr, size) for(int i = 0; i < size; i++) { \
                                 printf("%d ", arr[i]);      \
                             }   printf("\n");

bool linearSearch(int *arr, int s, int i, int key) {
    if(i == s)
        return false;
    if(arr[i] == key)
        return true;
    return linearSearch(arr, s, i + 1, key);
}

// Returns the first occurrance of the element
int linearSearchIndex(int *arr, int s, int i, int key) {
    if(i == s)
        return -1;
    if(arr[i] == key)
        return i;
    return linearSearchIndex(arr, s, i + 1, key);
}

int idx = 0; // to update allIndex array
int *linearSearchAllIndex(int *arr, int s, int i, int key, int *allIndex) {
    if(i == s)
        return allIndex; // return array when index has reached out of bound
    if(i == 0 && arr[i] == key) {
        // keep adding index of the element == key
        allIndex[idx++] = i;
    } 
    if(i > 0 && arr[i] == key) {
        // keep on adding memory to allIndex and increase the size counter
        int *tmp = realloc(allIndex, sizeof(int));
        if(tmp != NULL) {
            allIndex = tmp;
            allIndex[idx++] = i;
        } else {
            printf("Error allocating memory to tmp\n");
            free(tmp);
            free(allIndex);
            exit(1);
        }
    }
    return linearSearchAllIndex(arr, s, i + 1, key, allIndex);
}

/* Updated function where it does not take allocated array as argument
 * it returns an allocated array that was declared globally */
int idx2 = 0; // to update allIndex array
int *allIndex2;
int *linearSearchAllIndex2(int *arr, int s, int i, int key) {
    if(i == 0) {
        int *allIndex2 = calloc(1, sizeof(int));
        if(allIndex2 == NULL) {
            printf("Error allocating memory to allIndex\n");
            exit(1);
        }
    }
    if(i == s)
        return allIndex2; // return array when index has reached out of bound
    if(i == 0 && arr[i] == key) {
        // keep adding index of the element == key
        allIndex2[idx2++] = i;
    }
    if(i > 0 && arr[i] == key) {
        // keep on adding memory to allIndex and increase the size counter
        int *tmp = realloc(allIndex2, sizeof(int));
        if(tmp != NULL) {
            allIndex2 = tmp;
            allIndex2[idx2++] = i;
        } else {
            printf("Error allocating memory to tmp\n");
            free(tmp);
            free(allIndex2);
            exit(1);
        }
    }
    return linearSearchAllIndex2(arr, s, i + 1, key);
}

int main(void) {
    int arr[] = {0, 9, 9, 10, -9};
    int key   =  9;

    linearSearch(arr, sizeof(arr)/sizeof(*arr), 0, key) ?
    printf("Key:%d found at %d\n",
            key, linearSearchIndex(arr, sizeof(arr)/sizeof(*arr), 0, key)) : 
    printf("key:%d not found\n", key);

    // return all index where key is found
    int *findAllIndex = calloc(1, sizeof(int));
    findAllIndex = linearSearchAllIndex(arr, sizeof(arr)/sizeof(*arr), 0, key, findAllIndex);
    printf("All index where the %d occurred: ", key);
    PRINT_ARR(findAllIndex, idx);
    free(findAllIndex);

    // return all index where key is found using method 2
    int *findAllIndex2 = linearSearchAllIndex2(arr, sizeof(arr)/sizeof(*arr), 0, key);
    printf("All index where the %d occurred method 2: ", key);
    PRINT_ARR(findAllIndex2, idx2);
    free(findAllIndex2);
    return 0;
}
