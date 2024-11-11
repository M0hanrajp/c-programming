#include "two_fer.h"
#include <string.h>

void two_fer(char *buffer, const char *name) {
   char temp[100] = "One for ";
   if(name == NULL) {
      strcat(temp, "you");
   } else {
      strcat(temp, name);
   }
   strcat(temp, ", one for me.");
   strcpy(buffer, temp);
}
