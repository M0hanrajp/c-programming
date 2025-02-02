/* Write a function that checks whether all elements in an array are square 
 * numbers. The function should be able to take any number of array elements.
Your function should return true if all elements in the array are square numbers
and false if not.
An empty array should return undefined / None / nil /false (for C). You can assume
that all array elements will be positive integers.

Examples:
is_square({1, 4, 9, 16}) --> true
is_square({3, 4, 7, 9}) --> false
is_square({}) --> false */
#include <stdbool.h>
#include <stddef.h>
#include <math.h>
bool is_square (const unsigned arr[], size_t size) {
  if(size == 0){return false;}
  for(size_t i = 0; i < size; i++)
    if(arr[i] != ((const unsigned int)sqrt(arr[i]) * (const unsigned int)sqrt(arr[i]))){return false;}
  return true;
}
