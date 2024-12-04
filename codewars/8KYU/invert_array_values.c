/* Given a set of numbers, return the additive inverse of each. 
 * Each positive becomes negatives, and the negatives become positives.

[1, 2, 3, 4, 5] --> [-1, -2, -3, -4, -5]
[1, -2, 3, -4, 5] --> [-1, 2, -3, 4, -5]
[] --> [] */
#include <stddef.h>
void invert(int *values, size_t values_size) {
  if(values_size > 0) {
    for(size_t i = 0; i < values_size; i++)
      values[i] = -values[i];
  }
}
