/* Given an array of integers of any length, return an array that has 1 added to the value represented by the array.

If the array is invalid (empty, or contains negative integers or integers with more than 1 digit), return nil (or your language's equivalent).

Examples
Valid arrays

[4, 3, 2, 5] would return [4, 3, 2, 6] (4325 + 1 = 4326)
[1, 2, 3, 9] would return [1, 2, 4, 0] (1239 + 1 = 1240)
[9, 9, 9, 9] would return [1, 0, 0, 0, 0] (9999 + 1 = 10000)
[0, 1, 3, 7] would return [0, 1, 3, 8] (0137 + 1 = 0138)
Invalid arrays

[] is invalid because it is empty
[1, -9] is invalid because -9 is not a non-negative integer
[1, 2, 33] is invalid because 33 is not a single-digit integer */
#include <stdlib.h>
#include <stdint.h>
// Returned array must be freeable.
//
// *count is an in/out parameter. It contains the size of arr on input,
// and should be set to the lenght of returned array upon return.
//
// When input is invalid, the function should return NULL and set *count to 0.

int *up_array(const int *arr, unsigned *count) {
  // perform necessary checks
  if(*count == 0){return NULL;}
  for(uint64_t i = 0; i < *count; i++)
    if(arr[i] < 0 || arr[i] > 9){*count = 0; return NULL;}
  // main
  unsigned len = 0;
  long int size = *count * 1, rem = 0; 
  int *plusone = (int *)calloc(200, sizeof(int));
  for(long int i = size - 1; i > - 1; i--) {
    if(i == size - 1){plusone[i] = arr[i] + 1;}
    else{plusone[i] = arr[i] + rem;}
    if(plusone[i] > 9){plusone[i] = 0; rem = 1;}else{rem = 0;}
    if(i == 0 && rem == 1){len += 1;plusone[i] = rem;}
    len++;
  }
  *count = len;
  return plusone;
}
