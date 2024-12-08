/* Remove all exclamation marks from sentence but ensure a exclamation mark at the end of string. 
 * For a beginner kata, you can assume that the input data is always a non empty string, no need
 * to verify it.

Examples
"Hi!"     ---> "Hi!"
"Hi!!!"   ---> "Hi!"
"!Hi"     ---> "Hi!"
"!Hi!"    ---> "Hi!"
"Hi! Hi!" ---> "Hi Hi!"
"Hi"      ---> "Hi!" */
#include <stdlib.h>
#include <string.h>
char *remove_bang (const char *string) {
// allocate a new string on the heap; memory will be freed
  char *str = (char *)calloc(strlen(string) + 1, sizeof(char));
  int index = 0;
  for(int i = 0; string[i] != '\0'; i++) {
    if(string[i] != '!') {
      str[index] = string[i];
      index++;
    }
  }
  str[index] = '!';
  str[index + 1] = '\0';
  return str;
}
