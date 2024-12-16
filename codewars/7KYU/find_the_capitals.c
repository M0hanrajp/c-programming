/* Write a function that takes a single non-empty string of only 
 * lowercase and uppercase ascii letters (word) as its argument, 
 * and returns an ordered list containing the indices of all capital 
 * (uppercase) letters in the string.

Example (Input --> Output)
"CodEWaRs" --> [0,3,4,6] */
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
size_t *find_capitals (const char *word, size_t *uppercase_count) {
  size_t *uppercase_array = (size_t *)calloc(strlen(word), sizeof(size_t));
  size_t len = 0;
  for(size_t i = 0; word[i] != '\0'; i++) {
    if(word[i] >= 65 && word[i] <= 90)
      uppercase_array[len++] = i;
  }
  *uppercase_count = len;
  return uppercase_array;
}
