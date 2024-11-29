#include <stdlib.h>
#include <string.h>

char *are_you_playing_banjo(const char *name) {
  char *result = calloc(30, 1);
  strcpy(result, name);
  if(name[0] == 'r' || name[0] == 'R')
    strcat(result, " plays banjo");
  else
    strcat(result, " does not play banjo");
	return result; // memory will be freed
}
/* If your name starts with the letter "R" or lower case "r", you are playing banjo!

The function takes a name as its only argument, and returns one of the following strings:

name + " plays banjo" 
name + " does not play banjo */
