#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* this implementation removes 'a' or 'A'
 * in the provided string, and then result
 * is updated with new string that does not
 * have any of these characters */
void removeA(char *src, char *dest) {
    if(*src == '\0')
        return;
    if(*src != 'a' || *src != 'A') {
        *dest = *src;
        src  += 1;
        dest += 1;
        removeA(src, dest);
    } else {
        src  += 1;
        removeA(src, dest);
    }
}


int main(void) {
    char *str = "baaccadad";
    char *res = calloc(strlen(str) + 1, sizeof(char));
    removeA(str, res);
    printf("Removed char a string :: %s\n", res);
    return 0;
}
