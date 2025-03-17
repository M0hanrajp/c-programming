# include <stdio.h>
int main() {
    unsigned char;
    FILE * fp;
    fp = fopen("trial", ‘r’);
    while ((ch = getc(fp)) != EOF)
      printf("%c", ch);
    fclose( * fp);
    return 0;
}

/* $ gcc -g -Wall ypk_e.c
ypk_e.c: In function ‘main’:
ypk_e.c:3:5: warning: useless type name in empty declaration
    3 |     unsigned char;
      |     ^~~~~~~~
ypk_e.c:5:25: error: stray ‘\342’ in program
    5 |     fp = fopen("trial", ‘r’);
      |                         ^
ypk_e.c:5:27: error: stray ‘\342’ in program
    5 |     fp = fopen("trial", ‘r’);
      |                           ^
ypk_e.c:5:26: error: ‘r’ undeclared (first use in this function)
    5 |     fp = fopen("trial", ‘r’);
      |                          ^
ypk_e.c:5:26: note: each undeclared identifier is reported only once for each function it appears in
ypk_e.c:6:13: error: ‘ch’ undeclared (first use in this function)
    6 |     while ((ch = getc(fp)) != EOF)
      |             ^~
ypk_e.c:8:13: error: incompatible type for argument 1 of ‘fclose’
    8 |     fclose( * fp);
      |             ^~~~
      |             |
      |             FILE
In file included from ypk_e.c:1:
/usr/include/stdio.h:178:26: note: expected ‘FILE *’ but argument is of type ‘FILE’
  178 | extern int fclose (FILE *__stream); */
