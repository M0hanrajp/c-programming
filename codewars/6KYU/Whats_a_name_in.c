// The function should return true if that is the case, and else false. Letter comparison should be case-INsensitive.
/*     "Across the rivers", "chris" --> true
      ^      ^  ^^   ^
      c      h  ri   s
    Contains all of the letters in "chris", in order.
----------------------------------------------------------
    "Next to a lake", "chris" --> false
    Contains none of the letters in "chris".
--------------------------------------------------------------------
    "Under a sea", "chris" --> false
         ^   ^
         r   s
    Contains only some of the letters in "chris".
--------------------------------------------------------------------
    "A crew that boards the ship", "chris" --> false
       cr    h              s i
       cr                h  s i  
       c     h      r       s i
    Contains all of the letters in "chris", but not in order.
--------------------------------------------------------------------
    "A live son", "Allison" --> false
     ^ ^^   ^^^
     A li   son
    Contains all of the correct letters in "Allison", in order, but not enough of all of them (missing an 'l'). */
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
bool is_subsequence (const char *haystack, const char *needle) {
  bool res = true;
  unsigned long skip = 0;
  if(strlen(haystack) < strlen(needle)) 
    res = false;
  for(int i = 0; needle[i] != '\0'; i++) {
    if(res && skip < strlen(haystack)) {
      for(int j = skip; haystack[j] != '\0'; j++) {
        if(tolower(needle[i]) == tolower(haystack[j])) {
          res = true;
          skip = j + 1;
          break;
        }
        else
          res = false;
        skip = j;
      }
    }
    else
      break;
  }
  return res;
}
