/*
 * Given an array of integers your solution should find the smallest integer.

For example:

Given [34, 15, 88, 2] your solution will return 2
Given [34, -345, -1, 100] your solution will return -345
*/
#include <stddef.h>

int find_smallest_int(const int array[/* len */], size_t len) {
  int smallest_int = 0;
  smallest_int = array[0];
  for(unsigned long i = 1; i < len; i++) {
    if(smallest_int > array[i])
      smallest_int = array[i];
  }
  return smallest_int;
}
