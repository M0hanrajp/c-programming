/* Given an integer, return a string with dash '-' marks before and after 
 * each odd digit, but do not begin or end the string with a dash mark.
Ex:
274 -> '2-7-4'
6815 -> '68-1-5' */
#include <string.h>
void dashatize(int number, char string[32]) {
  memset(string, 0, 32);
  unsigned index = 0;
  long long int mul = 10, num = number * 1, cp = num * 1, checkOE = 0, dig = 0;
  if(num < 0){num = -1 * num; cp = num * 1;}
  if(num < 10 && num >= 0) {
    string[index++] = '0' + num;
  } else {
    while(num / mul > 9) {
      mul *= 10;
      dig++;
    }
    while (cp > 0) {
      checkOE = cp / mul;
      if(index == 0){
        if(checkOE % 2 != 0) {
          string[index++] = '0' + checkOE;
          string[index++] = '-';
        } else {
          string[index++] = '0' + checkOE;
        }
      } else {
        if(cp > 9) {
          if(checkOE % 2 != 0) {
            if(string[index - 1] != '-'){string[index++] = '-';}
            string[index++] = '0' + checkOE;
            string[index++] = '-';
          } else {
            string[index++] = '0' + checkOE;
          } 
        } else {
          if(checkOE % 2 != 0) {
            if(string[index - 1] != '-'){string[index++] = '-';}
            string[index++] = '0' + checkOE;
          } else {
            string[index++] = '0' + checkOE;
          }
        }
      }
      cp %= mul;
      dig--;
      mul /= 10;
    }
    if(dig == -1){string[index] = '0';}
  }
}
