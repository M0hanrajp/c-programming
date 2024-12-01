/* reate a function that takes an integer as an argument and returns "Even" for even numbers or "Odd" for odd numbers.
 */
#include <stdlib.h>
const char* even_or_odd(int number) {
  return !(abs(number) % 2) ? "Even" : "Odd";
}
