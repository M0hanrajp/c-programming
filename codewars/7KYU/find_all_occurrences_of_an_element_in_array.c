/* Given an array (a list in Python) of integers and an integer n, find 
 * all occurrences of n in the given array and return another array containing 
 * all the index positions of n in the given array.
If n is not in the given array, return an empty array [].
Assume that n and all values in the given array will always be integers.

Example:

find_all(7, {6, 9, 3, 4, 3, 82, 11}, 3, *z)
// returns pointer to {2, 4}
// assigns array length to `*z` */
#include <stdlib.h>
size_t *find_all(size_t a, const int array[a], int number, size_t *z) {
  size_t *index_array = (size_t *)calloc(a, sizeof(size_t)), index = 0;
  for(size_t i = 0; i < a; i++) {
    if(number == array[i])
      index_array[index++] = i;
  }
  *z = index;
  return index_array;
}
