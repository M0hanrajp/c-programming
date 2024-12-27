/* He needs you to create a method that can determine how many letters 
 * (both uppercase and lowercase ASCII letters) and digits are in a given string.

Example:
"hel2!lo" --> 6
"wicked .. !" --> 6
"!?..A" --> 1 */
#include <stddef.h>
size_t count_letters_and_digits(const char *input) {
  size_t count = 0;
  while(*input != '\0') {
    if((*input >= 65 && *input <= 90) || (*input >= 97 && *input <= 122) || (*input >= 48 && *input <= 57))
      count++;
    input++;
  }
  return count;
}
