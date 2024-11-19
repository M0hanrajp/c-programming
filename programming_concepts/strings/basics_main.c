/* Program to learn basics of strings */
#include <stdio.h>

void displayString(char *input);

int main(void) {
    char string[] = {'0'};
    printf("%s %c\n", string, string[0]); // 0 48 is printed

    // expanded way of declaring strings
    char words[] = {'A', 'B', 'C', 'D', 'E'};
    printf("%s\n", words);
    displayString(words);

    char sentence[] = "I use arch linux BTW";
    displayString(sentence);

    char userInput[100];
    printf("Enter a string:: ");
    scanf("%s", userInput);
    // will only print the characters till the first space character is encountered.
    displayString(userInput);
    printf("%s\n", userInput);
    char userInputSecond[100];
    printf("Enter a string:: ");
    // here `^\n` indicates scanf will read all characters till it meets a newline character
    // TODO: why does the printf take previous string as it's input ?
    scanf("%[^\n]s", userInputSecond);
    displayString(userInputSecond); // prints the same string
    printf("%s\n", userInputSecond); // does not print anything
    return 0;
}

void displayString(char *input) {
    for(int i = 0; input[i] != '\0' ; i++) {
        printf("%c", input[i]);
    }
    printf("\n");
}
