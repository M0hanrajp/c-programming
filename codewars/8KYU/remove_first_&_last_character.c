#include <string.h>

char* remove_char(char* dst, const char* src)
{
  /* src is the input string */
  /* your solution should write the result into dst and return it */
  unsigned long srcIndex = strlen(src);
  for(int index = 1; src[index] != '\0'; index++) {
    dst[index - 1] = src[index];
  }
  dst[srcIndex - 2] = '\0';
  return dst;
}
    // char* strings[] = {"eloquent", "country", "person", "place", "ok"};
    // char* expected[] = {"loquen", "ountr", "erso", "lac", ""};
