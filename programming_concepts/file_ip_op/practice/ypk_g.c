#include <stdio.h>
int main() {
    FILE * fp;
    char name[20] = "Ajay";
    int i;
    fp = fopen("students.dat", "r"); // good practice to open would be using rb
    for (i = 0; i <= 10; i++)
      fwrite(name, sizeof(name), 1, fp);
    close(fp); //fclose should be used
    return 0;
  }
/* 
$ gcc -g -Wall ypk_g.c
ypk_g.c: In function ‘main’:
ypk_g.c:9:5: warning: implicit declaration of function ‘close’; did you mean ‘pclose’? [-Wimplicit-function-declaration]
    9 |     close(fp);
      |     ^~~~~
      |     pclose
 */
