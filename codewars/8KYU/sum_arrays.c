/* Write a function that takes an array of numbers and returns the sum of the numbers. 
 * The numbers can be negative or non-integer. If the array does not contain any numbers 
 * then you should return 0.

Examples
Input: [1, 5.2, 4, 0, -1]
Output: 9.2
*/
#include <stddef.h>

int sum_array(const int *values, size_t count) {
  double sum = 0;
  for(unsigned long index = 0; index < count; index++) {
    sum += values[index];
  }
  return sum;
}
