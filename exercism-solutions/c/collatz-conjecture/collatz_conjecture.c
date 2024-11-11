#include "collatz_conjecture.h"

// return the count of steps
int steps(int start) {
   int count = -1;
   if(start > 0) {
      count = 0;
      while(start != 1) {
         if(start % 2 == 0) {
            start = start / 2;
            count++;
         } else {
            start = (3 * start) + 1;
            count++;
         }
      }
   }
   return count;
}
