#include "armstrong_numbers.h"
#include <math.h>
#include <stdbool.h>

bool is_armstrong_number(int candidate) {
   if(candidate >= 0 && candidate < 10) {
      if(candidate == pow(candidate, 1)) {
            return true;
      }
   }
   if(candidate >= 10 && candidate <= 99) {
      int checkArmstrong = 0, n = 0;
      n = candidate / 10;
      checkArmstrong = pow(n, 2) + pow(((candidate - (n * 10)) / 1.0), 2);
      if(checkArmstrong == candidate)
         return true;
   }
   if(candidate >= 100 && candidate <= 999) {
      int checkArmstrong = 0, nOne = 0, nTwo = 0, nThree = 0;
      nOne = candidate / 100;
      nTwo = candidate - (nOne * 100);
      nThree = (nTwo - ((nTwo / 10) * 10));
      checkArmstrong = pow(nOne, 3) + pow((int)(nTwo / 10), 3) + pow(nThree, 3);
      if(checkArmstrong == candidate)
         return true;
   }
   if(candidate >= 1000 && candidate <= 9999) {
      int checkArmstrong = 0, nOne = 0, nTwo = 0, nThree = 0, nfour = 0;
      nOne = candidate / 1000;
      nTwo = candidate - (nOne * 1000);
      nThree = nTwo - ((int)(nTwo/100) * 100);
      nfour = (nThree - ((nThree/10) * 10));
      checkArmstrong = pow(nOne, 4) + pow((int)(nTwo / 100), 4) + pow((int)(nThree/10), 4) + pow(nfour, 4);
      if(checkArmstrong == candidate)
         return true;
   }
   if(candidate >= 1000000 && candidate <= 9999999) {
      int checkArmstrong = 0, nOne = 0, nTwo = 0, nThree = 0, nfour = 0, nfive = 0, nSix = 0, nSeven = 0;
      nOne = candidate / 1000000;
      nTwo = candidate - (nOne * 1000000);
      nThree = nTwo - ((int)(nTwo/100000) * 100000);
      nfour = (nThree - ((nThree/10000) * 10000));
      nfive = (nfour - (nfour/1000) * 1000);
      nSix = (nfive - (nfive/100) * 100);
      nSeven = (nSix - (nSix/10) * 10);
      checkArmstrong = pow(nOne, 7) + pow((int)(nTwo / 100000), 7) + pow((int)(nThree/10000), 7) + pow((int)(nfour/1000), 7) + pow((int)(nfive/100), 7) + pow((int)(nSix/10), 7) + pow(nSeven, 7);
      if(checkArmstrong == candidate)
         return true;
   }
   return false;
}
