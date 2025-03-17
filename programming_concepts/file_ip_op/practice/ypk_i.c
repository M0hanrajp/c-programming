#include <stdio.h>
main() {
     int fp;
     fp = fopen("students.dat", READ | BINARY);
     if (fp == -1)
       puts("cannot open file\n");
     else
       close(fp);
     return 0;
}
/* 
$ gcc -g -Wall ypk_i.c
ypk_i.c:2:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
    2 | main() {
      | ^~~~
ypk_i.c: In function ‘main’:
ypk_i.c:4:33: error: ‘READ’ undeclared (first use in this function)
    4 |      fp = fopen("students.dat", READ | BINARY);
      |                                 ^~~~
ypk_i.c:4:33: note: each undeclared identifier is reported only once for each function it appears in
ypk_i.c:4:40: error: ‘BINARY’ undeclared (first use in this function)
    4 |      fp = fopen("students.dat", READ | BINARY);
      |                                        ^~~~~~
ypk_i.c:8:8: warning: implicit declaration of function ‘close’; did you mean ‘pclose’? [-Wimplicit-function-declaration]
    8 |        close(fp);
      |        ^~~~~
      |        pclose
 */
