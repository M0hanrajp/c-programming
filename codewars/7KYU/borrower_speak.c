/* The borrowers are tiny tiny fictional people. As tiny tiny people they have 
 * to be sure they aren't spotted, or more importantly, stepped on.

As a result, the borrowers talk very very quietly. They find that capitals and 
punctuation of any sort lead them to raise their voices and put them in danger.

The young borrowers have begged their parents to stop using caps and punctuation.

Change the input text s to new borrower speak. Help save the next generation! */
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
char *borrow(const char *source) {
  char *tiny = (char *)calloc(strlen(source), sizeof(char));
  size_t index = 0; 
  for(size_t i = 0; source[i] != '\0'; i++) {
    if((source[i] >= 'A' && source[i] <= 'Z') || (source[i] >= 'a' && source[i] <= 'z'))
      tiny[index++] = tolower(source[i]);
  }
  tiny[index] = '\0';
  return tiny;
}
