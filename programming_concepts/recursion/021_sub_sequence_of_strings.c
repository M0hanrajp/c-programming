/* Subsequence of strings:
 * for a given string "abc", the sub sequences are:
 * [ "a", "b", "c", "ab", "bc", "ac", "abc" ]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printSubSequence(char *str, char *res, int strIdx, int resLength) {
    /* when str NULL is reached it means
     * res str will hold either one char or multiple char
     * when that happens if resLength is greater than 0 we print it
     * this way we avoid printing NULL character */
    if(str[strIdx] == '\0') {
        if(resLength > 0) {
            res[resLength] = '\0';
            printf("%s\n", res);
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
    char *str = "12";
    char *res = calloc(strlen(str) + 1, sizeof(char));
    printSubSequence(str, res, 0, 0);
    return 0;
}
