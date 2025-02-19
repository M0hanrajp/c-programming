/* Having two standards for a keypad layout is inconvenient!
Computer keypad's layout:
7 8 9  \n
4 5 6  \n
1 2 3  \n
  0 \n
Cell phone keypad's layout:
1 2 3\n 
4 5 6\n  
7 8 9\n  

Solve the horror of unstandardized keypads by providing a function 
that converts computer input to a number as if it was typed on a phone.
Example:
"789" -> "123"

Notes:
You get a string with numbers only
 */
#include <string.h>
char *computer_to_phone (const char *computer, char *phone) {
  if(!strcmp(computer,"")){strcpy(phone, ""); return phone;}
  unsigned index = 0;
  for(unsigned i = 0; computer[i] != '\0'; i++) {
    switch(computer[i]) {
        case '9': phone[index++] = '3'; break;
        case '8': phone[index++] = '2'; break;
        case '7': phone[index++] = '1'; break;
        case '3': phone[index++] = '9'; break;
        case '2': phone[index++] = '8'; break;
        case '1': phone[index++] = '7'; break;
        default : phone[index++] = computer[i]; break;
    }
  }
  phone[index] = '\0';
	return phone; // return it
}
