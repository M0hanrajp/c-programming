/* Complete the method/function so that it converts dash/underscore delimited 
 * words into camel casing. The first word within the output should be capitalized 
 * only if the original word was capitalized (known as Upper Camel Case, also often 
 * referred to as Pascal case). The next words should be always capitalized.

Examples
"the-stealth-warrior" gets converted to "theStealthWarrior"
"The_Stealth_Warrior" gets converted to "TheStealthWarrior"
"The_Stealth-Warrior" gets converted to "TheStealthWarrior" */
#include <stdbool.h>
#include <ctype.h>
//  do not allocate memory for the result
//  write to pre-allocated pointer *camel
void to_camel_case(const char *text, char *camel) {
  if(*text == 0){*camel = '\0';}
  bool isUH = false;
  for(int i = 0; text[i] != '\0'; i++) {
    if(isUH){ *camel = toupper(text[i]); camel++; isUH = false; continue;}
    if(text[i] == '-' || text[i] == '_'){isUH = true; continue;}
    else{*camel = text[i]; camel++;}
  }
  *camel = '\0';
}
