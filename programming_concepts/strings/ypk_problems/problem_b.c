#include <stdio.h>

int main(void) {
    char str1[10], str2[10], str3[10], str4[10];
    printf("Enter a string: ");scanf("%s %s %s %s", str1, str2, str3, str4);
    printf("%s %s %s %s\n",str1, str2, str3, str4);
    /* From this exercise
     * each of the string entered with space will be stored separately in str1 .. str4
     * If a string is entered with more than 4 differenet words, only the 4 words are stored and rest are discarded
     * if you are entering more than required characters per each array the behavior is undefined meaning, the string
     * might show different characters than expected ones.
     * as strings are stored in contagious memory locations, characters might overalp if each arrays exceeds max char limit.
     */
    return 0;
}
