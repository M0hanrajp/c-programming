/* Write a function that can return the smallest value of an array or the 
 * index of that value. The function's 2nd parameter will tell whether it 
 * should return the value or the index.
Assume the first parameter will always be an array filled with at least 1 
number and no duplicates. Assume the second parameter will be a string holding 
one of two values: 'value' and 'index'.

Some examples:

([1,2,3,4,5], "value") should return 1
([1,2,3,4,5], "index") should return 0 */
#include <stddef.h>
#include <string.h>
int find_smallest(const int numbers[/*length*/], size_t length, const char *mode) {
  int value = 0, index = 0;
  value = numbers[0];
  index = 0;
  for(size_t i = 1; i < length; i++) {
    if(value > numbers[i]) {
      value = numbers[i];
      index = i;
    }
  }
  return strcmp(mode, "value") == 0 ? value : index; // add solution here
}
