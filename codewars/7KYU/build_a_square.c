/* I will give you an integer. Give me back a shape that is as long and wide 
 * as the integer. The integer will be a whole number between 1 and 50.
Example
n = 3, so I expect a 3x3 square back just like below as a string:
+++
+++
+++ */
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
char* generate_shape(size_t n) {
  char* shape = (char *)calloc((n * n) + (n -1), sizeof(char));
  unsigned index = 0;
  for(unsigned i = 0; i < n; i++) {
    for(unsigned j = 0; j < n; j++) {
      shape[index++] = '+';
    }
    if(i < n - 1){strcat(shape, "\n"); index++;}
  }
  return shape;
}
