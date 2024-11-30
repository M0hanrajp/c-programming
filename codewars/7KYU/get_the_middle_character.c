/* You are going to be given a non-empty string. 
 * Your job is to return the middle character(s) of the string.

If the string's length is odd, return the middle character.
If the string's length is even, return the middle 2 characters.
Examples:
"test" --> "es"
"testing" --> "t"
"middle" --> "dd"
"A" --> "A" */
#include <string.h>
char *get_middle(char outp[3], const char *inp) {
  if(!(strlen(inp) % 2)) {
    outp[0] = inp[(strlen(inp) / 2) - 1];
    outp[1] = inp[strlen(inp) / 2];
    outp[2] = '\0';
  } else {
    outp[0] = inp[strlen(inp) / 2];
    outp[1] = '\0';
  }
    return outp;
}
