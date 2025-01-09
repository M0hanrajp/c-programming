/*/omplete the method that takes a boolean value and return a "Yes" string for true, or a "No" string for false. */
#include <stdbool.h>
const char *bool_to_word (bool value) {
  return value == true ? "Yes" : "No";
}
