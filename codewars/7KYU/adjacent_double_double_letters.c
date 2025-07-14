// https://www.codewars.com/kata/67248b0d2b83c34cf65c625f/c
#include <stdbool.h>
#include <string.h>
bool adjacent_double_double_letters(const char *word) {
  int dw = 0;
  int ln = strlen(word);
  int isAdjacent = 0;
  for(int i = 0; word[i] != '\0'; i++) {
    if(i < ln && (i + 1) < ln) {
      if(word[i] == word[i + 1]) {
        dw++; isAdjacent++;
        if(isAdjacent == 2 && dw == 2)
          return true;
        i += 1;
      } else {
        isAdjacent = 0;
        dw = 0;
      }
    }
  }
  return false;
}
