/* Complete the solution so that it reverses the string passed into it.
'world'  =>  'dlrow'
'word'   =>  'drow' */
#include <string.h>
#include <stdlib.h>
char *strrev (char *string) {
  char *copy = (char *)calloc(strlen(string), sizeof(char));
  strcpy(copy, string);
  unsigned long end = strlen(string), start = 0;
  while(end--) {string[start++] = copy[end];}
  string[start] = '\0';
  return string; // reverse the string in place and return it
}
