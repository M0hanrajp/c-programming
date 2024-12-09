#include "hamming.h"

int compute(const char *lhs, const char *rhs) {
   int diff = 0, index = 0;
   if(strlen(lhs) == strlen(rhs)) {
      while (lhs[index] != '\0' && rhs[index] != '\0') {
         if(lhs[index] != rhs[index])
            diff++;
         index++;
      }
   } else
      diff = -1;
   return diff;
}
