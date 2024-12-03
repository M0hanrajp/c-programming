/* Given a list of integers, determine whether the sum of its elements is odd or even.

Give your answer as a string matching "odd" or "even".

If the input array is empty consider it as: [0] (array with a zero).

Examples:
Input: [0]
Output: "even"

Input: [0, 1, 4]
Output: "odd" */
#include <stddef.h>
#include <stdlib.h>
const char *odd_or_even(const int *v, size_t sz) {
  int sumV = 0;
  while(sz--){sumV += v[sz];}
  return abs(sumV) % 2 ? "odd" : "even";
}
