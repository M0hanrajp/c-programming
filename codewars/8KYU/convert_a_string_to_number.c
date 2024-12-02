/* We need a function that can transform a string into a number. 
 * What ways of achieving this do you know?

Note: Don't worry, all inputs will be strings, and every string 
is a perfectly valid representation of an integral number.

Examples
"1234" --> 1234
"605"  --> 605
"1405" --> 1405
"-7" --> -7 */
#include <stdbool.h>
int string_to_number(const char *src) {
  int result = 0;
  int i = 0;
  bool isNeg = false;
  
  // check for negative symbol
  src[i] == '-' ? isNeg = true : (result = src[i] - 48);
  i++;
  
  while(src[i] != '\0') {
    result = (result * 10) + (src[i] - 48);
    i++;
  }
  if(isNeg)
    return -result;
  else
    return result;
}
