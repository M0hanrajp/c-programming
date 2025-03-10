// Understanding basic operations of file IP/OP
// Program -> C library functions -> OS -> DISK
// TODO: update with the function return type and how it works.
#include <stdio.h>

int main(void) {
    FILE *fp = NULL;
    char  fc = 0;

    fp = fopen("fdir/file.txt", "r");
    while (1) {
        fc = fgetc(fp);
        if(fc == EOF)
            break;
        printf("%c", fc);
    }
    fclose(fp);
    return 0;
}
