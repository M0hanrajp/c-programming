/* Challenge:
Most of us used to need to make a quick copy of text from Wikipedia, but those reference marks, e.g. [1], sprinkled all over can get quite annoying!
Now you, code warrior, are about to make a difference!

Given a string, remove in-place all reference marks (which have the format [n], where n - is an integer) and return it.

It's important to note, however, that these marks do not nest - thus you should not worry about the cases with nested marks, e.g. [[1]].
Reference marks do stack, though, e.g. [1][2][3].

It is also guaranteed that there will be no marks with non-digits between the brackets.

Example:
Given a source string: "Caesar is considered by many historians to be one of the greatest military commanders in history.[4]", your function should return: "Caesar is considered by many historians to be one of the greatest military commanders in history."

Addendum:
Please keep in mind, that these marks can theoretically appear anywhere within the source string.
Remove the marks only. No whitespace stripping or any other form of the source string mutation is required. */
#include <string.h>
#include <stdlib.h>
char* filterRefsOut(char *source) {
  unsigned length = strlen(source), index = 0;
  char *f = (char *)calloc(length + 1, sizeof(char));
  strcpy(f, source);memset(source, 0, length);
  
  for(int i = 0; f[i] != '\0'; i++) {
    if(f[i] == '[') { while(f[i] != ']') {i++;} if(f[i] == ']'){continue;}}
    source[index++] = f[i];
  }
  free(f);
  return source;
}
