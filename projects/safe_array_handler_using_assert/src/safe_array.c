#include "safe_array.h"
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>

int safe_array[MAX_ARRAY_SIZE];
bool is_initialized = false;

void safe_array_init(int defaultValue) {
    // Inititalize all the elments with the specified value
    for(int i = 0; i < MAX_ARRAY_SIZE; i++)
        safe_array[i] = defaultValue;
    is_initialized = true;
}

bool safe_array_set_element(int index, int value) {
    bool assert_passed = false;
    /* precondition 
     * a. check if array is initialized in the program
     * b. check if entered index is valid
     */
    assert(is_initialized == true);
    assert(index >= 0 && index < MAX_ARRAY_SIZE);
    if(!assert_passed) {
        safe_array[index] = value;
        return true;
    }
    return false;
}

bool safe_array_get_element(int index, int *outValue) {
    bool assert_passed = false;
    /* precondition 
     * a. check if array is initialized in the program
     * b. check if entered index is valid
     */
    assert(is_initialized == true);
    assert(outValue != NULL && 
           "function parameter cannot be NULL");
    assert(index >= 0 && index < MAX_ARRAY_SIZE);
    if(!assert_passed) {
        *outValue = safe_array[index];
        return true;
    }
    return false;
}

void safe_array_print(void) {
    /* precondition 
     * a. check if array is initialized in the program
     */
    assert(is_initialized == true &&
           "Attempting to print an uninitialzied array");
    for (int i = 0; i < MAX_ARRAY_SIZE; i++) {
        printf("S_ARRAY[%d] = %d stored at %p\n", 
                i, 
                safe_array[i], 
                safe_array + i);
    }
}

int safe_array_get_max_size(void) {
    int size = MAX_ARRAY_SIZE;
    assert(size > 0 &&
           "size of the array should be greater than 0");
    return size;
}
