/* Write a function that accepts a string, and returns true if it is in 
 * the form of a phone number.
Assume that any integer from 0-9 in any of the spots will produce a valid 
phone number.

Only worry about the following format:
(123) 456-7890 (don't forget the space after the close parentheses)
Examples:
"(123) 456-7890"  => true
"(1111)555 2345"  => false
"(098) 123 4567"  => false */
#include <string.h>
#include <stdbool.h>
bool valid_phone_number(const char* number) {
  bool valid = true;
  // check for format
  if(strlen(number) > 14){return false;}
  if(strlen(number) < 14){return false;}
  if(number[0] != '('){return false;}
  if(number[4] != ')'){return false;}
  if(number[5] != ' '){return false;}
  if(number[9] != '-'){return false;}
  // check for integers
  if(!(number[ 1] >= '0' && number[ 1] <= '9')){return false;}
  if(!(number[ 2] >= '0' && number[ 2] <= '9')){return false;}
  if(!(number[ 3] >= '0' && number[ 3] <= '9')){return false;}
  if(!(number[ 6] >= '0' && number[ 6] <= '9')){return false;}
  if(!(number[ 7] >= '0' && number[ 7] <= '9')){return false;}
  if(!(number[ 8] >= '0' && number[ 8] <= '9')){return false;}
  if(!(number[10] >= '0' && number[10] <= '9')){return false;}
  if(!(number[11] >= '0' && number[11] <= '9')){return false;}
  if(!(number[12] >= '0' && number[12] <= '9')){return false;}
  if(!(number[13] >= '0' && number[13] <= '9')){return false;}
  return valid;
}
