/* A program that copies chars from a file to other file.
 * All lowercase chars are converted to upper case chars */

#include <stdio.h>

void UppercaseFileCopy(const char *sourceFile, const char *targetFile) {
    FILE *sf = fopen(sourceFile, "r");
    FILE *tf = fopen(targetFile, "w");
    int sc = 0;
    while ((sc = fgetc(sf)) != EOF) {
        sc > 96 && sc < 123 ? fputc(sc - 32, tf) : fputc(sc, tf);
    }
    fclose(sf);
    fclose(tf);
}


int main(void) {
    UppercaseFileCopy("edir/d_problem_sf.txt", "edir/d_problem_tf.txt");
    return 0;
}
