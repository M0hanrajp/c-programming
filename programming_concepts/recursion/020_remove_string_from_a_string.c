#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This implementation removes a string from the src
 * string and includes only the characters that do not
 * match with the del string. */
void removeString(char *src, char *dest, char *del) {
    if(*src == '\0')
        return;
    if(*src == *del) {
        int ans = strncmp(src, del, strlen(del));
        if(ans == 0) {
            src += strlen(del);
            removeString(src, dest, del);
        } else {
            *dest = *src;
            src  += 1;
            dest += 1;
            removeString(src, dest, del);
        }
    } else {
        *dest = *src;
        src  += 1;
        dest += 1;
        removeString(src, dest, del);
    }
}

int main(void) {
    char *src = "CiscAppleo";
    char *del = "Apple";
    char *res = calloc(strlen(src) + 1, sizeof(char));
    removeString(src, res, del);
    printf("Result :: %s\n", res);
    return 0;
}
