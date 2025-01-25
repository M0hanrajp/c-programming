/* Write an algorithm that takes an array and moves all of the zeros to the end, preserving the order of the other elements.
move_zeros(10, int [] {1, 2, 0, 1, 0, 1, 0, 3, 0, 1}); // -> int [] {1, 2, 1, 1, 3, 1, 0, 0, 0, 0} */
#include <stddef.h>
#include <stdbool.h>
void move_zeros(size_t len, int arr[len]) {
  int aarr[1000] = {0}, x = 0;
  bool ischanged = false;
  for(size_t i = 0; i < len; i++) {
    if(arr[i] != 0) {
      aarr[x] = arr[i];
      ischanged = true;
      x++;
    }
  }
  if(ischanged) {
    for(size_t i = 0; i < len; i++) {
      arr[i] = aarr[i];
    }
  }
}
