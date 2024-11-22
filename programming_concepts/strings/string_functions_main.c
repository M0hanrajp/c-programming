// This program uses built in string functions to check their behavior
#include <stdio.h>
#include <string.h>

int main(void) {
    char str[500] = "Happy Coding!", tar[500];

    // How to find length of a string
    printf("Length of a string :: %s is :: %ld\n", str, strlen(str));

    // How to copy a string
    printf("Source string: %s & target string: %s\n", str, strcpy(tar, str));
    /* format of strcpy(char *, const char *)
     * the soruce string is to be treated as constant so that there is no modification when the program is running */

    // Using string concatenation
    printf("After string concatenation: %s\n", strcat(str, "T&T"));
    return 0;
}
