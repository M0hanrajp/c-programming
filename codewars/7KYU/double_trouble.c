// https://www.codewars.com/kata/57f7796697d62fc93d0001b8/c
#include <stddef.h>

void update_array(int *arr, int sp, int len) {
  for(int i = sp; i < len; i++) {
    if((i + 1) < len) {
      arr[i] = arr[i + 1];
    }
  }
}

void remove_summing_pairs(size_t *length, int x[*length], int t) {
  int fp = 0;
  int sp = fp + 1;
  int len = *length;
  while(fp < len && sp < len) {
    if(t == x[fp] + x[sp]) {
      update_array(x, sp, len);
      len -= 1;
      fp = 0; sp = fp + 1;
      continue;
    }
    fp++; sp++;
  }
  *length = len;
}
