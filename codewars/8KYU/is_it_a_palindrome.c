/* Write a function that checks if a given string (case insensitive) is a palindrome.
A palindrome is a word, number, phrase, or other sequence of symbols that reads the 
same backwards as forwards, such as madam or racecar. */
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
bool is_palindrome(const char *str_in) {
  bool yes = true;
  unsigned long i = strlen(str_in) - 1;
  for(int x = 0; str_in[x] != '\0' && i >= 0; x++) {
    if(tolower(str_in[x]) !=  tolower(str_in[i])) {
      yes = false;
      break;
    }
    i--;
  }
  return yes;
}
