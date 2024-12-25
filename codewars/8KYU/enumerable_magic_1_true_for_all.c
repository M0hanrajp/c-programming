/* Create a method all which takes two params:
a sequence
a function (function pointer in C)
and returns true if the function in the params returns true for 
every element in the sequence. Otherwise, it should return false. 
If the sequence is empty, it should return true, since technically 
nothing failed the test.

Example
all((1, 2, 3, 4, 5), greater_than_9) -> false
all((1, 2, 3, 4, 5), less_than_9)    -> True */
#include <stdbool.h>
#include <stddef.h>

typedef bool (*Predicate)(int);

bool all(int* arr, size_t size, Predicate fun) {
  bool res = true;
  for(size_t i = 0; i < size; i++) {
    res = fun(arr[i]);
  }
  return res;
}
