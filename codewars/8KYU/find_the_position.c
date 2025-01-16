/* When provided with a letter, return its position in the alphabet.

Input :: "a"
Output :: "Position of alphabet: 1"
Note: Only lowercased English letters are tested */
#include <stdlib.h>
#include <stdio.h>
char* position(char alphabet) {
  char* res = (char *)calloc(25, sizeof(char));
  sprintf(res, "Position of alphabet: %d", alphabet - 96);
  return res;
}
