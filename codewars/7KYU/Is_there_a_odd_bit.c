/* Return 1 when any odd bit of x equals 1; 0 otherwise.

Assume that:

x is an unsigned, 32-bit integer;
the bits are zero-indexed (the least significant bit is position 0)
Examples
  2  -->  1 (true) because at least one odd bit is 1 (2 = 0b10)
  5  -->  0 (false) because none of the odd bits are 1 (5 = 0b101)
170  -->  1 (true) because all of the odd bits are 1 (170 = 0b10101010) */
#include <stdbool.h>
#include <inttypes.h>
bool any_odd(uint32_t x) {
  bool result = false;
  for(int i = 31; i >= 0; i--) {
    if((i % 2 != 0) && ((x & (1u << i)) != 0))
      result = true;
  }
    return result;
}
