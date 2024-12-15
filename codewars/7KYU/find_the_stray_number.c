/* You are given an odd-length array of integers, in which all of them are the same, except for one single number.

Complete the method which accepts such an array, and returns that single different number.

The input array will always be valid! (odd-length >= 3)

Examples
[1, 1, 2] ==> 2
[17, 17, 3, 17, 17, 17, 17] ==> 3 */
#include <stddef.h>

int stray(size_t n, int arr[n]) {
  int ca = 0, cb = 0, a = 0, b = 0, res = 0;
  a = arr[0];
  ca++;
  for(size_t i = 1; i < n; i++) {
    if(a == arr[i]) {
      ca++;
    } else {
      b = arr[i];
      cb++;
    }
    if(ca == 1 && cb >= 2)
      res = a;
    if(ca >= 2 && cb == 1)
      res = b;
  }
  return res;
}
