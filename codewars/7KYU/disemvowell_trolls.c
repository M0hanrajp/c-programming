/* Trolls are attacking your comment section!
A common way to deal with this situation is to remove all of the vowels from the trolls' comments, neutralizing the threat.
Your task is to write a function that takes a string and return a new string with all vowels removed.
For example, the string "This website is for losers LOL!" would become "Ths wbst s fr lsrs LL!".
Note: for this kata y isn't considered a vowel.
 */
#include <stdlib.h>
#include <string.h>
//solution must allocate all required memory
//and return a free-able buffer to the caller.

char *disemvowel(const char *str) {
	char *res = (char *)calloc(strlen(str) + 1, sizeof(char));
  unsigned long index = 0;
  for(int i = 0; str[i] != '\0'; i++) {
    if((str[i] == 'a' || str[i] == 'A') || (str[i] == 'e' || str[i] == 'E') || (str[i] == 'i' || str[i] == 'I') || (str[i] == 'o' || str[i] == 'O') || (str[i] == 'u' || str[i] == 'U')) 
      continue;
    res[index++] = str[i];
  }
  res[index] = '\0';
  return res;
}

