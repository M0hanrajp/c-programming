#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_STRINGS 3

char** copy_string_array(const char *source_strings[NUM_STRINGS]) {
    char **dest_strings = (char **)malloc(NUM_STRINGS * sizeof(char *));
    if (!dest_strings) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    for (int i = 0; i < NUM_STRINGS; i++) {
        dest_strings[i] = (char *)malloc(strlen(source_strings[i]) + 1);
        if (!dest_strings[i]) {
            printf("Memory allocation failed for string %d\n", i);
            return NULL;
        }
        strcpy(dest_strings[i], source_strings[i]);
    }
    return dest_strings;
}

int main() {
    const char *source_strings[NUM_STRINGS] = {"Alpha", "Bravo", "Charlie"};
    char **copied_strings = copy_string_array(source_strings);
    if (copied_strings) {
        for (int i = 0; i < NUM_STRINGS; i++) {
            printf("%s\n", copied_strings[i]);
            free(copied_strings[i]);
        }
    }
    free(copied_strings);
    return 0;
}

