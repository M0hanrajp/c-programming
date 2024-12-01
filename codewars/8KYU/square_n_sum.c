/* Complete the square sum function so that it squares each number passed into it and then sums the results together.

For example, for [1, 2, 2] it should return 9 */
#include <stddef.h>
#include <math.h>
int square_sum(const int values[/* count */], size_t count) {
  int result = 0;
  for(size_t i = 0; i < count; i++) {
    result = result + pow(values[i], 2);
  }
	return result;
}
