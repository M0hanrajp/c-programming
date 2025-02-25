/* Given two words and a letter, return a single word that's a combination 
 * of both words, merged at the point where the given letter first appears 
 * in each word. The returned word should have the beginning of the first 
 * word and the ending of the second, with the dividing letter in the middle. 
 * You can assume both words will contain the dividing letter.

Examples
("hello", "world", "l")       ==>  "held"
("coding", "anywhere", "n")   ==>  "codinywhere"
("jason", "samson", "s")      ==>  "jasamson"
("wonderful", "people", "e")  ==>  "wondeople" */
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
char *strings_merge (const char *s1, const char *s2, char separator) {
  char *merge = (char *)calloc(strlen(s1) + strlen(s2) + 1, sizeof(char));
  unsigned index = 0; bool copy = false;
  for(unsigned i = 0; s1[i] != '\0'; i++) {
    if(s1[i] == separator){break;}
    merge[index++] = s1[i];
  }
  for(unsigned i = 0; s2[i] != '\0'; i++) {
    if(s2[i] == separator){copy = true;}
    if(copy){merge[index++] = s2[i];}
  }
	return merge;
}
