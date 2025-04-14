#include <stdio.h>

void appendContentsOfFile(const char *sourceFile, const char *targetFile) {
    FILE *sf = fopen(sourceFile, "r+"); // read and write mode, can also use a mode
                                        // if a mode is used then no need of fseek
    FILE *tf = fopen(targetFile, "r");
    int fc = 0;
    // Move pointer of target file to 1 byte ahead of EOF
    fseek(sf, -1, SEEK_END);
    fputc(' ', sf);

    // Copy from target file to source file
    while ((fc = fgetc(tf)) != -1) {
        fputc(fc, sf);
    }
    fclose(sf);
    fclose(tf);
}

int main(void) {
    appendContentsOfFile("edir/a_problem.txt", "edir/b_problem.txt");
    return 0;
}
