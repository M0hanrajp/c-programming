/* Make a program that filters a list of strings and returns a list with only 
 * your friends name in it.
If a name has exactly 4 letters in it, you can be sure that it has to be a 
friend of yours! Otherwise, you can be sure he's not...

Input = ["Ryan", "Kieran", "Jason", "Yous"]
Output = ["Ryan", "Yous"]

Input = ["Peter", "Stephen", "Joe"]
Output = []
Input strings will only contain letters.
Note: keep the original order of the names in the output. */
#include <string.h>
void filter_friends (const char *names[]) {
  const char *friends[100];
  unsigned len = 0, index = 0;
  for(int i = 0; names[i] != '\0'; i++) {
    if(strlen(names[i]) == 4)
      friends[len++] = names[i];
  }
  friends[len] = NULL;
  for(int i = 0; friends[i] != '\0'; i++)
    names[index++] = friends[i];
  names[index] = NULL;
}
