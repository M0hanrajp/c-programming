/* to_alternating_case("hello world"); // => "HELLO WORLD"
to_alternating_case("HELLO WORLD"); // => "hello world"
to_alternating_case("hello WORLD"); // => "HELLO world"
to_alternating_case("HeLLo WoRLD"); // => "hEllO wOrld"
to_alternating_case("12345"); // => "12345" (Non-alphabetical characters are unaffected)
to_alternating_case("1a2b3c4d5e"); // => "1A2B3C4D5E"
to_alternating_case("String.prototype.toAlternatingCase"); // => "sTRING.PROTOTYPE.TOaLTERNATINGcASE" */
#include <string.h>
#include <stdlib.h>
char *to_alternating_case(const char *s) {
  char *result = (char *)calloc((strlen(s) + 1), sizeof(char));
  unsigned long len = 0;
  strcpy(result, s);
  while(result[len] != '\0') {
    if(result[len] >= 65 && result[len] <= 90) {
      result[len] += 32;
      len++;
      continue;
    }
    if(result[len] >= 97 && result[len] <= 122) {
      result[len] -= 32;
    }
    len++;
  }
  return result;
}
