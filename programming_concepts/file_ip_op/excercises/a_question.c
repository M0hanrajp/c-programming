// A program the read the contents of the file and display at stdout but with line numbers
// the soruce file should not contain any line numbers.
// All files will be written/read at edir/
#include <stdio.h>

void readFileDisplayStdoutWithLineNumbers(const char *file_name) {
    FILE *fp = fopen(file_name, "r");
    char sbuff[50];int Ln = 1;
    /* fgets Parsing stops if a newline character is found 
     * (in which case str will contain that newline character) 
     * or if end-of-file occurs.*/
    while (fgets(sbuff, sizeof(sbuff), fp)) {
        printf("%2d. %s", Ln++, sbuff);
    }
    fclose(fp);
}

int main(void) {
    readFileDisplayStdoutWithLineNumbers("edir/a_problem.txt");
    return 0;
}
