/* Write a function named sumDigits which takes 
 * a number as input and returns the sum of the 
 * absolute value of each of the number's decimal digits.
For example: (Input --> Output)
10 --> 1
99 --> 18
-32 --> 5 */
#include <stdlib.h>
int sum_digits(int n) {
  int sum = 0;
  n = ( n < 0 ? abs(n) : n);
  while(n > 0){sum += n % 10; n /= 10;}
  return sum;
}
