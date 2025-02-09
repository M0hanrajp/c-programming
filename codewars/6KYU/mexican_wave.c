/* Task
In this simple Kata your task is to create a function that turns a string into a 
Mexican Wave. You will be passed a string and you must return that string in an 
array where an uppercase letter is a person standing up. 
Rules
 1.  The input string will always be lower case but maybe empty.
 2.  If the character in the string is whitespace then pass over it as if it was an empty seat
Example
wave("hello") => {"Hello", "hEllo", "heLlo", "helLo", "hellO"} */

#include <string.h>
#include <stdlib.h>
void wave(const char *y, char **target) {
  unsigned count = 0;
  for (int i = 0; y[i] != '\0'; i++) {
    if(y[i] == ' ')
      continue;
    target[count] = (char *)calloc(strlen(y), sizeof(char));
    strcpy(target[count], y);
    target[count][i] = y[i] - 32;
    count++;
  }
}
