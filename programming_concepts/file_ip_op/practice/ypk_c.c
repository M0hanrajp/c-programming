# include <stdio.h>
int main() {
    char fname[] = "c:\\students.dat";
    FILE *fp;
    fp = fopen(fname, "tr");
    if (fp == NULL)
      printf("Unable to open file...\n");
    return 0;
}

// compiles without errors
/* "tr" is not any valid file opening mode, it should be
 "r", "rt" or "rb". And a .dat should be open in binary mode,
 that is in "rb" mode.
*/
