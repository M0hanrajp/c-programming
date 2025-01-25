/* This time no story, no theory. The examples below show you how to write function accum:

Examples:
accum("abcd") -> "A-Bb-Ccc-Dddd"
accum("RqaEzty") -> "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy"
accum("cwAt") -> "C-Ww-Aaa-Tttt"
The parameter of accum is a string which includes only letters from a..z and A..Z. */
#include <stdlib.h>
#include <ctype.h>
char *accum(const char *source) {
  char *mumbling = (char *)calloc(200, sizeof(char));
  unsigned index = 0;
  for(unsigned i = 0; source[i] != '\0'; i++) {
    unsigned j = 0;
    while(j < i + 1) {
      if(j == 0) {mumbling[index++] = toupper(source[i]);}
      if(j > 0) { mumbling[index++] = tolower(source[i]);}
      j++;
    }
    mumbling[index++] = '-';
  }
  mumbling[index - 1] = '\0';
  return mumbling;
}
