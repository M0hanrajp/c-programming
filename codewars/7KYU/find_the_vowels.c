/* We want to know the index of the vowels in a given word, for example, there are 
 * two vowels in the word super (the second and fourth letters).
So given a string "super", we should return a list of [2, 4].
Some examples:
Mmmm  => []
Super => [2,4]
Apple => [1,5]
YoMama -> [1,2,4,6]
NOTES
Vowels in this context refers to: a e i o u y (including upper case)
This is indexed from [1..n] (not zero indexed!) */
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
int *vowel_indices (const char *string, size_t *nb_vowels) {
  int *vi = (int *)calloc(strlen(string) + 1, sizeof(int));
  size_t index = 0;
  for(int i = 0; string[i] != '\0'; i++) {
    switch(string[i]) {
        case 'a' : case 'A' : vi[index++] = i + 1; break;
        case 'e' : case 'E' : vi[index++] = i + 1; break;
        case 'i' : case 'I' : vi[index++] = i + 1; break;
        case 'o' : case 'O' : vi[index++] = i + 1; break;
        case 'u' : case 'U' : vi[index++] = i + 1; break;
        case 'y' : case 'Y' : vi[index++] = i + 1; break;
    }
  }
	*nb_vowels = index;
	return vi;
}
