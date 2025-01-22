/* Write a function that accepts an array of 10 integers (between 0 and 9), 
 * that returns a string of those numbers in the form of a phone number.
Example
create_phone_number(phnum, (const unsigned char[]){1,2,3,4,5,6,7,8,9,0});
     phnum <- "(123) 456-7890" 
The returned format must be correct in order to complete this challenge.
Don't forget the space after the closing parentheses! */
#include <stdint.h>
#include <stdio.h>
char *create_phone_number(char phnum[15], const uint8_t digits[10]) {
  sprintf(phnum, "(%c%c%c) %c%c%c-%c%c%c%c", 
          digits[0] + 48, digits[1] + 48, digits[2] + 48,
          digits[3] + 48, digits[4] + 48, digits[5] + 48,
          digits[6] + 48, digits[7] + 48, digits[8] + 48,
          digits[9] + 48);
  return phnum;
}
