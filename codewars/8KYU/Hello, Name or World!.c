/* Define a method hello that returns "Hello, Name!" to a given name, or 
 * says Hello, World! if name is not given (or passed as an empty String).

Assuming that name is a String and it checks for user typos to return a 
name with a first capital letter (Xxxx).

Examples:

* With `name` = "john"  => return "Hello, John!"
* With `name` = "aliCE" => return "Hello, Alice!"
* With `name` not given 
  or `name` = ""        => return "Hello, World!" */
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// allocate memory for and then return a NULL-terminated C-string
char *hello(const char *name) {
  char *hi = (char *)calloc(50, sizeof(char ));
  strcpy(hi, "Hello, ");
  unsigned index = 7;
  if(strcmp(name, "") == 0) {
    strcat(hi, "World!");
  } else {
    hi[index++] = toupper(name[0]);
    for(unsigned i = 1; name[i] != '\0'; i++)
      hi[index++] = tolower(name[i]);
    hi[index++] = '!';
  }
  return hi;
}
