/* Program to learn basics of strings */
#include <stdint.h>
#include <stdio.h>

void displayString(char *input);

int main(void) {
    char string[] = {'0'};
    char s[2] = {};
    /* This declaratoion intializes elements of s to NULL
     * so when printed they are ignored */
    printf("%s %c at %p\n", string, string[0], (void *)string); // 0 0 is printed, ascii value will be 48
    printf("%s %c at %p\n", s, s[0], (void *)s); // space at address is printed

    // expanded way of declaring strings
/*     char words[] = {'A', 'B', 'C', 'D', 'E'};
    printf("%s\n", words);
    displayString(words); */

    char sentence[] = "I use arch linux BTW";
    printf("Address of sentence in main %p\n", sentence);
    printf("String in main :: %s\n", sentence);
    displayString(sentence);

/*     char userInput[100];
    printf("Enter a string:: ");
    scanf("%s", userInput);
    // will only print the characters till the first space character is encountered.
    displayString(userInput);
    printf("%s\n", userInput);
    char userInputSecond[100];
    printf("Enter a string:: ");
    // NOTE: The behavior of scanf for receving multiline words.
    // here `^\n` indicates scanf will read all characters till it meets a newline character
    // TODO: why does the printf take previous string as it's input ?
    scanf("%[^\n]s", userInputSecond);
    displayString(userInputSecond); // prints the same string
    printf("%s\n", userInputSecond); // does not print anything  */
    //NOTE: read https://github.com/M0hanrajp/c-programming/blob/fcc8480f8824c16f18a21da4ff46b794acdd35e0/misc_notes/behavior.md#scanf-behavior-on-reading-data-from-terminal
    // for using scanf to ingore whitespace characters
    return 0;
}

void displayString(char *input) {
    printf("Address &input %p & value *input %c, value of input (which holds char array's address) %p\n", &input, *input, input);
    for(int i = 0; *input != '\0' ; i++) {
        *input = 'X';
        printf("element :: %c & address of element :: %2d is %p\n", *input, i, input);
        input++;
    }
    printf("\n");
}
