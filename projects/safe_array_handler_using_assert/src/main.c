#include "safe_array.h"
#include <stdbool.h>
#include <stdio.h>

// To demonstrate NDEBUG, you might want to control this via compiler flags
// #define NDEBUG // Uncomment this to disable asserts

#include <assert.h> // Include here as well if main uses assert, or just rely on safe_array.c

int main() {
    printf("--- Safe Array Test Program ---\n");
    printf("Asserts are currently: %s\n",
           #ifdef NDEBUG
           "DISABLED"
           #else
           "ENABLED"
           #endif
    );

    int get_value;

    // Test 1: Initialize and print
    printf("\nTest 1: Initialize and Print\n");
    safe_array_init(0);
    safe_array_print();
    printf("Max array size: %d\n", safe_array_get_max_size());

    // Test 2: Set and Get valid elements
    printf("\nTest 2: Set and Get valid elements\n");
    if (safe_array_set_element(0, 8)) {
        printf("Set element at index 0 to 8\n");
    }
    if (safe_array_set_element(MAX_ARRAY_SIZE - 1, 88)) {
        printf("Set element at index %d to 88\n", MAX_ARRAY_SIZE - 1);
    }

    if (safe_array_get_element(MAX_ARRAY_SIZE - 1, &get_value)) {
        printf("get_value at index (%d): %d\n",MAX_ARRAY_SIZE - 1, get_value);
    }
    // Let's check the retrieved get_value with an assert in main too!
    assert(get_value == 88 && "Value retrieved from index 0 is not what was set!");

    if (safe_array_get_element(MAX_ARRAY_SIZE - 1, &get_value)) {
        printf("get_value at index %d: %d\n", MAX_ARRAY_SIZE - 1, get_value);
    }
    assert(get_value == 88 && "Value retrieved from last index is not what was set!");

    safe_array_print();

    // Test 3: Attempting to trigger assertions (these will halt if asserts are enabled)
    printf("\nTest 3: Potentially Triggering Assertions (if enabled)\n");
    // Uncomment one by one to see assertion failures:

    // Example 1: Accessing uninitialized array (if asserts are stricter in set/get)
    // We added an is_initialized check, let's try to bypass init (by re-declaring or similar,
    // or simply by commenting out the init call for a fresh run and trying to set an element)
    // For this specific setup, the is_initialized flag handles this well.
    // If you were to compile safe_array.c without the init flag check, then call set:
    // printf("Attempting to set element before init (MANUALLY SIMULATED SCENARIO)...\n");
    // This requires modifying safe_array.c temporarily to demo, or more complex main logic.

    // Example 2: Index out of bounds (negative)
    // printf("Attempting to set element at index -1...\n");
    // safe_array_set_element(-1, 100); // This should trigger an assertion

    // Example 3: Index out of bounds (too large)
    // printf("Attempting to get element at index %d...\n", MAX_ARRAY_SIZE);
    // safe_array_get_element(MAX_ARRAY_SIZE, &get_value); // This should trigger an assertion

    // Example 4: NULL pointer for output
    // printf("Attempting to get element with NULL output pointer...\n");
    // safe_array_get_element(0, NULL); // This should trigger an assertion

    // Example 5: Using array before initialization (if safe_array_init was forgotten)
    // To truly test this, you'd need to ensure 'is_initialized' is false.
    // One way is to have a separate function that tries to use the array without calling init.
    // Or, for a simple demo:
    // extern bool is_initialized;
    // is_initialized = false; // MANIPULATING MODULE-INTERNAL STATE FOR DEMO - NOT GOOD PRACTICE in real code
    // printf("Artificially setting is_initialized to false for demo.\n");
    // printf("Attempting to print uninitialized array (after manually resetting flag)...\n");
    // safe_array_print(); // This should trigger the is_initialized assertion in print

    printf("\n--- End of Safe Array Test Program ---\n");
    return 0;
}
  
