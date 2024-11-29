#include <stdbool.h>
#include <string.h>

bool validate_pin(const char *pin) {
  unsigned long pinLen = strlen(pin);
  bool isValid = false;
  if(pinLen == 4 || pinLen == 6) {
     for(int i = 0; pin[i] != '\0'; i++) {
      if(pin[i] >= 48 && pin[i] <= 57)
        isValid = true;
      else
        isValid = false;
      if(!isValid)
        return false;
     }   
  }
  return isValid;
}
/* ATM machines allow 4 or 6 digit PIN codes and PIN codes cannot contain anything but exactly 4 digits or exactly 6 digits.

If the function is passed a valid PIN string, return true, else return false.

Examples (Input --> Output)
"1234"   -->  true
"12345"  -->  false
"a234"   -->  false */
