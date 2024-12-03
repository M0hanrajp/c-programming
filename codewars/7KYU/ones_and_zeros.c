/* Given an array of ones and zeroes, convert the equivalent binary value to an integer.

Eg: [0, 0, 0, 1] is treated as 0001 which is the binary representation of 1.

Examples:

Testing: [0, 0, 0, 1] ==> 1
Testing: [0, 0, 1, 0] ==> 2
Testing: [0, 1, 0, 1] ==> 5
Testing: [1, 0, 0, 1] ==> 9
Testing: [0, 0, 1, 0] ==> 2
Testing: [0, 1, 1, 0] ==> 6
Testing: [1, 1, 1, 1] ==> 15
Testing: [1, 0, 1, 1] ==> 11 */
#include <stddef.h>
#include <math.h>
unsigned binary_array_to_numbers(const unsigned bits[/*count*/], size_t count) {
	unsigned long result = 0, p = count - 1;
  for(unsigned long i = 0; i < count; i++) {
    result = result + ( bits[i] * pow(2, p));
    p--;
  }
  return result;
}
