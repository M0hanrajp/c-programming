/* Sometimes there are problems: lack of colors, technical malfunction and a "bad" 
 * control string is produced e.g. aaaxbbbbyyhwawiwjjjwwm with letters not from a to m.
You have to write a function printer_error which given a string will return the error 
rate of the printer as a string representing a rational whose numerator is the number 
of errors and the denominator the length of the control string. Don't reduce this fraction 
to a simpler expression.
The string has a length greater or equal to one and contains only letters from ato z.

Examples:
s="aaabbbbhaijjjm"
printer_error(s) => "0/14"

s="aaaxbbbbyyhwawiwjjjwwm"
printer_error(s) => "8/22" */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
char *printerError(const char *s) {
  char *rate = (char *)calloc(6, sizeof(char));
  size_t len = strlen(s);
  unsigned errors = 0;
  for(int i = 0; s[i] != '\0'; i++){
    if(s[i] >= 'n' && s[i] <= 'z')
      errors++;
  }
  snprintf(rate, sizeof(rate), "%u/%lu", errors, len);
  return rate;
}
