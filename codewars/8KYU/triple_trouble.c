/* Triple Trouble
Create a function that will return a string that combines all of the letters of the three inputed strings in groups. Taking the first letter of all of the inputs and grouping them next to each other. Do this for every letter, see example below!
E.g. Input: "aa", "bb" , "cc" => Output: "abcabc"
Note: You can expect all of the inputs to be the same length. */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
char *triple_trouble(const char *one, const char *two, const char *three) {
  const char *string[] = {one, two, three};
  char *tt = (char *)calloc(3 * strlen(one) + 1, sizeof(char));
  char temp[4];
  for(int i = 0; one[i] != '\0'; i++) {
    memset(temp, 0, 4);
    sprintf(temp, "%c%c%c", string[0][i], string[1][i], string[2][i]);
    strcat(tt, temp);
  }
  return tt;
}
