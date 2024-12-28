/* Create a function that gives a personalized greeting. This function takes two parameters: name and owner.
Use conditionals to return the proper message:

case	return
name equals owner	'Hello boss'
otherwise	'Hello guest' */
#include <string.h>

const char* greet(const char *name, const char *owner)
{
  return strcmp(name, owner) ? "Hello guest" : "Hello boss";
}
