/* Description:
Remove n exclamation marks in the sentence from left to right. n is positive integer.

Examples
remove("Hi!",1) === "Hi"
remove("Hi!",100) === "Hi"
remove("Hi!!!",1) === "Hi!!"
remove("Hi!!!",100) === "Hi"
remove("!Hi",1) === "Hi"
remove("!Hi!",1) === "Hi!"
remove("!Hi!",100) === "Hi"
remove("!!!Hi !!hi!!! !hi",1) === "!!Hi !!hi!!! !hi"
remove("!!!Hi !!hi!!! !hi",3) === "Hi !!hi!!! !hi"
remove("!!!Hi !!hi!!! !hi",5) === "Hi hi!!! !hi"
remove("!!!Hi !!hi!!! !hi",100) === "Hi hi hi" */

#include <stdlib.h>
#include <string.h>
char *remove(const char *str_in, int n) {
  int index = 0;
  char *rep = (char *)calloc(strlen(str_in), sizeof(char));
  while(*str_in != '\0') {
    if(*str_in == '!' && n != 0) {
      n--;
      str_in++;
      continue;
    }
    rep[index++] = *str_in++;
  }
  rep[index] = '\0';
  return rep;
}
