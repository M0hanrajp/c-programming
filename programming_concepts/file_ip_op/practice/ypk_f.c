# include <stdio.h>
int main() {
    FILE * fp;
    char names[20];
    int i;
    fp = fopen("students.dat", "wb");
    for (i = 0; i <= 10; i++) {
      puts("\nEnter name: ");
      gets(name);
      fwrite(name, size of (name), 1, fp);
    }
    close(fp);
    return 0;
}
/* 
$ gcc -g -Wall ypk_f.c
ypk_f.c: In function ‘main’:
ypk_f.c:9:7: warning: implicit declaration of function ‘gets’; did you mean ‘fgets’? [-Wimplicit-function-declaration]
    9 |       gets(name);
      |       ^~~~
      |       fgets
ypk_f.c:9:12: error: ‘name’ undeclared (first use in this function); did you mean ‘names’?
    9 |       gets(name);
      |            ^~~~
      |            names
ypk_f.c:9:12: note: each undeclared identifier is reported only once for each function it appears in
ypk_f.c:10:20: error: ‘size’ undeclared (first use in this function); did you mean ‘size_t’?
   10 |       fwrite(name, size of (name), 1, fp);
      |                    ^~~~
      |                    size_t
ypk_f.c:10:24: error: expected ‘)’ before ‘of’
   10 |       fwrite(name, size of (name), 1, fp);
      |             ~          ^~~
      |                        )
ypk_f.c:10:7: error: too few arguments to function ‘fwrite’
   10 |       fwrite(name, size of (name), 1, fp);
      |       ^~~~~~
In file included from ypk_f.c:1:
/usr/include/stdio.h:681:15: note: declared here
  681 | extern size_t fwrite (const void *__restrict __ptr, size_t __size,
      |               ^~~~~~
ypk_f.c:12:5: warning: implicit declaration of function ‘close’; did you mean ‘pclose’? [-Wimplicit-function-declaration]
   12 |     close(fp);
      |     ^~~~~
      |     pclose
ypk_f.c:4:10: warning: unused variable ‘names’ [-Wunused-variable]
    4 |     char names[20];
      |          ^~~~~ 
*/
