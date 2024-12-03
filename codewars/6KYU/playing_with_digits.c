/* Some numbers have funny properties. For example:

89 --> 8¹ + 9² = 89 * 1
695 --> 6² + 9³ + 5⁴= 1390 = 695 * 2
46288 --> 4³ + 6⁴+ 2⁵ + 8⁶ + 8⁷ = 2360688 = 46288 * 51
If it is the case we will return k, if not return -1.

Note: n and p will always be strictly positive integers. */
// link : https://www.codewars.com/kata/5552101f47fc5178b1000050
#include <math.h>
int digPow(int n, int p) {
  int sumpd = 0, div = 1, k = 0;
  while(n / div >= 10){div *= 10;}
  while(div > 0){
    sumpd += pow((n / div) % 10, p);
    div /= 10;
    p++;
  }
  k = sumpd / n;
	return sumpd == n * k ? k : -1;
}
