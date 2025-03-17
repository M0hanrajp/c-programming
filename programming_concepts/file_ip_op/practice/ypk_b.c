#include <stdio.h>
#include <stdlib.h>
  int main() {
    FILE * fp;
    char c;
    fp = fopen("TRY.C", "r");
    if (fp == null) {
      puts("Cannot open file\n");
      exit();
    }
    while ((c = getc(fp)) != EOF)
      putch(c);
    fclose(fp);
    return 0;
  }

/*
 1. null is not defined, NULL should be used at that place.
 2. exit() function should have an int type argument, which is
 not present there.
 3. putch() is defined in conio.h file which is also not present.

$ gcc -g -Wall ypk_b.c
ypk_b.c: In function ‘main’:
ypk_b.c:7:15: error: ‘null’ undeclared (first use in this function)
    7 |     if (fp == null) {
      |               ^~~~
ypk_b.c:7:15: note: each undeclared identifier is reported only once for each function it appears in
ypk_b.c:9:7: error: too few arguments to function ‘exit’
    9 |       exit();
      |       ^~~~
In file included from ypk_b.c:2:
/usr/include/stdlib.h:624:13: note: declared here
  624 | extern void exit (int __status) __THROW __attribute__ ((__noreturn__));
      |             ^~~~
ypk_b.c:12:7: warning: implicit declaration of function ‘putch’; did you mean ‘putc’? [-Wimplicit-function-declaration]
   12 |       putch(c);
      |       ^~~~~
      |       putc

*/
