/* Write a function that returns a string in which firstname is swapped with last name.
Example(Input --> Output)
"john McClane" --> "McClane john" */
#include <string.h>
#include <stdbool.h>
char *name_shuffler (char *shuffled, const char *name) {
	bool isSpace = false;
  unsigned long len = 0;
  // Copy the last name
  for(int i = 0; name[i] != '\0'; i++) {
    if(name[i] == ' ') {
      isSpace = true;
      continue;
    }
    if(isSpace)
      shuffled[len++] = name[i];
  }
  // add space after last name
  shuffled[len++] = ' ';
  // copy first name
  for(int i = 0; name[i] != ' '; i++) {
    shuffled[len++] = name[i];
  }
  shuffled[strlen(name)] = '\0';
	return shuffled;
}
