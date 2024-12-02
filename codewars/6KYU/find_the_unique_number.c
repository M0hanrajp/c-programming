#include <stddef.h>
float finduniq(const float *nums, size_t n) {
  float resa = 0, resb = 0, fres = 0;
  int counta = 0, countb = 0;
  resa = nums[0];
  counta++;
  for(size_t i = 1; i < n; i++) {
      if(resa == nums[i])
          counta++;
      else {
          resb = nums[i];
          countb++;
      }
      if(counta == 1 && countb >= 2) {
          fres = resa;
          break;
      }
      if(countb == 1 && counta >= 2) {
          fres = resb;
          break;
      }
  }
  return fres;
}
/* finduniq((const float[]){1, 1, 1, 2, 1, 1}, 5); /* --> 2 */
