#include "reverse_string.h"
#include <stdlib.h>

char *reverse(const char *value) {
   unsigned long end = strlen(value), start = 0;
   char *output = (char *)calloc(end + 1, sizeof(char));
   char *copy = (char *)calloc(end + 1, sizeof(char));
   strcpy(copy, value);
   while (end--) {output[start++] = copy[end];}
   output[start] = '\0';
   free(copy);
   return output;
}
