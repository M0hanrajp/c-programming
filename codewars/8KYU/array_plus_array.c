/* I'm new to coding and now I want to get the sum of two arrays... Actually the sum of all their elements. I'll appreciate for your help.
P.S. Each array includes only integer numbers. Output is a number too. */
#include <stddef.h>

long arr_plus_arr(const int *a,  const int *b, size_t na, size_t nb) {
  static long arr_sum = 0;
  arr_sum = 0;
  if(na == nb) {
    for(size_t i = 0; i < na; i++)
      arr_sum += a[i] + b[i];
  } else {
    for(size_t j = 0; j < na; j++)
      arr_sum += a[j];
    for(size_t k = 0; k < nb; k++)
      arr_sum += b[k];
  }
  return arr_sum;
}
