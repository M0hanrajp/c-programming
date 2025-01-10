/* Remove an exclamation mark from the end of a string. For a beginner kata, 
 * you can assume that the input data is always a string, no need to verify it.
Examples
"Hi!"     ---> "Hi"
"Hi!!!"   ---> "Hi!!"
"!Hi"     ---> "!Hi"
"!Hi!"    ---> "!Hi"
"Hi! Hi!" ---> "Hi! Hi"
"Hi"      ---> "Hi" */
#include <string.h>
char *remove_mark (char *string) {
	unsigned len = strlen(string);
  if(len > 0)
    string[len - 1] = (string[len - 1] == '!' ? '\0' : string[len - 1]);
  return string;
}
