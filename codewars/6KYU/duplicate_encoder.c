/* The goal of this exercise is to convert a string to a new string where each character 
 * in the new string is "(" if that character appears only once in the original string, 
 * or ")" if that character appears more than once in the original string. 
 * Ignore capitalization when determining if a character is a duplicate.

Examples
"din"      =>  "((("
"recede"   =>  "()()()"
"Success"  =>  ")())())"
"(( @"     =>  "))((" 
Notes
Assertion messages may be unclear about what they display in some languages. If you read 
"...It Should encode XXX", the "XXX" is the expected result, not the input! */
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
size_t checkDup(char element, const char *testString) {
  static size_t count = 0;
  count = 0;
  for(size_t i = 0; testString[i] != 0; i++) {
    if(tolower(element) == tolower(testString[i])){count++;}
    if(count > 2){break;}
  }
  return count;
}

char *DuplicateEncoder (const char *string) {
  char *enc = (char *)calloc(strlen(string) + 1, sizeof(char));
  size_t index = 0;
  while(string[index] != 0) {
    enc[index] = checkDup(string[index], string) == 1 ? '(' : ')';
    index++;
  }
  enc[index] = '\0';
  return enc;
}
