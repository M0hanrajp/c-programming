/* Your boss decided to save money by purchasing some cut-rate optical 
 * character recognition software for scanning in the text of old novels 
 * to your database. At first it seems to capture words okay, but you quickly 
 * notice that it throws in a lot of numbers at random places in the text.

Examples (input -> output)
'! !'                 -> '! !'
'123456789'           -> ''
'This looks5 grea8t!' -> 'This looks great!'
Your harried co-workers are looking to you for a solution to take this garbled 
text and remove all of the numbers. Your program will take in a string and clean 
out all numeric characters, and return a string with spacing and special characters 
~#$%^&!@*():;"'.,? all intact. */
#include <stdlib.h>
#include <string.h>
char *clean_string (char *string) {
  char *cpy = (char *)calloc(strlen(string), sizeof(char));
  size_t index = 0;
  for(size_t i = 0; string[i] != '\0'; i++) {
    if(string[i] >= '0' && string[i] <= '9')
      continue;
    cpy[index++] = string[i];
  }
  strcpy(string, cpy);
  free(cpy);
  return string;
}
