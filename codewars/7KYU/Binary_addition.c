/* Implement a function that adds two numbers together and returns their sum in binary. 
 * The conversion can be done before, or after the addition.
The binary number returned should be a string.
Examples:(Input1, Input2 --> Output (explanation)))
1, 1 --> "10" (1 + 1 = 2 in decimal or 10 in binary)
5, 9 --> "1110" (5 + 9 = 14 in decimal or 1110 in binary) */
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
char *binary_add (unsigned a, unsigned b, char *binary) {
  uint64_t aa = a;
  uint64_t bb = b;
  uint64_t res = aa + bb, index = 0;
  bool msbflag = false;
  char bin[64];
  // get msb
  for(uint64_t i = 64; i > 0; i--) {
    msbflag = (res & ((uint64_t )1 << (i - 1))) != 0 ? true : false;
    if(msbflag) {
      index = i;
      break;
    }
  }
  if(index == 0) {
    binary[index] = '0';
    binary[index + 1] = '\0';
    return binary;
  }
  // from msb index copy to bin
  for(uint64_t j = index; j > 0; j--) {
    bin[index - j] = ((res & ((uint64_t )1 << (j - 1))) != 0 ? '1' : '0');
  }
  bin[index] = '\0';
  strcpy(binary, bin);
	return binary;
}
