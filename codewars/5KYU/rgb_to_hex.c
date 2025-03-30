/* The rgb function is incomplete. Complete it so that passing in RGB decimal 
 * values will result in a hexadecimal representation being returned. Valid 
 * decimal values for RGB are 0 - 255. Any values that fall out of that range 
 * must be rounded to the closest valid value.
Note: Your answer should always be 6 characters long, the shorthand with 3 will 
not work here.

Examples (input --> output):
255, 255, 255 --> "FFFFFF"
255, 255, 300 --> "FFFFFF"
0, 0, 0       --> "000000"
148, 0, 211   --> "9400D3" */
#include <stdlib.h>
#include <string.h>
char *convHex(int dec) {
  char *convHex = (char *)calloc(3, sizeof(char));
  unsigned index = 1;
  if(dec < 0) {
    convHex[1] = '0'; convHex[0] = 48;
  } else if(dec < 16) {
    if(dec > 9) {
      switch (dec) {
        case 10: convHex[index--] = 'A'; break;
        case 11: convHex[index--] = 'B'; break;
        case 12: convHex[index--] = 'C'; break;
        case 13: convHex[index--] = 'D'; break;
        case 14: convHex[index--] = 'E'; break;
        case 15: convHex[index--] = 'F'; break;
      }
    }
    if(dec < 10){convHex[index--] = 48 + dec;}
    convHex[index] = '0';
  } else if(dec > 255) {
    convHex[index--] = 'F'; convHex[index] = 'F';
  } else {
    while(dec > 0) {
      convHex[index--] = dec % 16 == 15 ? 'F' : 
                         dec % 16 == 14 ? 'E' :
                         dec % 16 == 13 ? 'D' :
                         dec % 16 == 12 ? 'C' :
                         dec % 16 == 11 ? 'B' :
                         dec % 16 == 10 ? 'A' : 48 + (dec % 16);
      dec /= 16;
    }
  }
  convHex[2] = '\0';
  return convHex;
}

void rgb (int r, int g, int b, char hex[6 + 1]) {
  memset(hex, 0, 7); // without this the test case in codewars would crash
  strcat(hex, convHex(r)); free(convHex(r));
  strcat(hex, convHex(g)); free(convHex(g));
  strcat(hex, convHex(b)); free(convHex(b));
  hex[6] = '\0';
}
