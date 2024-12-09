/* A pangram is a sentence that contains every single letter of the alphabet at least once. For example, 
 * the sentence "The quick brown fox jumps over the lazy dog" is a pangram, because it uses the letters 
 * A-Z at least once (case is irrelevant).
Given a string, detect whether or not it is a pangram. Return True if it is, False if not. Ignore numbers and punctuation. */
#include <stdbool.h>
bool is_pangram(const char *str_in) {
  int az[26] = {0};
  bool isPangram = false;
  for(int i = 0; str_in[i] != '\0'; i++) {
        switch (str_in[i]) {
          case 'a':
          case 'A':
              az[0] += 1;
              break;
          case 'b':
          case 'B':
              az[1] += 1;
              break;
          case 'c':
          case 'C':
              az[2] += 1;
              break;
          case 'd':
          case 'D':
              az[3] += 1;
              break;
          case 'e':
          case 'E':
              az[4] += 1;
              break;
          case 'f':
          case 'F':
              az[5] += 1;
              break;
          case 'g':
          case 'G':
              az[6] += 1;
              break;
          case 'h':
          case 'H':
              az[7] += 1;
              break;
          case 'i':
          case 'I':
              az[8] += 1;
              break;
          case 'j':
          case 'J':
              az[9] += 1;
              break;
          case 'k':
          case 'K':
              az[10] += 1;
              break;
          case 'l':
          case 'L':
              az[11] += 1;
              break;
          case 'm':
          case 'M':
              az[12] += 1;
              break;
          case 'n':
          case 'N':
              az[13] += 1;
              break;
          case 'o':
          case 'O':
              az[14] += 1;
              break;
          case 'p':
          case 'P':
              az[15] += 1;
              break;
          case 'q':
          case 'Q':
              az[16] += 1;
              break;
          case 'r':
          case 'R':
              az[17] += 1;
              break;
          case 's':
          case 'S':
              az[18] += 1;
              break;
          case 't':
          case 'T':
              az[19] += 1;
              break;
          case 'u':
          case 'U':
              az[20] += 1;
              break;
          case 'v':
          case 'V':
              az[21] += 1;
              break;
          case 'w':
          case 'W':
              az[22] += 1;
              break;
          case 'x':
          case 'X':
              az[23] += 1;
              break;
          case 'y':
          case 'Y':
              az[24] += 1;
              break;
          case 'z':
          case 'Z':
              az[25] += 1;
              break;
          default:
              break;
        }
  }
  for(int a = 0; a < 26; a++){
    if(az[a] == 0) {
      isPangram = false;
      break;
    }
    else 
      isPangram = true;
  }
  return isPangram;
}
