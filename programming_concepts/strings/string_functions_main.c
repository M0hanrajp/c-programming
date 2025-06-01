// This program uses built in string functions to check their behavior
#include <stdio.h>
#include <string.h>

int main(void) {
    char str[500] = "Sappy Coding!", tar[500];

    // How to find length of a string
    printf("Length of a string :: %s is :: %ld\n", str, strlen(str));

    char s[] = "string";
    printf("Length of string :: %lu & size of string :: %lu\n", strlen(s), sizeof(s));
    /* strlen : https://cplusplus.com/reference/cstring/strlen/
     * A C string is as long as the number of characters between the beginning of the 
     * string and the terminating null character (without including the terminating null character itself.
     *
     * sizeof gives the total size of the array
     */

    // How to copy a string
    printf("Source string: %s & target string: %s\n", str, strcpy(tar, str));
    /* format of strcpy(char *, const char *)
     * the soruce string is to be treated as constant so that there is no modification when the program is running */

    // Using string concatenation
    printf("After string concatenation: %s\n", strcat(str, "T&T"));

    // String compare
    printf("Comapre strings:: %d\n", strcmp(str, " "));
    return 0;
}
