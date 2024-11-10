#include "leap.h"
#include <stdbool.h>

bool leap_year(int year) {
   if(year % 4 == 0) {
      if(year % 100 == 0) {
         if(year % 400 == 0) {
            return true;
         }
         else
            return false;
      }
      else if(year % 100 != 0) 
         return true;
      else
         false;
   }
   return false;
}
