/* Complete the solution so that it returns a formatted string. The return value should equal 
 * "Value is VALUE" where value is a 5 digit padded number.
Example:
solution(5); // should return "Value is 00005" */

#include <stdio.h>
#include <stdlib.h>
char* solution(int n) {
  char* res = (char *)calloc(16, sizeof(char));
  if(n <   10){sprintf(res, "Value is 0000%d", n);}
  if(n >    9 && n <    100){sprintf(res, "Value is 000%d", n);}
  if(n >   99 && n <   1000){sprintf(res, "Value is 00%d", n);}
  if(n >  999 && n <  10000){sprintf(res, "Value is 0%d", n);}
  if(n > 9999 && n < 100000){sprintf(res, "Value is %d", n);}
  return res;
}

/* 
 * simple usage of sprintf with padding
sprintf(str, "Value is %05d", n);

"Value is %05d" is the format string.
- %05d formats the integer n:
- %d → Prints n as a decimal integer.
- 0 (zero) → Pads the number with leading zeros if needed.
- 5 → Specifies a minimum width of 5 characters.

Example Outputs:
If n = 42, then str will contain: "Value is 00042" */
