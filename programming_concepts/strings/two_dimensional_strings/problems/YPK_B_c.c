/* Write a program to reverse the strings stored in the following array
of pointers to strings: */

#include <stdio.h>
#include <string.h>
void reverseArrayOfPointers(char **array, unsigned size) {
  char temp[1][50]; memset(temp, 0, sizeof(temp));
  unsigned index = 0;
  for(unsigned i = 0; i < size; i++) {
    strcpy(temp[0], array[i]);
    for(int j = strlen(array[i]) - 1; j > -1; j--) {
      array[i][index++] = temp[0][j];
    }
    index = 0; memset(temp, 0, sizeof(temp));
  }
}

int main(void) {
  // is the given requirement per textbook
  char a[] = "To err is human...";
  char b[] = "But to really mess things up...";
  char c[] = "One needs to know C!!";
  char *s[] = {a, b, c};
  reverseArrayOfPointers(s, sizeof(s)/sizeof(*s));
  printf("::: Modified :::\n%s\n%s\n%s\n", s[0], s[1], s[2]);
  return 0;
}
