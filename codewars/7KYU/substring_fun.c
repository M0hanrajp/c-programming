/* Complete the function that takes an array of words.
You must concatenate the nth letter from each word to construct a new word which should be returned as a string, where n is the position of the word in the list.
For example:

["yoda", "best", "has"]  -->  "yes"
  ^        ^        ^
  n=0     n=1     n=2
Note: Test cases contain valid input only - i.e. a string array or an empty array; and each word will have enough letters. */
#include <stddef.h>
#include <stdlib.h>
char *nth_char (size_t length, const char *const strings[length], char *str_out) {
  str_out = (char *)calloc(length + 1, sizeof(char));
  for(size_t i = 0; i < length; i++)
    str_out[i] = strings[i][i];
  str_out[length] = '\0';
  return str_out; // return it
}
