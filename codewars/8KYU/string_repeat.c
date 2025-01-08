/* Write a function that accepts an integer n and a string 
 * s as parameters, and returns a string of s repeated exactly n times.

Examples (input -> output)
6, "I"     -> "IIIIII"
5, "Hello" -> "HelloHelloHelloHelloHello */
#include <stdlib.h>
#include <string.h>
char *repeat_str(size_t count, const char *src) {
  size_t len = count;
  char *str = (char *)malloc((len * strlen(src)) + 1);
  if(len > 0) {
    strcpy(str, src);
    len--;
    while(len){
      strcat(str, src);
      len--;
    }
  }
  str[(strlen(src) * count) + 1] = '\0';
  return str;
}
