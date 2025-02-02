/* Write a program that uses an array of pointers to strings str[ ].
Receive two strings str1 and str2 and check if str1 is embedded in
any of the strings in str[ ]. If str1 is found, then replace it with str2.

For example if str1 contains "mountain" and str2 contains "car",
then the second string in str should get changed to "Move a car". */

#include <stdio.h>
#include <string.h>

void checkAndReplace(char **string, unsigned size, char *check, char *replace) {
  char temp[100]; memset(temp, 0, sizeof(temp));
  char cpy[1][100]; memset(temp, 0, sizeof(cpy));
  unsigned index = 0, length = 0, k = 0, x = 0, p = 0;
  for(unsigned i = 0; i < size; i++) {
    length = strlen(string[i]);
    memset(cpy, 0, sizeof(cpy));
    strcpy(cpy[0], string[i]);
    for(unsigned j = 0; j < length; j++) {
      if(string[i][j] == '.' || string[i][j] == '!') { continue;}
      temp[index++] = string[i][j];
      if(string[i][j] == ' ' || j == length - 1) {
        if(temp[index - 1] == ' '){temp[index - 1] = '\0';}
        // if the strings are same then replace the word with str2
        if(!strcmp(temp, check)) {
          for(k = j - index + 1; replace[x] != '\0'; k++)
            string[i][k] = replace[x++];
          if(j == length - 1)
            string[i][k] = '\0';
          else {
            p = strlen(replace);
            if(strlen(temp) == p) {
              string[i][k] = string[i][j];
            } else if(p < strlen(temp)) {
              while(p <= length) {
                string[i][k++] = string[i][j++];
                p++;
              }
              string[i][k] = '\0'; k = 0; p = 0;
              break;
            } else {
              while(j <= length) {
                string[i][k++] = cpy[0][j++];
              }
              string[i][k] = '\0'; k = 0; p = 0;
              break;
            }
          }
        }
        memset(temp, 0, sizeof(temp)); index = 0;
        continue;
      }
    }
    memset(temp, 0, sizeof(temp)); index = 0;
  }
}

int main(void) {

  // Get user input and store in str1 and str2
  char str1[100]; memset(str1, 0, sizeof(str1));
  char str2[100]; memset(str2, 0, sizeof(str2));

  printf("Enter string that needs to be checked  :: ");
  scanf("%s", str1);
  printf("Enter string that needs to be replaced :: ");
  scanf("%s", str2);

  // str is an array of pointers that holds the strings database
  char arr[] = "Move a mountain Kite";
  char brr[] = "We will teach you how to...";
  char crr[] = "Level a building";
  char drr[] = "Erase the past";
  char err[] = "Make a million";
  char *str[ ] = {arr, brr, crr, drr, err};

  // call the function.
  checkAndReplace(str, sizeof(str)/sizeof(*str), str1, str2);
  printf("\n::::: modified strings :::::\n");
  printf("%s\n%s\n%s\n%s\n%s\n", arr, brr, crr, drr, err);
  return 0;
}
