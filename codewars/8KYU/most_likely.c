/* Create a function which compares two probabilities, returning true if the first one is most likely otherwise false.
For this exercise probability is expressed as two numbers separated by a colon e.g. a probability of 1 in 3 will be 1:3.
So:

Input: ('1:3','1:2') - returns false as 1 in 3 is less likely than 1 in 2. */
#include <stdbool.h>
bool most_likely(const char *a, const char *b) {
  float pa = (a[0] - 48) / ((a[2] - 48) * 1.0);
  float pb = (b[0] - 48) / ((b[2] - 48) * 1.0);
  return pa > pb;
}
