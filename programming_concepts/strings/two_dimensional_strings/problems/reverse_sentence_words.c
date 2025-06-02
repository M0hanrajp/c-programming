/* A program that reverses a sentence or two tempWords
 * example: "Summmer time" -> "time Summmer"
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORDS 10

void reversetempWords(char *str) {
    // array of pointers of size MAX_WORDS
    char *words[MAX_WORDS];
    int cptr = 0;

    // final resulting string
    char *buildString = (char *)calloc(strlen(str) + 1, sizeof(str));

    // Assume that each word is maximum 20 bytes in the source string
    char *tempWord = calloc(20, sizeof(char));

    /* @breif, start copying words from the source string.
     * assign each word to an element of *words[i]
     */
    for(int i = 0; i < MAX_WORDS; i++) {
        int idx = 0;
        memset(tempWord, 0, 20 * sizeof(char));
        if(*str == ' ')
            str++;
        if(*str == '\0')
            break;
        while (*str != ' ' && *str != '\0') {
            tempWord[idx++] = *str;
            str++;
        }
        tempWord[idx] = '\0';
        words[cptr] = (char *)calloc(strlen(tempWord) + 1, sizeof(char));
        strcpy(words[cptr], tempWord);
        // DEBUG printf("words[%d]:: %s & str:: %s\n", cptr, storeWords[cptr], str);
        cptr++;
    }

    // copy the last tempWord to empty string
    strcpy(buildString, words[cptr - 1]);
    strcat(buildString, " ");

    // from 2nd last tempWord concatenate the final string till first word
    for(int i = cptr - 2; i >= 0; i--) {
        strcat(buildString, words[i]);
        strcat(buildString, " ");
    }
    buildString[strlen(buildString) - 1] = '\0';

    printf("Reversed  :: %s\n", buildString);

    // deallocate used memory
    free(buildString); buildString = NULL;
    free(tempWord); tempWord = NULL;
    for (int i = 0; i < cptr; i++)
        free(words[i]);
    *words = NULL;
}


int main(void) {
    char *s = "It's Summer Time Magic!!!";
    printf("!Reversed :: %s\n", s);
    reversetempWords(s);
    return 0;
}
