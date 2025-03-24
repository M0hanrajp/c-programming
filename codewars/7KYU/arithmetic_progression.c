/* In your class, you have started lessons about arithmetic progression. Since 
 * you are also a programmer, you have decided to write a function that will return 
 * the first n elements of the sequence with the given common difference d and first 
 * element a. Note that the difference may be zero!
The result should be a string of numbers, separated by comma and space.

Example
# first element: 1, difference: 2, how many: 5
arithmetic_sequence_elements(1, 2, 5) == "1, 3, 5, 7, 9"
Note: The returned string will be free'd if non-NULL. */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
char *arithmetic_sequence_elements(int a, int d, size_t n) {
  unsigned index = 0;
  char *ap = (char *)calloc(500, sizeof(char));char temp[10];
  if(n == 0){return ap;}
  index += sprintf(temp, "%d, ", a);
  strcpy(ap, temp);memset(temp, 0, sizeof(temp));
  for(size_t i = 1; i < n; i++) {
    a += d;
    index += sprintf(temp, "%d, ", a);
    strcat(ap, temp);memset(temp, 0, sizeof(temp));
  }
  ap[index - 2] = '\0';
  return ap;
}
