/* Step 1: Create a function called encode() to replace all the lowercase vowels in a given string with numbers according to the following pattern:
a -> 1
e -> 2
i -> 3
o -> 4
u -> 5
For example, encode("hello") would return "h2ll4". There is no need to worry about uppercase vowels in this kata.

Step 2: Now create a function called decode() to turn the numbers back into vowels according to the same pattern shown above.

For example, decode("h3 th2r2") would return "hi there".

For the sake of simplicity, you can assume that any numbers passed into the function will correspond to vowels. */
#include <stdlib.h>
#include <string.h>
char *encode(const char *string) {
  char *enc = (char *)calloc(strlen(string) + 1, sizeof(char));
  strcpy(enc, string);
  for(int i = 0; string[i] != '\0'; i++) {
    switch(string[i]) {
        case 'a': enc[i] = '1'; break;
        case 'e': enc[i] = '2'; break;       
        case 'i': enc[i] = '3'; break;       
        case 'o': enc[i] = '4'; break;       
        case 'u': enc[i] = '5'; break;       
    }
  }
  return enc;
}

char *decode(const char *string) {
  char *dec = (char *)calloc(strlen(string) + 1, sizeof(char));
  strcpy(dec, string);
  for(int i = 0; string[i] != '\0'; i++) {
    switch(string[i]) {
        case '1': dec[i] = 'a'; break;
        case '2': dec[i] = 'e'; break;       
        case '3': dec[i] = 'i'; break;       
        case '4': dec[i] = 'o'; break;       
        case '5': dec[i] = 'u'; break;       
    }
  }
  return dec;
}
