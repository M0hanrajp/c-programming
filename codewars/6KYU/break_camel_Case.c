/* Complete the solution so that the function will break up camel casing, using a space between words.

Example
"camelCasing"  =>  "camel Casing"
"identifier"   =>  "identifier"
""             =>  "" */
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
char* solution(const char *camelCase) {
  // allocate memory dynamically
  int length = strlen(camelCase), index = 0;
  char* res = (char *)malloc(length + 20);
  
  if(camelCase[0] != '\0') {
    res[index++] = camelCase[0];
    for(int i = 1; camelCase[i] != '\0'; i++) {
      if(camelCase[i] >= 'A' && camelCase[i] <= 'Z') {
        res[index++] = ' ';
      }
      res[index++] = camelCase[i];
    }
    res[index++] = '\0';
    return res;
  }
  return res;
}
