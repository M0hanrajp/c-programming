/* An isogram is a word that has no repeating letters, consecutive or non-consecutive. 
 * Implement a function that determines whether a string that contains only letters is 
 * an isogram. Assume the empty string is an isogram. Ignore letter case.

Example: (Input --> Output)

"Dermatoglyphics" --> true
"aba" --> false
"moOse" --> false (ignore letter case) */
#include <stdbool.h>
#include <string.h>
bool IsIsogram (const char *string) {
  bool result = true;
  for(int i = 0; string[i] != '\0'; i++) {
    for(unsigned long x = i + 1; x < strlen(string); x++) {
      if(string[i] == string[x] || string[i] == string[x] + 32 || string[i] == string[x] - 32) {
        result = false;
        break;
      } 
    }
  }
  return result;
}
