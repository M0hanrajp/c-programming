/* You get an array of numbers, return the sum of all of the positives ones.
Example
[1, -4, 7, 12] => 1 + 7 + 12 = 20
Note
If there is nothing to sum, the sum is default to 0. */
#include <stddef.h>
int positive_sum(const int *values, size_t count) {
  int sum = 0;
  for(size_t i = 0; i < count; i++)
    sum += values[i] > 0 ? values[i] : 0;
  return sum;
}
