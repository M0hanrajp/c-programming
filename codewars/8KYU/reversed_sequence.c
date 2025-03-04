/* Build a function that returns an array of integers from n to 1 where n>0.

Example : n=5 --> [5,4,3,2,1] */
#include <stdlib.h>
unsigned short *reverse_seq(unsigned short num) {
  unsigned short *rs = (unsigned short *)calloc(num, sizeof(unsigned short));
  unsigned index = 0;while(num != 0){rs[index++] = num; num--;}
  return rs;
}
