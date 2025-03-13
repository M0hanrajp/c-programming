// count the number of spaces, Tabs, newlines, characters
#include <stdio.h>

int main(void) {
    FILE *fp = NULL;
    char  ch = 0;
    int   c = 0, s = 0, t = 0, n = 0;
    fp = fopen("fdir/file-a.c", "r"); // use any file under fdir directory
    while ((ch = fgetc(fp)) != EOF) {
        switch(ch) {
            case  ' ' : s++; break;
            case '\t' : t++; break; // counts tab
            case '\n' : n++; break;
            default   : c++; break;
        } 
    }
    printf("\nSpaces : %d, Tabs : %d, Newlines : %d, characters : %d\n", s, t, n, c);
    fclose(fp);
    return 0;
}
