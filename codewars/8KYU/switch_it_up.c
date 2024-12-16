/* When provided with a number between 0-9, return it in words. 
 * Note that the input is guaranteed to be within the range of 0-9.
Input: 1
Output: "One".
If your language supports it, try using a switch statement. */
#include <string.h>
char* switchItUp(int number) {
  static char words[6];
  switch(number) {
      case 0:
        strcpy(words, "Zero");
        break;
      case 1:
        strcpy(words, "One");
        break;     
      case 2:
        strcpy(words, "Two");
        break;
      case 3:
        strcpy(words, "Three");
        break;
      case 4:
        strcpy(words, "Four");
        break;
      case 5:
        strcpy(words, "Five");
        break;
      case 6:
        strcpy(words, "Six");
        break;     
      case 7:
        strcpy(words, "Seven");
        break;     
      case 8:
        strcpy(words, "Eight");
        break;     
      case 9:
        strcpy(words, "Nine");
        break;     
      case 10:
        strcpy(words, "Ten");
        break;     
      default:
        break;
  }
  return words;
}
