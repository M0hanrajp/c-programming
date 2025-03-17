#include <stdio.h>
#include <stdlib.h>
void openfile(char *sf, FILE **f) {
    *f = fopen(sf, "r");
}

int main(void) {
    FILE *fp;
    openfile("example.txt", fp);
    if(fp == NULL){ perror("");}
    return 0;
}

// in this program we cannot pass fp it's of type FILE *
// the function expects FILE **, hence we need to pass &fp

/*
$ gcc -g -Wall ypk_a.c
ypk_a.c: In function ‘main’:
ypk_a.c:9:29: warning: passing argument 2 of ‘openfile’ from incompatible pointer type [-Wincompatible-pointer-types]
    9 |     openfile("example.txt", fp);
      |                             ^~
      |                             |
      |                             FILE *
ypk_a.c:3:32: note: expected ‘FILE **’ but argument is of type ‘FILE *’
    3 | void openfile(char *sf, FILE **f) {
      |                         ~~~~~~~^
*/
