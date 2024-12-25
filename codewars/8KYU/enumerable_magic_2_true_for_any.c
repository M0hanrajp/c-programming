/* Create an any? (JS: any) function that accepts an array and a block (JS: function), and returns true if the block (/function) returns true for any item in the array. If the array is empty, the function should return false.

Ruby: If you get stuck, you can read up here: */
#include <stdbool.h>
#include <stddef.h>

typedef bool (*Predicate)(int);

bool any(const int* arr, size_t size, Predicate fun) {
  if(size < 1)
    return false;
  bool res = false;
  for(size_t i = 0; i < size; i++) {
    res = fun(arr[i]);
    if(res == true)
      break;
  }
  return res;
}
