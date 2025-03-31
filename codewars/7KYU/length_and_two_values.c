/* Given an integer n and two other values, build an array of size n filled with these two values alternating.
Examples
5, true, false     -->  [true, false, true, false, true]
10, "blue", "red"  -->  ["blue", "red", "blue", "red", "blue", "red", "blue", "red", "blue", "red"]
0, "one", "two"    -->  []
Good luck! */
#include <stddef.h>
#include <string.h>
// alternately assign values to the preallocated *array
void alternate(size_t length, int first_value, int second_value, int *array) {
  for(size_t i = 0; i < length; i++)
    array[i] = (i % 2 == 0) ? first_value : second_value;
}
