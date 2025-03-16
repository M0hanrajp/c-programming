// A program that copies a binary to another binary
#include <stdio.h>

void copyBinaryFile(const char *sFile, const char *tFile, const char *sMode, const char *tMode) {
    FILE *sf = fopen(sFile, sMode);
    FILE *tf = fopen(tFile, tMode);
    int  fc; // declare this as an integer because, if declared as char, 0xFF can be considered EOF
    while((fc = fgetc(sf)) != EOF)
        fputc(fc, tf);
    fclose(sf);
    fclose(tf);
}

int main(void) {
    copyBinaryFile("fdir/a.out", "fdir/c.exe", "rb", "wb");
    return 0;
}
