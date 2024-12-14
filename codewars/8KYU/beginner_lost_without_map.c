#include <stddef.h>
#include <stdlib.h>
int *maps(const int *arr, size_t size) {
  int *darr = (int *)calloc(size, sizeof(*arr));
  while(size--) {*(darr + size) = 2 * *(arr + size);}
  return darr;
}
