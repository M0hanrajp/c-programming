#include <stdio.h>

void copyFile(const char *source, const char *target) {
    FILE *fs = NULL, *ft = NULL;
    char  ch = 0;
    fs = fopen(source, "r");
    ft = fopen(target, "w");
    /* fopen in "w" mode
     * Searches file. If the file exists, its contents are overwritten.
     * If the file doesn’t exist, a new file is created. Returns NULL, if unable to open file.
     * Operations possible – writing to the file.
     */
    while((ch = fgetc(fs)) != EOF)
        fputc(ch, ft);
    /* int fputc( int ch, FILE* stream );
     * Writes a character ch to the given output stream stream.
     * Internally, the character is converted to unsigned char just before being written.
     * On success, returns the written character.
     * On failure, returns EOF and sets the error indicator (see ferror()) on stream.
     * It increments pointer to the next character */
    fclose(ft);
    fclose(fs);
}

int main(void) {              /* second argument can have any filename, since fopen can create
                                 file if it does not exist. */
    copyFile("fdir/file-a.c", "fdir/new.txt");
    printf("File copied, please check fdir/empty.txt has been updated or not!\n");
    return 0;
}

/* output --
// the file does not contain anything
mpunix@LIN-5CG3350MRD:~/c-programming/programming_concepts/file_ip_op$ cat fdir/empty.txt
mpunix@LIN-5CG3350MRD:~/c-programming/programming_concepts/file_ip_op$ gcc -g -Wall copy_file_char_to_other_file.c
mpunix@LIN-5CG3350MRD:~/c-programming/programming_concepts/file_ip_op$ ./a.out
// first execution file has copied characters from test-file.txt to empty.txt
mpunix@LIN-5CG3350MRD:~/c-programming/programming_concepts/file_ip_op$ cat fdir/empty.txt
flowchart TD
    A[Call g_bus_own_name()]
    B[Attempt connection to bus (bus_type)]
    C{Is connection successful?}
    D[name_lost_handler (NULL connection)]
    E[bus_acquired_handler invoked]
    F{Is name acquired?}
    G[name_lost_handler (after bus acquired)]
    H[name_acquired_handler invoked]

    A --> B
    B --> C
    C -- "No" --> D
    C -- "Yes" --> E
    E --> F
    F -- "No" --> G
    F -- "Yes" --> H
mpunix@LIN-5CG3350MRD:~/c-programming/programming_concepts/file_ip_op$ gcc -g -Wall copy_file_char_to_other_file.c
mpunix@LIN-5CG3350MRD:~/c-programming/programming_concepts/file_ip_op$ ./a.out
// second execution file has copied characters from file-a.c to empty.txt
// Note that all characters are replaced
mpunix@LIN-5CG3350MRD:~/c-programming/programming_concepts/file_ip_op$ cat fdir/empty.txt
#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;

} */
