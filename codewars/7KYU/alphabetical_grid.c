/* Task:
You need to write a function grid that returns an alphabetical grid of size NxN, where a = 0, b = 1, c = 2....
Examples:
grid(4)

a b c d
b c d e
c d e f
d e f g
grid(10)
a b c d e f g h i j
b c d e f g h i j k
c d e f g h i j k l
d e f g h i j k l m
e f g h i j k l m n
f g h i j k l m n o
g h i j k l m n o p
h i j k l m n o p q
i j k l m n o p q r
j k l m n o p q r s */
#include <stdlib.h>
#include <stdio.h>
char *grid (int n) {
  int index = 0, limit = 0, alphabet = 97, row = 1;
  limit = (n + n) * n;
  if(n <= 0){limit = 1;}
  char *string = (char *)calloc(limit + 1, sizeof(char));
  while(index < limit) {
    if(alphabet > 122){alphabet -= 26;}
    sprintf(&string[index], "%c ", alphabet);
    alphabet++;
    if(index + 1 == (n * 2 * row) - 1) {
      if(alphabet > 122){alphabet -= 26;}
      alphabet = 'a' + row;
      row++;
      while(alphabet > 122){alphabet -= 26;}
      string[index + 1] = '\n';
    }
    index += 2;
  }
  string[limit - 1] = '\0';
  return string; // memory will be freed
}
