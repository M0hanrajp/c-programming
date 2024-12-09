#include "isogram.h"
#include <stddef.h>
#include <ctype.h>
bool is_isogram(const char phrase[]) {
   bool isIsogram = true;
   if(phrase == NULL)
      return isIsogram = false;
   for(int i = 0; phrase[i] != '\0'; i++) {
      for(int j = i + 1; phrase[j] != '\0'; j++) {
         if(tolower(phrase[i]) >= 97 && tolower(phrase[i]) <= 122) {
            if(tolower(phrase[i]) == tolower(phrase[j])) {
               isIsogram = false;
               break;
            }
         } else
            continue;
      }
   }
   return isIsogram;
}
