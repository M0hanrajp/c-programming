#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_STRINGS 3

void create_string_array() {
    char **string_array = (char **)malloc(NUM_STRINGS * sizeof(char *));
    if (!string_array) {
        printf("Memory allocation failed\n");
        return;
    }

    const char *sample_strings[NUM_STRINGS] = {"Hello", "World", "!"};

    for (int i = 0; i < NUM_STRINGS; i++) {
        string_array[i] = (char *)malloc(strlen(sample_strings[i]) + 1);
        if (!string_array[i]) {
            printf("Memory allocation failed for string %d\n", i);
            // Memory leak: free previously allocated strings and the array itself before returning
            return;
        }
        strcpy(string_array[i], sample_strings[i]);
    }

    for (int i = 0; i < NUM_STRINGS; i++) {
        printf("%s ", string_array[i]);
        free(string_array[i]);
    }
    printf("\n");
    free(string_array);
}

int main() {
    create_string_array();
    return 0;
}

