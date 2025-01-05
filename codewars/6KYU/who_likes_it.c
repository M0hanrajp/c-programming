/* You probably know the "like" system from Facebook and other pages. People can "like" blog posts, pictures or other items. We want to create the text that should be displayed next to such an item.
Implement the function which takes an array containing the names of people that like an item. It must return the display text as shown in the examples:

[]                                -->  "no one likes this"
["Peter"]                         -->  "Peter likes this"
["Jacob", "Alex"]                 -->  "Jacob and Alex like this"
["Max", "John", "Mark"]           -->  "Max, John and Mark like this"
["Alex", "Jacob", "Mark", "Max"]  -->  "Alex, Jacob and 2 others like this"
return must be an allocated string
do not mutate input
Note: For 4 or more names, the number in "and 2 others" simply increases. */
#include <stdlib.h>
#include <stdio.h>
// result string must be a heap-allocated, nul-terminated string
// to be freed by the tests suite

char *likes(size_t n, const char *const names[n]) {
  char *text = (char *)calloc(60, sizeof(char));
	if(n == 0){sprintf(text, "no one likes this");}
  if(n == 1){sprintf(text, "%s likes this", names[n - 1]);}
  if(n == 2){sprintf(text, "%s and %s like this", names[n - 2], names[n - 1]);}
  if(n == 3){sprintf(text, "%s, %s and %s like this", names[n - 3], names[n - 2], names[n - 1]);}
  if(n >= 4){sprintf(text, "%s, %s and %lu others like this", names[n - n], names[n - n + 1], n - 2);}
  return text;
}
