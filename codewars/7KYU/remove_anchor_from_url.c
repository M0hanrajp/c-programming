/* Complete the function/method so that it returns the url 
 * with anything after the anchor (#) removed.
Examples
"www.codewars.com#about" --> "www.codewars.com"
"www.codewars.com?page=1" -->"www.codewars.com?page=1" */
#include <stdlib.h>
#include <string.h>
char *remove_url_anchor(const char *url_in) {
  char *url_out = (char *)calloc((strlen(url_in) + 1), sizeof(char));
  unsigned len_out = 0;
  for(int i = 0; url_in[i] != '\0'; i++) {
    if(url_in[i] == '#')
      break;
    url_out[len_out++] = url_in[i];
  }
  url_out[len_out] = '\0';
  return url_out;
}
