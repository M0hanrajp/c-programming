/* Welcome. In this kata, you are asked to square every digit 
 * of a number and concatenate them.
For example, if we run 9119 through the function, 811181 will 
come out, because 92 is 81 and 12 is 1. (81-1-1-81)
Example #2: An input of 765 will/should return 493625 because 
72 is 49, 62 is 36, and 52 is 25. (49-36-25)
Note: The function accepts an integer and returns an integer.
Happy Coding! */
#include <stdbool.h>
unsigned long long square_digits (unsigned n) {
	unsigned long long square_sum = 0, d = 1, sq = 0;
  bool isSecond = false, isFirst = true;
  // use d to extract diigts from left
  while (n / d > 9) {
    d *= 10;
  }
  while(d > 0) {
    // get the digit
    sq = (n / d) % 10;
    d /= 10;
    // For the first extracted digit
    if(isFirst) {
      square_sum += sq * sq;
      isFirst = false;
      isSecond = true;
      sq = 0;
      continue;
    }
    // For all the digits after first
    if(isSecond) {
      sq *= sq;
      // multiply final value to accumulate squared digit
      sq < 10 ? (square_sum *= 10) : (square_sum *= 100);
      square_sum += sq;
      sq = 0;
    }
  }
  return square_sum;
}
