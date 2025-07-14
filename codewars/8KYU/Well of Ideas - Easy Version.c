/* kata: https://www.codewars.com/kata/57f222ce69e09c3630000212/c */

#include <stddef.h>
#include <string.h>
const char *well(size_t n, const char *ideas[n]) {
  size_t gi = 0;
  
  while(n--) 
    if(strcmp(ideas[n], "good") == 0)
      gi++;
  
  return gi > 0 && gi <= 2 ? "Publish!" :
                   gi  > 2 ? "I smell a series!"   :
                             "Fail!";
}
