/* Complete the function that takes two integers (a, b, where a < b) 
 * and return an array of all integers between the input parameters, 
 * including them.
For example:
a = 1
b = 4
[1, 2, 3, 4] */
#include <stddef.h>
void between(int a, int b, int *integers) {
  size_t len = 0;
  size_t terms = b - a + 1;
  while(terms--){integers[len++] = 0;}
  for(size_t i = 0; i <= len; i++) {
    integers[i] = a++;
  }
}
