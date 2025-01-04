/* Count how often sign changes in array.
result
number from 0 to ... . Empty array returns 0

example
const arr = [1, -3, -4, 0, 5];

| elem | count |
|------|-------|
|  1   |  0    |
| -3   |  1    |
| -4   |  1    |
|  0   |  2    |
|  5   |  2    |
catchSignChange(arr) == 2; */
#include <stddef.h>
#include <stdbool.h>
size_t catch_sign_change(const int *array, size_t length) {
  size_t count = 0;
  bool isNegative = false, isPositive = false;
  while(length--) {
    if(array[length] < 0) {
      isNegative = true;
    } else {
      isPositive = true;
    }
    if(isNegative && array[length] >= 0) {
      count++;
      isNegative = false;
    }
    if(isPositive && array[length] < 0) {
      count++;
      isPositive = false;
    }   
  }
  return count;
}
