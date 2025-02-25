/* Welcome.
In this kata you are required to, given a string, replace every letter with its position in the alphabet.
If anything in the text isn't a letter, ignore it and don't return it.
"a" = 1, "b" = 2, etc.
Example
Input = "The sunset sets at twelve o' clock."
Output = "20 8 5 19 21 14 19 5 20 19 5 20 19 1 20 20 23 5 12 22 5 15 3 12 15 3 11" */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
// returned string has to be dynamically allocated and will be freed by the caller
char *alphabet_position(const char *text) {
  char *str = (char *)calloc(strlen(text) * 2 + 1, sizeof(char));
  int index = 0, buffer = 0;
  for(int i = 0; text[i] != '\0'; i++) {
    if((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122)) {
      sprintf(&str[index], "%d ", buffer = text[i] >= 65 && text[i] <= 90 ? text[i] - 64 : text[i] - 96);
      index += buffer > 9 ? 3 : 2;
    } else {continue;}
  }
  str[strlen(str) - 1] = '\0';
  return str;
}
