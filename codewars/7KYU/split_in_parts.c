/* The aim of this kata is to split a given string into different strings 
 * of equal size (note size of strings is passed to the method)

Example:
Split the below string into other strings of size #3
'supercalifragilisticexpialidocious'
Will return a new string
'sup erc ali fra gil ist ice xpi ali doc iou s'
Assumptions:

String length is always greater than 0
String has no spaces
Size is always positive */
#include <stddef.h>
#include <string.h>
char *split(const char *str_in, size_t size, char *str_out) {
/*
    `str_out` has enough room for 2 * strlen(`str_in`) + 1 bytes
    Write to `str_out` and return it:
*/
  size_t index = 0, chars = 0;
  memset(str_out, 0, (2 * strlen(str_in) + 1));  
  for(size_t i = 0; str_in[i] != '\0'; i++) {
    if(chars == size) {
      str_out[index++] = ' ';
      chars = 0;i--;
      continue;
    }
    str_out[index++] = str_in[i]; chars++;
  }
  return str_out;
}
