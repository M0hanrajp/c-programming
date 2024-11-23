// This program uses custom functions to perform the same functionalities as built in string functions
// Note check Behavior.md for the reason why address is being printed
#include <stdio.h>

// function declarations
int customStrlen(char *inputString);
int customStrcmp(const char *sourceString, const char *targetString);
char *customStrcpy(char *sourceString, char *targetString);
char *customStrcat(char *srcString, char *tarString);

int main(void) {
    char str[] = "Happy Coding, something else, playground.", copy[500];
    // finding string length
    printf("Size of string : %d & base address: %p\n", customStrlen(str), str);

    // Copying string
    printf("Input string: %s & copied string: %s\n", str, customStrcpy(str, copy));

    // String concatenation
    char a[20] = "Silicon";
    char b[10] = " chip";
    printf("After string concat: %s\n", customStrcat(a, b));

    // String compare
    printf("Compare strings:: %d\n", customStrcmp("Jerry", "Jerry Boy"));
    return 0;
}

// function definitions
int customStrlen(char *inputString) {
    int count = 0;
    for(int i = 0; inputString[i] != '\0'; i++) {
        count++;
    }
    return count;
}

// Can be written with soruce string made to constant using const keyword
char *customStrcpy(char *sourceString, char *targetString) {
    for (int i = 0; sourceString[i] != '\0'; i++) {
        targetString[i] = sourceString[i];
    }
    return targetString;
}

char *customStrcat(char *srcString, char *tarString) {
    int srcStringEndIndex = customStrlen(srcString);
    printf("Base address of *srcString = %p & base address of tarString = %p\n", srcString, tarString);
    while (*tarString != '\0') {
        *(srcString + srcStringEndIndex) = *tarString;
        printf("[DEBUG]:: %s & %p\n", srcString, &(srcString[srcStringEndIndex]));
        srcStringEndIndex++;
        tarString++;
    }
    srcString[srcStringEndIndex] = '\0';
    return srcString;
}

int customStrcmp(const char *sourceString, const char *targetString) {
    for(int i = 0; targetString[i] != '\0' || sourceString[i] != '\0'; i++) {
        if(sourceString[i] != targetString[i]) {
            return (sourceString[i] - targetString[i]);
        }
    }
    return 0;
}
