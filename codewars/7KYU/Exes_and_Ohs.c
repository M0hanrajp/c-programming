/* Check to see if a string has the same amount of 'x's and 'o's. The method must return a boolean and be case insensitive. The string can contain any char.

Examples input/output:

XO("ooxx") => true
XO("xooxx") => false
XO("ooxXm") => true
XO("zpzpzpp") => true // when no 'x' and 'o' is present should return true
XO("zzoo") => false */
#include <stdbool.h>

bool xo (const char* str) {
  int cx = 0, co = 0;
  bool isEqual = true;
  while(*str != '\0') {
    if(*str == 'x' || *str == 'X')
      cx++;
    if(*str == 'o' || *str == 'O')
      co++;
    str++;
  }
  if(cx != co)
    isEqual = false;
  return isEqual;
}
