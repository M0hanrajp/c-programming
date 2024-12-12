/* You will be given an array and a limit value. You must check that all 
 * values in the array are below or equal to the limit value. If they are,
 * return true. Else, return false.
You can assume all values in the array are numbers. */
#include <stdbool.h>
#include <stddef.h>

bool small_enough(int *arr, size_t length, int limit)
{
  bool result = true;
  for (size_t i = 0; i < length; i++) {
    if (arr[i] > limit) result = false;
  }
  return result;
}

