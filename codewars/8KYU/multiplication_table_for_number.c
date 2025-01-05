/* Your goal is to return multiplication table for number that is always an integer from 1 to 10.

For example, a multiplication table (string) for number == 5 looks like below:

1 * 5 = 5
2 * 5 = 10
3 * 5 = 15
4 * 5 = 20
5 * 5 = 25
6 * 5 = 30
7 * 5 = 35
8 * 5 = 40
9 * 5 = 45
10 * 5 = 50
P. S. You can use \n in string to jump to the next line. */
/* Note: newlines should be added between rows, but there should be no trailing newline at the end. If you're unsure about the format, look at the sample tests. */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
char *multi_table(int num) {
  char multiplication[13];
  char *table = (char *)calloc(140, sizeof(char));
  for(int i = 1; i < 11; i++) {
    if(i == 10)
      sprintf(multiplication, "%d * %d = %d", i, num, i * num);
    else
      sprintf(multiplication, "%d * %d = %d\n", i, num, i * num);
    strcat(table, multiplication);
  }
  return table;
}
