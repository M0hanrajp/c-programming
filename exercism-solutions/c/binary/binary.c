#include "binary.h"
#include <math.h>
#include <string.h>


int convert(const char *input) {
   int decimal = 0;
   int msbPosition = strlen(input);
   long unsigned int strIndex = 0;
   if(stringValid(input)) {
      if(msbPosition >= 1) {
         while (strIndex < strlen(input)) {
            if(input[strIndex] == 49) {
               decimal += 1 * pow(2, (msbPosition - 1));
               strIndex++;
               msbPosition--;
               continue;
            }
            if(input[strIndex] == 48) {
               strIndex++;
               msbPosition--;
            }
         }
      }
      if(msbPosition == 1) {
         if(input[strIndex] == 49)
            decimal += 1 * pow(2, (msbPosition));
         if(input[strIndex] == 48)
            decimal += 0 * pow(2, (msbPosition));
      }
      return decimal;
   }
   return -1;
}

bool stringValid(const char *dupInput) {
   bool result = true;
   for(int strIndex = 0; dupInput[strIndex] != '\0'; strIndex++) {
      if(dupInput[strIndex] != 48 && dupInput[strIndex] != 49) {
         result = false;
         break;
      }
   }
   return result;
}

