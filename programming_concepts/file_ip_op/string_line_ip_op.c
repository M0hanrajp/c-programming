// Reading & Writing string to a file
#include <stdio.h>
#include <string.h>

// Writing to a file that exists/not exists on the disk
void writeStringToFile(const char *fileName, const char *mode, const char *string) {
    FILE *fp = fopen(fileName, mode);
    unsigned result = fputs(string, fp);
    /* int fputs( const char* restrict str, FILE* restrict stream ); (since C99)
     * Writes all the characters till it encounters null-terminated string str to the 
     * output stream pointed by stream, as if by repeatedly executing fputc.
     * The terminating null character from str is not written.
     * If successful, fputs() returns the non zero value.
     * If unsuccessful, fputs() returns EOF.
     * if the file stream is operated in read mode then the file will not be updated
     */
    fclose(fp);
    result < 0 ? printf("%u, program failed\n", result) :
                 printf("String has been written to %s\n", fileName);
}

void writeStringFromTerminalToFile(const char *fileName, const char *mode, char *string) {
    FILE *fp = fopen(fileName, mode);
    while (strlen(fgets(string, sizeof(string), stdin)) > 1) {
        /* > fgets -> Reads at most count - 1 characters from the given file stream and stores them 
         * in the character array pointed to by str
         * char* fgets( char* restrict str, int count, FILE* restrict stream ); (since C99)
         * > Parsing stops if a newline character is found (in which case str will contain that 
         * newline character) or if end-of-file occurs.
         * > If bytes are read and no errors occur, writes a null character at the position immediately 
         * after the last character written to str.
         * stream -> might be pointer to FILE or stdin
         * > str on success, null pointer on failure.
         * If the end-of-file condition is encountered, sets the eof indicator on stream (see feof()).
         * There is no runtime check for the 2nd argument string size.
         * Behavior is undefined if input buffer is more than the size of char *string
         * the 2nd argument provides the number of characters to read from the stream
         */
        fputs(string, fp);
    }
    fclose(fp);
}

void readStringFromFileAndPrinttoStdout(const char *sourceFileName, const char *mode) {
    FILE *fp = fopen(sourceFileName, mode);
    char sbuff[10];
    while (fgets(sbuff, 10, fp) != NULL)
        printf("%s", sbuff);
    fclose(fp);
}

int main(void) {
    // case 1 string with new line
    char sbuff[100] = "Just\nTrying\nto\nLearn\nAnd\ndo something great!\n";
    //char sbuff[100] = ""; // test with empty string // Nonthing will be written
    // Get string as a input
    writeStringToFile("fdir/write-str.txt", "w", sbuff);

    // Case 2 string input is given from stdin
    char sterm[10];
    // Get string as a input from terminal
    // press enter to input next string, press enter on newline to terminate the program.
    writeStringFromTerminalToFile("fdir/write-str-term.txt", "w", sterm);

    // Case 3 read string from file and print to stdout
    readStringFromFileAndPrinttoStdout("fdir/write-str.txt", "r");
    return 0;
}

/* If you increase the size of buffer more than sizeof(sbuff) in (fgets(sbuff, 12, fp) != NULL)
 * the following warnings are posted
~/c-programming/programming_concepts/file_ip_op$ gcc -g -Wall string_line_ip_op.c
string_line_ip_op.c: In function ‘readStringFromFileAndPrinttoStdout’:
string_line_ip_op.c:47:12: warning: ‘fgets’ writing 12 bytes into a region of size 10 overflows the destination [-Wstringop-overflow=]
   47 |     while (fgets(sbuff, 12, fp) != NULL)
      |            ^~~~~~~~~~~~~~~~~~~~
string_line_ip_op.c:46:10: note: destination object ‘sbuff’ of size 10
   46 |     char sbuff[10];
      |          ^~~~~
In file included from string_line_ip_op.c:2:
/usr/include/stdio.h:592:14: note: in a call to function ‘fgets’ declared with attribute ‘access (write_only, 1, 2)’
  592 | extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
      |              ^~~~~ */
