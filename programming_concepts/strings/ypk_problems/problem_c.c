// A program to extract a specific word from the mentioned position in a string.
#include <stdio.h>
#define SIZE 15

char *extractFromPosition(int position, const char *string);

int main(void) {
    char userInput[SIZE];
    printf("Enter a string with characters less than 15:: ");
    scanf("%[^\n]s", userInput);
    printf("Resulting string word from entered position: %s\n", extractFromPosition(8, userInput));
    return 0;
}

char *extractFromPosition(int position, const char *string) {
    static char userOutput[SIZE];
    int index = 0;
    for (int i = position - 1; string[i] != '\0'; i++) {
        userOutput[index] = string[i];
        index++;
    }
    return userOutput;
}
