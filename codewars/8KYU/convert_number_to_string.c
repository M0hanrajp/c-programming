/* 12345 in int should be "12345" in string
-12345 in int should be "-12345" in string */
#include <stdlib.h>
//  return a dynamically allocated C-string
//  this output will be freed by the tester
char *number_to_string(int number) {
  // for numbers 0 to 9
  if(number >= 0 && number < 10) {
    char *str = (char *)calloc(2, sizeof(char));
    str[0] = 48 + number;
    str[1] = '\0';
    return str;
  }
  // for numbers -1 to -9
  if(number < 0 && number > -10) {
    char *str = (char *)calloc(3, sizeof(char));
    str[0] = '-';
    str[1] = 48 + abs(number);
    str[2] = '\0';
    return str;
  } 
  char *str = (char *)calloc(25, sizeof(char));
  unsigned index = 0, div = 1;
  while(abs(number) / div > 9)
    div *= 10;
  if(number < 0){str[0] = '-';index++;}
  while(div > 0){
    str[index++] = 48 + (abs(number) / div);
    number = abs(number) % div;
    div /= 10;
  }
  str[index] = '\0';
  return str;
}
