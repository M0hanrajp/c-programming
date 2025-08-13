#ifndef SAFE_ARRAY_H
#define SAFE_ARRAY_H

#include <stdbool.h>

// --- Configuration ---
#define MAX_ARRAY_SIZE 5

// --- Public Function Declarations ---

/**
 * @brief Initializes the safe array with a specific value.
 * All elements of the array will be set to 'defaultValue'.
 * @param defaultValue The value to initialize each element with.
 */
void safe_array_init(int defaultValue);

/**
 * @brief Sets the value of an element at a specific index.
 * Halts with an assertion failure if the index is out of bounds
 * (in debug mode).
 * @param index The index of the element to set.
 * @param value The value to set the element to.
 * @return true if the operation was successful (in a non-debug build,
 * this might always return true or have more robust error handling).
 * For this example, we'll focus on assert, so return type is less critical.
 */
bool safe_array_set_element(int index, int value);

/**
 * @brief Gets the value of an element at a specific index.
 * Halts with an assertion failure if the index is out of bounds
 * (in debug mode).
 * @param index The index of the element to get.
 * @param outValue Pointer to store the retrieved value.
 * @return true if the operation was successful and value was retrieved,
 * false otherwise (e.g., if outValue is NULL or index is invalid
 * in a non-assert context).
 */
bool safe_array_get_element(int index, int *outValue);

/**
 * @brief Prints all elements of the safe array to the console.
 */
void safe_array_print(void);

/**
 * @brief Gets the maximum configured size of the array.
 * Useful for looping or knowing bounds.
 * @return The maximum size of the array.
 */
int safe_array_get_max_size(void);

#endif // SAFE_ARRAY_H
