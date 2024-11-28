#include "pangram.h"
#define APLHABETS 26
bool is_pangram(const char *sentence) {
   int count[APLHABETS] = {0};
   if(sentence != (void *)'\0') {
      for(int index = 0; sentence[index] != '\0'; index++) {
         switch (sentence[index]) {
            case 'a':
            case 'A':
               count[0]++;
               break;
            case 'b':
            case 'B':
               count[1]++;
               break;
            case 'c':
            case 'C':
               count[2]++;
               break;
            case 'd':
            case 'D':
               count[3]++;
               break;
            case 'e':
            case 'E':
               count[4]++;
               break;
            case 'f':
            case 'F':
               count[5]++;
               break;
            case 'g':
            case 'G':
               count[6]++;
               break;
            case 'h':
            case 'H':
               count[7]++;
               break;
            case 'i':
            case 'I':
               count[8]++;
               break;
            case 'j':
            case 'J':
               count[9]++;
               break;
            case 'k':
            case 'K':
               count[10]++;
               break;
            case 'l':
            case 'L':
               count[11]++;
               break;
            case 'm':
            case 'M':
               count[12]++;
               break;
            case 'n':
            case 'N':
               count[13]++;
               break;
            case 'o':
            case 'O':
               count[14]++;
               break;
            case 'p':
            case 'P':
               count[15]++;
               break;
            case 'q':
            case 'Q':
               count[16]++;
               break;
            case 'r':
            case 'R':
               count[17]++;
               break;
            case 's':
            case 'S':
               count[18]++;
               break;
            case 't':
            case 'T':
               count[19]++;
               break;
            case 'u':
            case 'U':
               count[20]++;
               break;
            case 'v':
            case 'V':
               count[21]++;
               break;
            case 'w':
            case 'W':
               count[22]++;
               break;
            case 'x':
            case 'X':
               count[23]++;
               break;
            case 'y':
            case 'Y':
               count[24]++;
               break;
            case 'z':
            case 'Z':
               count[25]++;
               break;
            // Numbers
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
               continue;
            // Special characters
            case ' ':
            case '_':
            case '"':
            case '.':
               continue;
            default:
               return false;
         }
      }
   // check if each alphabet has atleast been used once
   // return false if not used
   // return true if used
   for(int index = 0; index < 26; index++) {
      if(count[index] == 0) {
         return false;
      }
   }
   return true;
   }
   // return false if sentence is null
   return false;
}
