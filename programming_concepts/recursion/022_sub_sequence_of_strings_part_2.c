/* Subsequence of strings:
 * for a given string "abc", the sub sequences are:
 * [ "a", "b", "c", "ab", "bc", "ac", "abc" ]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRINT_SEQUENCE(arr, size) for(int i = 0; i < size; i++) { \
                                      printf("[%s], ", arr[i]);    \
                                  }   printf("\n");

// this function collects all the subsequences inside a array pointers 
// all subsequences will be part of a array
char **list = NULL;
int listIdx = 0;
void printSubSequence(char *str, char *res, int strIdx, int resLength) {
    /* when str NULL is reached it means
     * res str will hold either one char or multiple char
     * when that happens if resLength is greater than 0 we print it
     * this way we avoid printing NULL character */
    if(str[strIdx] == '\0') {
        if(resLength > 0) {
            res[resLength] = '\0';
            if(listIdx == 0) {
                list = calloc(1, sizeof(char *));
                if(list == NULL) {
                    printf("Memory allocaton failed\n");
                    exit(1);
                } else {
                    list[listIdx] = calloc(resLength + 1, sizeof(char));
                    strcpy(list[listIdx], res);
                    listIdx++;
                }
            } else {
                // dynamically allocate each char *, based on total subsequences
                char **temp = realloc(list, (listIdx + 1) * sizeof(char *));
                if(temp == NULL) {
                    printf("Memory allocation failed\n");
                    free(list);
                    exit(1);
                } else {
                    list = temp;
                    list[listIdx] = calloc(resLength + 1, sizeof(char));
                    strcpy(list[listIdx], res);
                    listIdx++;
                }
            }
        }
        return;
    }
    // start dividing the string by index
    printSubSequence(str, res, strIdx + 1, resLength);

    // below code is invoked once strIdx is out of bound
    // then current character that is mapped is assigned
    // to res and then new function call is made with res
    res[resLength] = str[strIdx];
    printSubSequence(str, res, strIdx + 1, resLength + 1);
}

int main(void) {
    char *str = "ab";
    char *res = calloc(strlen(str) + 1, sizeof(char));
    printSubSequence(str, res, 0, 0);
    PRINT_SEQUENCE(list, listIdx);
    return 0;
}
