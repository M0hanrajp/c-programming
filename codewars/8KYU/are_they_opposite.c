/* Give you two strings: s1 and s2. If they are opposite, return true; otherwise,
 * return false. Note: The result should be a boolean value, instead of a string.
The opposite means: All letters of the two strings are the same, but the case is 
opposite. you can assume that the string only contains letters or it's a empty string. 
Also take note of the edge case - if both strings are empty then you should return false/False.
Examples (input -> output)
"ab","AB"     -> true
"aB","Ab"     -> true
"aBcd","AbCD" -> true
"AB","Ab"     -> false
"",""         -> false */
#include <stdbool.h>
#include <string.h>
bool is_opposite(const char *s1, const char *s2) {
  if(strlen(s1) != strlen(s2))
    return false;
  if(!(strcmp(s1, "") || strcmp(s2, "")))
    return false;
  bool op = true;
  for(int i = 0; s1[i] != '\0'; i++) {
    if(s1[i] >= 65 && s1[i] <= 90) {
      if(s2[i] != s1[i] + 32) {
        op = false;
        continue;
      }
    }
    if(s1[i] >= 97 && s1[i] <= 122) {
      if(s2[i] != s1[i] - 32) {
        op = false;
        continue;
      }
    }
  }
  return op;
}
