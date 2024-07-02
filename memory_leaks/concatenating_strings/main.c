#include <complex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concatenate_strings(const char *str1, const char *str2) {
    char *result = (char *)malloc(strlen(str1) + strlen(str2) + 1);
    if (!result) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    strcpy(result, str1);
    strcat(result, str2);
    return result;
}

int main() {
    const char *hello = "Hello";
    const char *world = "World";
    char *concatenated = concatenate_strings(hello, world);
    if (concatenated) {
        printf("%s\n", concatenated);
    }
    free(concatenated);
    return 0;
}

