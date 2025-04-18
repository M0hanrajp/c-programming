/* Write a function that takes in a string of one or more words, and returns
 * the same string, but with all words that have five or more letters reversed 
 * (Just like the name of this Kata). Strings passed in will consist of only 
 * letters and spaces. Spaces will be included only when more than one word is present.
Examples:

"Hey fellow warriors"  --> "Hey wollef sroirraw" 
"This is a test        --> "This is a test" 
"This is another test" --> "This is rehtona test" */
#include <string.h>
#include <stdlib.h>
//  do not allocate memory for return string
//  assign the value to the pointer "result"
void spin_words(const char *sentence, char *result) {
  memset(result, 0, strlen(sentence) + 1);
  char *temp = (char *)calloc(50, sizeof(char));
  char *spin = (char *)calloc(50, sizeof(char));
  unsigned count = 0;
  for(int i = 0; sentence[i] != '\0'; i++) {
    if(sentence[i] != ' ') {
    temp[count++] = sentence[i];
    } else {
      if(strlen(temp) > 4) {
        for(size_t i = 0; i < count; i++) {
          spin[i] = temp[count - 1 - i];
        }
        strcat(result, spin);
        strcat(result, " ");
      } else {
        strcat(result, temp);
        strcat(result, " ");
      }
      memset(temp, 0, strlen(temp));
      memset(spin, 0, strlen(spin));
      count = 0;
    }
  }
  if(temp != NULL){
    if(strlen(temp) > 4) {
      for(size_t i = 0; i < count; i++) {
        spin[i] = temp[count - 1 - i];
      }
      strcat(result, spin);
    } else {
      strcat(result, temp);
    }
  }
  free(temp);
  free(spin);
}
