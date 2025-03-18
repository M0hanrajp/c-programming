// Usage of ferror
#include <stdio.h>

int main(void) {
    FILE *fp = fopen("fdir/test", "w");
    int   ch = 0;
    while(!feof(fp)) {
        /* Checks if the end of the given file stream has been reached.
         * nonzero value if the end of the stream has been reached, otherwise 0
         * It does not advances the fp pointer to the next byte.
         */
        ch = fgetc(fp);
        if(ferror(fp)){ perror("");}
        break; // since file is opened in write mode, reading from it is not allowed
               // fgetc returns EOF, triggering EOF, in turn triggering ferror
               // if break is not used then it will continue to print perror value.
               // as fp will not advance to the next pointer, feof will always return 0
        /* ferror Checks the given stream for errors.
         * Nonzero value if the file stream has errors occurred, 0 otherwise */
    }
    fclose(fp);
}
