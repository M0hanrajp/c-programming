# include <fcntl.h>
# include <stdio.h>
  int main() {
    int fp;
    fp = open("pr22.c", "r"); //r is not supported in sys calls
    if (fp == -1)
      puts("cannot open file\n");
    else
      close(fp); // not defined in fcntl.h, include unistd.h
    return 0;
  }
/* 
$ gcc -g -Wall ypk_h.c
ypk_h.c: In function ‘main’:
ypk_h.c:5:25: warning: passing argument 2 of ‘open’ makes integer from pointer without a cast [-Wint-conversion]
    5 |     fp = open("pr22.c", "r"); //r is not supported in sys calls
      |                         ^~~
      |                         |
      |                         char *
In file included from ypk_h.c:1:
/usr/include/fcntl.h:181:42: note: expected ‘int’ but argument is of type ‘char *’
  181 | extern int open (const char *__file, int __oflag, ...) __nonnull ((1));
      |                                      ~~~~^~~~~~~
ypk_h.c:9:7: warning: implicit declaration of function ‘close’; did you mean ‘pclose’? [-Wimplicit-function-declaration]
    9 |       close(fp); // not defined in fcntl.h, include unistd.h
      |       ^~~~~
      |       pclose
 */
