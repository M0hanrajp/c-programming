/* Implement a function which convert the given boolean value into its string representation.
    do_test(true,  "true");
    do_test(false, "false"); */
#include <stdbool.h>
const char *boolean_to_string(bool b) {
    return b ? "true" : "false";
}
