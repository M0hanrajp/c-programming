// Create a program that removes all the occurrences of the word 'the'
// Note: the below program is able to remove 'the' even if it occurrs between any words.
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
char *removeThe(char *a) {
  unsigned index = 0;
  char temp[3];
  char *string = (char *)calloc(100, sizeof(char));
  for(int i = 0; a[i] != '\0'; i++) {
    if(a[i] == ' ') {
      temp[0] = i + 1 < strlen(a) ? a[i + 1] : 0;
      temp[1] = i + 2 < strlen(a) ? a[i + 2] : 0;
      temp[2] = i + 3 < strlen(a) ? a[i + 3] : 0;
      if(strcmp(temp, "The") == 0 || strcmp(temp, "the") == 0) {
        i += 3;
        continue;
      }
    } else if (a[i] == 't' || a[i] == 'T') {
      temp[0] = i < strlen(a) ? a[i] : 0;
      temp[1] = i + 1 < strlen(a) ? a[i + 1] : 0;
      temp[2] = i + 2 < strlen(a) ? a[i + 2] : 0;
      if(strcmp(temp, "The") == 0 || strcmp(temp, "the") == 0) {
        i += 2;
      } else {
        string[index++] = a[i];
        continue;
      }
    } else {
      string[index++] = a[i];
    }
  }
  return string;
}

int main(void) {
  char str[] = "the the strtheing the The the"; // you will get string as the output
  char *p = removeThe(str);
  printf("%s\n", p);
  return 0;
}
