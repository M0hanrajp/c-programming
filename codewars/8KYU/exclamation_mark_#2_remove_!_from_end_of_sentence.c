/* Description:
Remove all exclamation marks from the end of sentence.
Examples
"Hi!"     ---> "Hi"
"Hi!!!"   ---> "Hi"
"!Hi"     ---> "!Hi"
"!Hi!"    ---> "!Hi"
"Hi! Hi!" ---> "Hi! Hi"
"Hi"      ---> "Hi" */
#include <string.h>
#include <stddef.h>
char *remove_marks (const char *str_in, char *str_out) {
  unsigned count = 0;
  for(size_t i = strlen(str_in) - 1; i >= 0; i--) {
    if(str_in[i] == '!')
      count++;
    if(str_in[i] != '!')
      break;
  }
  for(unsigned i = 0; i < strlen(str_in) - count; i++) {
    str_out[i] = str_in[i];
  }
  str_out[strlen(str_in) - count] = '\0';
	return str_out; // return it
}
