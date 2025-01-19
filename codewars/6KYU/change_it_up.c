/* Create a function that takes a string as a parameter and does the following, in this order:
Replaces every letter with the letter following it in the alphabet (see note below)
Makes any vowels capital
Makes any consonants lower case
Note:

the alphabet should wrap around, so Z becomes A
in this kata, y isn't considered as a vowel.
So, for example the string "Cat30" would return "dbU30" (Cat30 --> Dbu30 --> dbU30) */
#include <ctype.h>
#include <string.h>
char *change_it_up (char *str_out, const char *str_in) {
  for(int i = 0; str_in[i] != '\0'; i++) {
    if((str_in[i] >= 65 && str_in[i] <= 90) || (str_in[i] >= 97 && str_in[i] <= 122)) {
      if(str_in[i] == 'z' || str_in[i] == 'Z') {
        str_out[i] = 'A';
        continue;
      }
      str_out[i] = tolower(str_in[i] + 1);
      switch(str_out[i]) {
        case 'e':
        case 'i':
        case 'o':
        case 'u':
          str_out[i] -= 32;
        default:
          break;
      }
    } else {
      str_out[i] = str_in[i];
    }
  }
  str_out[strlen(str_in)] = '\0';
  return str_out;
}
