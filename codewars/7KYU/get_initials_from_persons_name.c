/* Write function toInitials returs initials for a given person name. E.g: "Bill Gates" -> "B. G."
Note: initials should be separated with a space. */
#include <stdlib.h>
#include <string.h>
char *toInitials(const char *name) {
  char *initial = (char *)calloc(10, sizeof(char));
  initial[0] = name[0];
  strcat(initial, ". ");
  size_t index = 3;
  for(size_t i = 2; name[i] != '\0'; i++) {
    if(name[i] >= 'A' && name[i] <= 'Z') {
      initial[index] = name[i];
      strcat(initial, ". ");
      index += 3;
    }
  }
  initial[index - 1] = '\0';
  return initial; // returned pointer will be freed
}
