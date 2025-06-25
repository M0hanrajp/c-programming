#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
size_t substrings_count (const char *full_text, const char *search_text) {
  if(full_text == NULL)
    return 0;
  if(strlen(search_text) > strlen(full_text))
    return 0;
  
  unsigned long idx = 0;
  int instance = 0;
  int old_i = 0;
  for(int i = 0; full_text[i] != '\0'; i++) {
    if(full_text[i] == search_text[idx]) {
      idx++;
      if(idx == strlen(search_text)) {
        instance++;
        idx = 0;
      }
    } else {
      idx = 0;
    }
  }
	return instance;
}

int main(void) {
    //const char *s = "_oaoaoaoaoaoa_@oaoaoaoaoao#o@oao";
    const char *t = "xxax#x_xxxaxxxa@xxax#x@_x@axxxax@xaxxx#@#x#xxxaxx";
    printf("Instance count = %zu\n", substrings_count(t, "xxax"));
    return 0;
}
