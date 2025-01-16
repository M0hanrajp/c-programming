/* "c" -> False
"C" -> True
"hello I AM DONALD" -> False
"HELLO I AM DONALD" -> True
"ACSKLDFJSgSKLDFJSKLDFJ" -> False
"ACSKLDFJSGSKLDFJSKLDFJ" -> True */
#include <stdbool.h>

bool is_uppercase(const char *source) {
  bool isup = true;
  int i = 0;
  while(source[i] != '\0'){
    if(source[i] >= 97 && source[i] <= 122) {
      isup = false;
      break;
    }
    i++;
  }
  return isup;
}
