/* Jack really likes his number five: the trick here is that you have to 
 * multiply each number by 5 raised to the number of digits of each numbers, so, for example:

  3 -->    15  (  3 * 5¹)
 10 -->   250  ( 10 * 5²)
200 --> 25000  (200 * 5³)
  0 -->     0  (  0 * 5¹)
 -3 -->   -15  ( -3 * 5¹) */
#include <stdlib.h>
int multiply(int number) {
  int dig = abs(number) * 1;
  int fiv = 1;
  while(dig > 0) {
    fiv *= 5;
    dig /= 10;
  }
  return number * fiv;
}
