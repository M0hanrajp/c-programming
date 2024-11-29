#include <stdlib.h>
#include <string.h>
char *count_sheep(unsigned n) {
  // Heap allocated string
  char *resultStr = calloc(13, n); 
  // sheep string
  char stra[11] = "n sheep...";
  char strb[12] = "nn sheep...";
  char strc[13] = "nnn sheep...";
  if(n != 0) {
    // Based on n generate the string
    for(unsigned index = 1; index <= n; index++) {
      if(index < 10) {
        stra[0] = index + 48;
        strcat(resultStr, stra);
        resultStr[index * 10] = '\0';
      }
      if(index >= 10 && index < 100) {
        strb[0] = (index / 10) + 48;
        strb[1] = (index - ((index / 10) * 10)) + 48;
        strcat(resultStr, strb);
        resultStr[index * 11] = '\0';
        }
      if(index >= 100 && index < 1000) {
        strc[0] = (index / 100) + 48;
        strc[1] = ((index - (index / 100) * 100) / 10) + 48;
        strc[2] = (index - (index / 10) * 10) + 48;
        strcat(resultStr, strc);
        resultStr[index * 12] = '\0';
        }
      }
    }
  return resultStr; 
}
 // do_test(12,
 //    "1 sheep...2 sheep...3 sheep...4 sheep...5 sheep..."
 //    "6 sheep...7 sheep...8 sheep...9 sheep..."
 //    "10 sheep...11 sheep...12 sheep..."
 // );
