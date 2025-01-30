/* Write a simple regex to validate a username. Allowed characters are:
lowercase letters,
numbers,
underscore
Length should be between 4 and 16 characters (both included). */
#include <stdbool.h>
#include <string.h>
bool validate_username (const char *username) {
  // check the length of string
  if(strlen(username) < 4 || strlen(username) > 16){return false;}
  // check upper case letters & space
  for(int i = 0; username[i] != '\0'; i++)
    if((username[i] >= 'A' && username[i] <= 'Z') || username[i] == ' '){return false;}
	return true;
}
