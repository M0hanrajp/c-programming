/* ROT13 is a simple letter substitution cipher that replaces a letter with the letter 
 * 13 letters after it in the alphabet. ROT13 is an example of the Caesar cipher.

Create a function that takes a string and returns the string ciphered with Rot13. 
If there are numbers or special characters included in the string, they should be returned 
as they are. Only letters from the latin/english alphabet should be shifted, like in the original Rot13 "implementation". */
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
char *rot13(const char *src) {
  char *rot = (char *)calloc(strlen(src) + 1, sizeof(char));
  char *start = rot;
  while(*src) {
    *rot = *src;
    if(*src >= 'a' && *src <= 'z') {
      if(*src + 13 > 'z'){*rot = *src + 13 - 26;}
      else if(*src + 13 < 'a'){*rot = *src + 13 + 26;}
      else{*rot = *src + 13;}
    }
    if(*src >= 'A' && *src <= 'Z') {
      if(*src + 13 > 'Z'){*rot = *src + 13 - 26;}
      else if(*src + 13 < 'A'){*rot = *src + 13 + 26;}
      else{*rot = *src + 13;}
    }   
    src++; 
    rot++;
  }
  return start;
}
