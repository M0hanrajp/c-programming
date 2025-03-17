# include <stdio.h>
int main() {
    FILE * fp;
    char str[80];
    fp = fopen("TRY.C", "r");
    while (fgets(str, 80, fp) != EOF) {
      fputs(str);
    }
    fclose(fp);
    return 0;
}
/* 1. fgets() do not return EOF, so while loop statement is
 invalid.
 2. We are storing 81 characters in str variable, 80 characters
 form the file and 1 character is added automatically the NULL
 character that caused overflow of the array.
 3. fputs() accepts three arguments, char* and FILE*, but only
 one argument is passed.
 */
/* $ gcc -g -Wall ypk_d.c
ypk_d.c: In function ‘main’:
ypk_d.c:6:31: warning: comparison between pointer and integer
    6 |     while (fgets(str, 80, fp) != EOF) {
      |                               ^~
ypk_d.c:7:7: error: too few arguments to function ‘fputs’
    7 |       fputs(str);
      |       ^~~~~
In file included from ypk_d.c:1:
/usr/include/stdio.h:655:12: note: declared here
  655 | extern int fputs (const char *__restrict __s, FILE *__restrict __stream);
      |            ^~~~~ */
