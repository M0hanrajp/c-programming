// convert binary string to decimal
#include <string.h>
#include <math.h>
unsigned bin_to_decimal(const char *bin) {
  unsigned index = strlen(bin);
  static unsigned decimal = 0;
  decimal = 0;
  for(unsigned i = 0; bin[i] != '\0'; i++) {
    if(bin[i] == '1') {
      decimal += pow(2, index - 1);
    }
    index--;
  }
	return decimal;
}
